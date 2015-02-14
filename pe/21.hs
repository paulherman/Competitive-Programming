divs n = iter 2 n
	where iter d n = if d == n then [] else (if n `mod` d == 0 then d : iter (d + 1) n else iter (d + 1) n)

upTo :: Integer -> [Integer]
upTo n = [1..n]

compute :: Integer -> Integer
compute = sum . map (sum . divs) . upTo