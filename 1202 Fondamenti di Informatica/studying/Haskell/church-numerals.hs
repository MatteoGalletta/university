add1 = \x -> x + 1

-- Church Numerals
zero = \f x -> x
one = \f x -> f x
two = \f x -> f (f x)
three = \f x -> f (f (f x))

-- Chuch Numerals to Natural Numbers
zero add1 0
one add1 0
two add1 0
three add1 0

-- Successor Function
succ = \n f x -> f (n f x)

succ zero add1 0
succ one add1 0
succ two add1 0
succ three add1 0

-- Sum Function
sum = \a b f x -> a f (b f x)

sum one two add1 0
sum two two add1 0
sum three zero add1 0

-- Product Function
prod = \a b f x -> a (b f) x

prod one two add1 0
prod two two add1 0
prod three three add1 0
prod zero three add1 0

-- IsZero Function
is_zero = \a x y -> a (\z -> y) x

is_zero zero 1 0
is_zero one 1 0
is_zero two 1 0
is_zero three 1 0

-- a) Following Expression Function
-- f_a(n) = (n + 3)^2

f_a = \n f x -> prod (sum n three) (sum n three) f x

f_a zero add1 0
f_a one add1 0
f_a two add1 0
f_a three add1 0

-- b) Following Expression Function (IsEven)
-- f_b(n) = true	if n is even
--			false	if n is odd

-- my first try: f_b = \n -> n (\z -> not z) true
f_b = \n -> n (\z x y -> z y x) true

f_b zero 1 0
f_b one 1 0
f_b two 1 0
f_b three 1 0

-- c) Following Expression Function (Power)
-- f_c(n,m) = n^m

f_c = \n m -> m (prod n) one
-- Found on the internet an easier one:
f_c = \n m -> m n

f_c two three add1 0
f_c three two add1 0
f_c three one add1 0
f_c three zero add1 0

-- d) Following Expression Function (Predecessor)
-- f_d(n) = n-1

-- my attempt: f_d = \n f x -> n (\z -> is_zero z x z) x
f_d = \n f x -> n (\g h -> h (g f)) (\u -> x) (\u -> u)

f_d three add1 0
f_d two add1 0
f_d one add1 0
f_d three add1 0
