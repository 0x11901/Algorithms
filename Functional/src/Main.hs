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

total []       = 0
total (x : xs) = x + total xs
