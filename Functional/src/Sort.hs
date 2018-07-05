-- Sort.hs
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
