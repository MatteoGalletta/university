-- Booleans Types
true = \x y -> x
false = \x y -> y

true 1 0
false 1 0

-- Logical Ports

-- And Port
and = \a b -> a b false

and true true 1 0
and true false 1 0
and false true 1 0
and false false 1 0

-- Or Port
or = \a b -> a true b

or true true 1 0
or true false 1 0
or false true 1 0
or false false 1 0

-- Not Port
not = \a -> a false true

not true 1 0
not false 1 0

-- If Then Else
if_then_else = \x -> x

if_then_else true "abc" "xyz"
if_then_else false "abc" "xyz"

