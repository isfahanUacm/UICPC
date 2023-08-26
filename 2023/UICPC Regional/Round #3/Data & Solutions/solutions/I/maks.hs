-- @EXPECTED_RESULTS@: CORRECT
import Control.Monad

splitBy :: (a -> Bool) -> [a] -> [[a]]
splitBy f str = case tail of (_:rest) -> head : splitBy f rest
                             []       -> [head]
                where (head,tail) = break f str

simplify :: String -> String
simplify = combine [] [] . splitBy (=='R')
    where combine left right []          = left ++ "R" ++ right
          combine left right [last]      = last ++ left ++ "R" ++ right ++ "R"
          combine left right (a:b:rest)  = combine (a++left) (b++right) rest

solve :: String -> [a] -> Maybe [a]
solve program input = foldM exec input (simplify program)
  where exec l     'R' = Just (reverse l)
        exec (_:t) 'D' = Just t
        exec _     _   = Nothing

main :: IO ()
main = readLn >>= (`replicateM_` do
    program <- getLine
    input <- getLine >> readLn :: IO [Int]
    case solve program input of
        Just output -> print output
        Nothing     -> putStrLn "error")
