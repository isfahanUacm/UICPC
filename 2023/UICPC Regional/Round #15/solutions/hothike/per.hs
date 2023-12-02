solve:: [Int] -> Int -> (Int, Int)
solve [a,b] _ = (0, 50)
solve (a:b:c:t) day
   | max a c <= subtemp  = (day, max a c)
   | otherwise           = (subday, subtemp)
 where
   (subday, subtemp) = solve (b:c:t) (day+1)

parse :: String -> ([Int], Int)
parse str = (map read (words (lines str !! 1)), 1)

disp :: (Int, Int) -> String
disp (a,b) = (show a) ++ " " ++ (show b)

main = interact (disp . uncurry solve . parse)
