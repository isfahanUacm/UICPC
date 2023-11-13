solve:: Int -> Int -> Int
solve n1 n2
   | n2 - n1 > 180  = n2 - n1 - 360
   | n2 - n1 > -180 = n2 - n1
   | otherwise      = n2 - n1 + 360

parse :: String -> (Int, Int)
parse str = (vals !! 0, vals !! 1)
   where vals = (map read) $ words str

main = interact (show . uncurry solve . parse)
