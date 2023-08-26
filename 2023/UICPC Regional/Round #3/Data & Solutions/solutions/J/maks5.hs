-- Approach: somewhat inefficient implementation of the second idea described in
--           solution.txt and implemented in maks3.c.
-- @EXPECTED_RESULTS@: CORRECT

import Control.Monad
import Data.List

solve :: [Int] -> Integer
solve list = sum $ map insertCost $ tail $ zip list (inits list)
    where
        insertCost (x,xs)
            | x < maximum xs = product $ map ((+1).genericLength) $
                               group $ sort $ filter (<x) xs
            | otherwise      = 0

doCase = getLine >> getLine >>= print.solve.map read.words

main = readLn >>= (`replicateM` doCase)
