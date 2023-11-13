import Control.Monad

data State = State Integer Integer Integer Integer deriving (Show)
sell (State money stocks best previous) price = (State newmoney newstocks best price)
    where value = money + previous * stocks
          newstocks = minimum [value `div` price, 100000]
          newmoney = value - newstocks * price

calculate (State money stocks best previous) price
    | previous > price = sell (State money stocks best previous) price
    | otherwise        = (State money stocks (maximum [best, money + price * stocks]) price)

solve a = foldl calculate (State 100 0 100 600) a

result (State _ _ best _) = best

main = do
    n <- readLn
    lines <- forM [1..n] (\a -> readLn)
    print $ result $ solve lines
