-- @EXPECTED_RESULTS@: CORRECT
import Control.Monad
import Data.Char

solve n = [undefined
    , 247073176590943186439168
    , 247073176590943186439168
    , 247073176590943186439168
    , 247073176590943186439168
    , 247073176590943186439168
    , 247072845992125906439168
    , 247070813693717458439168
    , 247066755953764920839168
    , 247057349205125525039168
    , 247033689015563322839168
    , 246972918870264891599168
    , 246861685382219625635168
    , 246649942550172329918528
    , 246186412211125491061952
    , 245228224202749711059488
    , 243985945560913777006648
    , 241881462878144723956828
    , 238716451221474026524964
    , 234321237560142152844748
    , 228531034766423460935995
    , 222103036346998935592602
    , 212795095987221162977007
    , 200891157701282775146124
    , 186126554624712816982558
    , 169203799155206602426722
    , 150963413026932092081731
    , 130511956302057992471944
    , 108292622641792927940379
    ,  86125966158468487939539
    ,  65606605930495666414544
    ,  48253097635645381932276
    ,  33777682071351065695944
    ,  21581704251132856036848
    ,  13086424949502634295472
    ,   7189532461169824483008
    ,   3899282638457082901248
    ,   1865911064934695745024
    ,    667911312560821570560
    ,    237729048123966382080
    ,     36338228665926746112
    ]!!n / 248708159685825027637248

run = do
    n <- readLn
    print $ solve n

main = do
    n <- readLn
    replicateM_ n run

{-

Used Mathematica to generate table of exact answers: Straightforward memoizing implementation. Note that even using 8 dice, only 1287 different rolls are possible.
Took about 7 minutes to run this on my old laptop (T9300 @ 2.50GHz). I think it could run in a second when well coded.

v[6] = 5;
v[n_] := n; 
Rolls = Table[FrobeniusSolve[{1, 1, 1, 1, 1, 1}, dice], {dice, 1, 8}];
Clear[p]; 
p[scoreTodo_] := p[scoreTodo, 8, {}]; 
p[scoreTodo_, diceLeft_, aside_] := Piecewise[{
      {1, scoreTodo <= 0 && MemberQ[aside, 6]}
    , {0, diceLeft <= 0}
    , {0, Length[aside] == 6}
    , {p2[scoreTodo, diceLeft, aside], True}
    }];
p2[scoreTodo_, diceLeft_, aside_] := p[scoreTodo, diceLeft, aside] = 
    Total[(
        Multinomial @@ #1 * Max[p3[scoreTodo, diceLeft, aside, #1] /@ Range[6]] & )
        /@ Rolls[[diceLeft]]
    ] / 6^diceLeft; 
p3[scoreTodo_, diceLeft_, aside_, roll_][take_] := Piecewise[{
      {0, MemberQ[aside, take]}
    , {0, roll[[take]] == 0}
    , {p[scoreTodo - roll[[take]]*v[take], diceLeft - roll[[take]], Append[aside, take]], True}
    }];

-}