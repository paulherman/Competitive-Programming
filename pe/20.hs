import Data.Char

fact n = if n == 0 then 1 else n * fact (n - 1)

compute = sum . map digitToInt . show . fact