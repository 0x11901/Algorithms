module Main where

main :: IO ()
main = putStrLn "no head feelings"

power :: Int -> Int -> Int
power 0 0 = 1
power _ 0 = 1
power x n = x * power x (n - 1)

power' :: Int -> Int -> Int
power' 0 0 = 1
power' _ 0 = 1
power' x n | odd n     = let p = power' x ((n - 1) `div` 2) in x * p * p
           | otherwise = let p = power' x (n `div` 2) in p * p

containes6 :: [String]
containes6 = filter (elem '6') (map show [1 .. 100])

factorial :: Integer -> Integer
factorial n | n < 0     = error "n is less than 0"
            | n == 0    = 1
            | otherwise = n * factorial (n - 1)

mygcd :: Int -> Int -> Int
mygcd x y = if y == 0 then x else mygcd y (mod x y)

product' []       = 1
product' (x : xs) = x * product' xs

-- total []       = 0
-- total (x : xs) = x + total xs

total' []       n = n
total' (x : xs) n = total' xs $! (x + n)
total xs = total' xs 0

mc n | n > 100   = n - 10
     | otherwise = mc (mc (n + 11))

fibonacci :: (Num a, Eq a) => a -> a
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n - 1) + fibonacci (n - 2)

fibs n = map fibonacci [0 .. n]

fibStep :: Num a => (a, a) -> (a, a)
fibStep (u, v) = (v, u + v)

fibPair :: (Eq a, Num a) => a -> (a, a)
fibPair 0 = (0, 1)
fibPair n = fibStep (fibPair (n - 1))

fastFib :: (Eq b, Num b) => b -> b
fastFib n = fst $ fibPair n
fibs' n = map fastFib [0 .. n]
