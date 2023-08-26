-- @EXPECTED_RESULTS@: CORRECT
import Control.Monad
import Data.Array.IArray
import Data.Array.IO

updateArray :: (MArray a e m, Ix i) => a i e -> i -> (e -> e) -> m ()
updateArray arr idx f = readArray arr idx >>= writeArray arr idx . f

(>>&&) :: Monad m => m Bool -> m Bool -> m Bool
a >>&& b = do v <- a; if v then b else return False

(>>||) :: Monad m => m Bool -> m Bool -> m Bool
a >>|| b = do v <- a; if v then return True else b

anyM :: Monad m => (a -> m Bool) -> [a] -> m Bool
anyM f xs = foldl (>>||) (return False) (map f xs)

allM :: Monad m => (a -> m Bool) -> [a] -> m Bool
allM f xs = foldl (>>&&) (return True) (map f xs)

canWin :: Int -> Array (Int,Int) Char -> Int -> IO Bool
canWin n grid p = do
    scores <- thaw initScores :: IO (IOArray Int Int)
    values <- thaw initValues :: IO (IOArray (Int,Int) Int)

    let push :: Int -> IO Bool
        push i = do
            visited <- newArray (1,n) False :: IO (IOArray Int Bool)

            let dfs :: Int -> IO Bool
                dfs i = do writeArray visited i True
                           score <- readArray scores i
                           if score < maxScore then do updateArray scores i (+1)
                                                       return True
                                               else anyM (traverse i) [1..n]

                traverse :: Int -> Int -> IO Bool
                traverse i j = return (grid!(i,j) == '.') >>&&
                               liftM (>0) (readArray values (i,j)) >>&&
                               liftM not (readArray visited j) >>&&
                               dfs j >>&&
                               do updateArray values (i,j) (subtract 1)
                                  updateArray values (j,i) (+1)
                                  return True

                in dfs i >>&&
                   do updateArray scores i (subtract 1)
                      return True

        in allM push $ [1..n] >>= (\i -> replicate (initScores!i - maxScore) i)

    where
        maxScore = initScores!p

        initScores :: Array Int Int
        initScores = listArray (1,n) [ sum [ initValues!(i,j) | j <- [1..n] ]
                                     | i <- [1..n] ]

        initValues :: Array (Int,Int) Int
        initValues = listArray ((1,1),(n,n)) (map initValue (assocs grid))

        initValue :: ((Int, Int), Char) -> Int
        initValue (_,     '1') = 2  -- fixed win
        initValue (_,     'd') = 1  -- fixed draw
        initValue (_,     '0') = 0  -- fixed loss
        initValue (_,     'x') = 0  -- no result
        initValue ((i,j), '.') | i == p    = 2  -- assumed won by p
                               | j == p    = 0  -- assumed lost to p
                               | otherwise = 1  -- assumed drawn

doCase = do
    n <- readLn
    grid <- liftM (listArray ((1,1),(n,n)) . concat) (replicateM n getLine)
    winners <- filterM (canWin n grid) [1..n]
    putStrLn $ unwords $ map show winners

main = readLn >>= (`replicateM_` doCase)
