module Main where
import           Data.List
import           Data.Maybe

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
-- fibs' n = map fastFib [0 .. n]
fibs' n = take n (map fst (iterate fibStep (0, 1)))

golden :: Fractional a => Int -> [a]
golden n = take n (map (\(x, y) -> x / y) (iterate fibStep (0, 1)))

combine :: [(a, a)] -> [(a, a, a)]
combine ((f1, f2) : (f3, f4) : fs) = (f1, f2, f4) : combine ((f3, f4) : fs)
combine _                          = []

fibPairs :: Int -> [(Int, Int)]
fibPairs n = map fibPair [1 .. n]

difference :: Int -> [Int]
difference n = map (\(f1, f2, f3) -> f1 * f3 - f2 * f2) (combine $ fibPairs n)


romeNotation :: [String]
romeNotation =
    ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

romeAmount :: [Int]
romeAmount = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

pair :: [(Int, String)]
pair = zip romeAmount romeNotation

subtrahend :: Int -> (Int, String)
subtrahend n = head (dropWhile (\(a, _) -> a > n) pair)

convert :: Int -> String
convert 0 = ""
convert n = let (rome, m) = subtrahend n in m ++ convert (n - rome)

--   convert 17
-- = "X" ++ convert (17 - 10)
-- = "X" ++ "V" ++ convert (7 - 5)
-- = "X" ++ "V" ++ "I" convert (2 - 1)
-- = "X" ++ "V" ++ "I" ++ "I" convert (1 - 1)
-- = "X" ++ "V" ++ "I" ++ "I" ++ ""
-- = "XVII"

subtrahend' :: String -> (Int, String)
subtrahend' n = head (dropWhile (\(_, a) -> not (a `isPrefixOf` n)) pair)

convert' :: String -> Int
convert' [] = 0
convert' n =
    let (rome, m) = subtrahend' n
    in  rome + convert' (fromMaybe "" (stripPrefix m n))

search :: (Ord a) => a -> [a] -> Bool
search a [] = False
search a xs | m < a     = search a behind
            | m > a     = search a front
            | otherwise = True
    where (front, m : behind) = splitAt (length xs `div` 2) xs

-- fixme: append all element to one list
search' :: (Ord a) => a -> [a] -> [a]
search' a [] = []
search' a xs | m < a     = search' a behind
             | m > a     = search' a front
             | otherwise = [a]
    where (front, m : behind) = splitAt (length xs `div` 2) xs


