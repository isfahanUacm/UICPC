-- @EXPECTED_RESULTS@: CORRECT

import Control.Monad

splitEvery :: Int -> [a] -> [[a]]
splitEvery _ [] = []
splitEvery n xs = take n xs : splitEvery n (drop n xs)

rotate :: [[a]] -> [[a]]
rotate = foldr (zipWith (:) . reverse) (repeat [])

isqrt :: Int -> Int
isqrt = floor . sqrt . fromIntegral

solve :: String -> String
solve l = concat $ rotate $ splitEvery (isqrt $ length l) l

main = readLn >>= (`replicateM` (getLine >>= putStrLn.solve))
