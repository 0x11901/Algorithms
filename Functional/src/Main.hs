module Main where

main :: IO ()
main = do
    putStrLn "hello world!"
    (\x -> \y -> x y) abs (-5)