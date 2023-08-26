-- @EXPECTED_RESULTS@: CORRECT
import Data.List

main :: IO ()
main = interact $ unlines . map testcase . tail . lines

testcase :: String -> String
testcase s = concat . reverse . take n . transpose . take n . iterate (drop n) $ s
  where n = round . sqrt . fromIntegral . length $ s