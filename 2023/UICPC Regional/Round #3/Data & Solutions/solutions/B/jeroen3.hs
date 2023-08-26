-- @EXPECTED_RESULTS@: CORRECT
import System.IO

main :: IO ()
main = do hSetBuffering stdout LineBuffering
          interact $ unlines . (\([t]:xs) -> testcases (read t) xs) . map words . lines

testcases :: Int -> [[String]] -> [String]
testcases 0 _    = []
testcases n cmds = "3 1 3 6" : f cmds
  where
    move [r1,c1,r2,c2] = unwords . map show $ [6-r2,7-c2,6-r1,7-c1]
    f (("MOVE":xs):ys) = move (map read xs) : f ys
    f (["GAME"]   :ys) = testcases (n - 1) ys