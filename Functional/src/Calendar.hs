module Calendar where

import           Prelude

type Weekday = Int
type Year = Int
type Month = Int
type Day = Int

week' :: Year -> Day -> Weekday
week' y d =
    let y1 = y - 1
    in  (y1 + (div y1 4) - (div y1 100) + (div y1 400) + d) `mod` 7
