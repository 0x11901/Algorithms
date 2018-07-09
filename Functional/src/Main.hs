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

insert' :: Ord a => a -> [a] -> [a]
insert' x [] = [x]
insert' x (y : ys) | x < y     = x : y : ys
                   | otherwise = y : insert' x ys

insertionSort :: Ord a => [a] -> [a] -> [a]
insertionSort xs []       = xs
insertionSort xs (y : ys) = insertionSort (insert' y xs) ys

swaps :: Ord a => [a] -> [a]
swaps []  = []
swaps [x] = [x]
swaps (x1 : x2 : xs) | x1 > x2   = x2 : swaps (x1 : xs)
                     | otherwise = x1 : swaps (x2 : xs)

fix :: Eq a => (a -> a) -> a -> a
fix f x = if x == x' then x else fix f x' where x' = f x

bubbleSort :: Ord a => [a] -> [a]
bubbleSort = fix swaps

bubbleSort' :: Ord a => [a] -> [a]
bubbleSort' xs | swaps xs == xs = xs
               | otherwise      = bubbleSort' $ swaps xs

bubbleSort'' :: Ord a => [a] -> [a]
bubbleSort'' [] = []
bubbleSort'' xs = bubbleSort'' initialElements ++ [lastElement]
  where
    swappedxs       = swaps xs
    initialElements = init swappedxs
    lastElement     = last swappedxs

delete' :: Eq a => a -> [a] -> [a]
delete' _ [] = []
delete' x (l : ls) | x == l    = ls
                   | otherwise = l : delete' x ls

selectionSort [] = []
selectionSort xs = mini : selectionSort xs'
  where
    mini = minimum xs
    xs'  = delete mini xs

quickSort :: Ord a => [a] -> [a]
quickSort []       = []
quickSort (x : xs) = quickSort mini ++ [x] ++ quickSort maxi
  where
    mini = filter (< x) xs
    maxi = filter (>= x) xs

filterSplit :: (a -> Bool) -> [a] -> ([a], [a])
filterSplit _ [] = ([], [])
filterSplit f (x : xs) | f x       = (x : l, r)
                       | otherwise = (l, x : r)
    where (l, r) = filterSplit f xs

quickSort' :: Ord a => [a] -> [a]
quickSort' []       = []
quickSort' [x     ] = [x]
quickSort' (x : xs) = quickSort' l ++ [x] ++ quickSort' r
    where (l, r) = filterSplit (< x) xs

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x : xs) (y : ys) | x > y     = y : merge (x : xs) ys
                        | otherwise = x : merge xs (y : ys)

mergeSort :: Ord a => [a] -> [a]
mergeSort []  = []
mergeSort [x] = [x]
mergeSort xs  = merge (mergeSort x1) (mergeSort x2)
  where
    (x1, x2) = halve xs
    halve xs = (take l xs, drop l xs)
    l = length xs `div` 2

halt :: Integral a => a -> [a]
halt 1 = [1]
halt n | even n    = let n' = div n 2 in n' : halt n'
       | otherwise = let n' = 3 * n + 1 in n' : halt n'

squareroot :: Int -> Double -> Double
squareroot 0 x = x
squareroot n x = (squareroot (n - 1) x + x / squareroot (n - 1) x) / 2

fix' :: (t -> t -> Bool) -> (t -> t) -> t -> t
fix' c f x | c x (f x) = x
           | otherwise = fix' c f (f x)

newton :: Fractional a => a -> a -> a
newton c t = (c / t + t) / 2.0

mysqrt :: Double -> Double
mysqrt c =
    fix' (\a b -> a - b < 0.0000000000000000000000000000000001) (newton c) c

nature = 0 : map (+ 1) nature

merge' :: Ord a => [a] -> [a] -> [a]
merge' xs [] = xs
merge' [] ys = ys
merge' (x : xs) (y : ys) | x > y     = y : merge' (x : xs) ys
                         | otherwise = x : merge' xs (y : ys)

-- ham = [1] merge' map (* 2) ham merge' map (* 3) ham merge' map (* 5) ham
-- ham = merge' [1] (map (* 2) ham)
