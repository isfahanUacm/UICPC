-- @EXPECTED_RESULTS@: CORRECT
import Control.Monad

solve = maximum . drop 76 . foldl improve (1:replicate 150 0)
    where improve m (s, p) = zipWith max m (take s m ++ map (p*) m)

doCase = readLn >>= (`replicateM` getLine) >>= (print.(100*).solve.map parse)
    where parse line = let [s, p] = words line in (read s, read p / 100)

main = readLn >>= (`replicateM_` doCase)
