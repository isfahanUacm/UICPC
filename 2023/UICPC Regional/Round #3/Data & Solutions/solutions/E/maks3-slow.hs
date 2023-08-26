-- @EXPECTED_RESULTS@: TIMELIMIT
-- An O(n*n) solution; this should be too slow.

import Control.Monad

solve :: String -> String
solve line = [ line!!(i + j) | j <- [k-1,k-2..0], i <- [0,k..k*k-k] ]
    where k = floor $ sqrt $ fromIntegral $ length line

main = readLn >>= (`replicateM` (getLine >>= putStrLn.solve))
