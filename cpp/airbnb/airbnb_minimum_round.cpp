/*
Given an array of numbers A = [x1, x2, ..., xn] and T = Round(x1+x2+... +xn).
We want to find a way to round each element in A such that after rounding we get a new array B = [y1, y2, ...., yn] such that y1+y2+...+yn = T where  yi = Floor(xi) or Ceil(xi), ceiling or floor of xi.
We also want to minimize sum |x_i-y_i|
*/

Represent numbers in A as:[ i1 + f1, i2 + f2, ..., in + fn ], then T = sum(i1, i2, ..., in) + round(f1, f2, ..., fn).
Let B = [i1 + new_round(f1), i2 + new_round(f2), ..., i2 + new_round(f2) ], where new_round(x) = 0 or 1.

Since T = sum(B), round(f1, f2, ..., fn) = new_round(f1) + new_round(f2) + ... + new_round(fn). . 

Let round(f1, f2, ..., fn) = m, where 0 <= m < n. 
count(f(x) = 1 | x in 1, 2, ..., n) should be equal to m.

To minimise sum(|x_i - y_i|), we should minimise sum(|f_i - new_round(f_i)|).

Now comes our rounding logic:. 
Let's sort [f1, f2, ..., fn]. Round up the largest m numbers and round down the rest, we get [y1, y2, ..., yn].

