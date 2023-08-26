-- @EXPECTED_RESULTS@: CORRECT
-- An O(n*sqrt(n)) solution; this should still run in time.

import Control.Monad

splitEvery :: Int -> [a] -> [[a]]
splitEvery _ [] = []
splitEvery n xs = take n xs : splitEvery n (drop n xs)

solve :: String -> String
solve line = [ square!!i!!j | j <- [k-1,k-2..0], i <- [0,1..k-1] ]
    where k      = floor $ sqrt $ fromIntegral $ length line
          square = splitEvery k line

main = readLn >>= (`replicateM` (getLine >>= putStrLn.solve))
