-- @EXPECTED_RESULTS@: CORRECT
import Control.Monad

sd :: Integer -> Integer
sd n = sd2 (n `divMod` 10)
sd2 (-1, 9) = 0
sd2 (big, 9) = 10 * (sd big) + (big + 1) * 45;
sd2 (big, n) = (n + 1) * d big + tr n + sd2 (big - 1, 9)
d 0 = 0
d n = let (a, b) = n `divMod` 10 in d a + b
tr n = (n * (n + 1)) `div` 2

solve a b = sd b - sd (a - 1)

run = do
    line <- getLine
    let [a, b] = map read $ words line
    print $ solve a b

main = do
    n <- readLn
    replicateM_ n run