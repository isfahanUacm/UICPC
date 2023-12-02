solve:: [String] -> Int -> String
solve [] _ = "makes sense"
solve (h:t) i
   | h == "mumble" = solve t (i+1)
   | h == show(i)  = solve t (i+1)
   | otherwise     = "something is fishy"

parse :: String -> ([String], Int)
parse str = (words (lines str !! 1), 1)

main = interact (uncurry solve . parse)
