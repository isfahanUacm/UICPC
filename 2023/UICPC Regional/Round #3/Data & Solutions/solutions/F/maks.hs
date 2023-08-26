-- @EXPECTED_RESULTS@: CORRECT
import Control.Monad
import Data.Array.Unboxed
import Data.Array.ST

solve :: Int -> Int -> [String] -> Maybe Int
solve h w rows
    = case [t + 1 | (i,t) <- assocs distToMe, t < maxBound, onEdge i] of
        [] -> Nothing
        ts -> Just (minimum ts)
    where
        -- The input grid as an array:
        grid = listArray ((1,1),(h,w)) (concat rows) :: UArray (Int,Int) Char

        -- Returns whether the given coordinates are inside the grid boundaries:
        inBounds (r,c) = r >= 1 && r <= h && c >= 1 && c <= w

        -- Returns whether the given coordinates lie on the edge of the grid:
        onEdge (r,c) = r == 1 || r == h || c == 1 || c == w

        -- Calculates location/times adjacent to a location/time pair:
        neighbours ((r,c), t) = [ ((r + dr, c + dc), t + 1) 
                                | (dr,dc) <- [(-1,0), (0,-1), (0,1), (1,0)] ]

        -- A grid cell is accessible to fire if it's in bounds and not a wall:
        openToFire (i,_) = inBounds i && grid!i /= '#'

        -- A grid cell is accessible to me if I get there before the fire does:
        openToMe (i,t) = inBounds i && grid!i /= '#' && distToFire!i > t

        -- Returns all locations where `char' occurs in the input grid:
        find char = [ coords | (coords,value) <- assocs grid, value == char ]

        -- Distance for each grid location to the nearest fire:
        distToFire = computeDistances (filter openToFire . neighbours) (find '*')

        -- Distance for each grid location to me (if I avoid the fire):
        distToMe = computeDistances (filter openToMe . neighbours) (find '@')

        {- Returns a grid-sized 2D array with the distances from the `initial'
           set of locations, using the `expand' function to determine which
           cells are reachable at every step.

           (Breadth-first-search is used instead of a fancier algorithm like
            Dijkstra's, because every step takes equal time.)
        -}
        computeDistances expand initial
            = runSTUArray (do
                a <- newArray (bounds grid) (maxBound :: Int)
                mapM_ (\i -> writeArray a i 0) initial
                let
                    relax (i,t) = do u <- readArray a i
                                     if (t < u) then do writeArray a i t
                                                        return True
                                                else return False

                    run []     = return a
                    run fringe = filterM relax (expand =<< fringe) >>= run

                    in run [(i,0) | i <- initial])

-- Reads, solves, and prints the answer to a single testcase
doCase = do
    [w,h] <- liftM (map read.words) getLine
    grid  <- h `replicateM` getLine
    case solve h w grid of
            Just answer -> print answer
            Nothing     -> putStrLn "IMPOSSIBLE"

main = readLn >>= (`replicateM_` doCase)
