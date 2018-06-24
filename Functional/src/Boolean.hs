-- Boolean.hs
import Prelude hiding ((/=),(==),not,and,or,(&&),(||))

(==) :: Bool -> Bool -> Bool
(==) True True = True
(==) False False = True
(==) _ _ = False

not :: Bool -> Bool
not True = False
not False = True
not _ = False

