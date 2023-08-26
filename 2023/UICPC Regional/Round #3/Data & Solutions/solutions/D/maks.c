#include <stdio.h>

/*  @EXPECTED_RESULTS@: CORRECT
    Approach: suppose we have a function, f(n), that (efficiently) computes the
    sum of all digits of numbers in range [0, n).  Then we can count the numbers
    in range [a:b] as f(b + 1) - f(a).

    Now to implement f(n).  Suppose n is of the form 'abcde'.  Let's call 'a'
    the leading digit, 'bcde' the trailing digits, 10,000 the magnitude of 'a'
    and 4 the position of 'a' (counted from the right, zero-based), so that
    n = magnitude*leading + trailing and magnitude = 10**position.

    We can partition [0, n) into two ranges: [0, a0000) and [a0000, abcde).

    To count the digits in the first range, we observe that each digit x < a
    occurs in first position exactly 'magnitude' times.  All other digits (0-9)
    occur leading * position * magnitude / 10 times (i.e. for each leading digit
    and for each combination of possible digits in other positions).

    To count the digits in the second range, we note that 'a' occurs as a
    leading digit exactly 'trailing' times (i.e. as a0000, a0001 .. abcde)
    and that the occurance of the other digits can be computed recursively
    as f(trailing).

    This leads to an efficient (O(log n) time) solution.
*/

typedef unsigned long long ull;

static ull sumDigitsBelow(ull n)
{
    ull result = 0, magnitude = 1, trailing;
    int position = 0, leading;

    /* Find position/magnitude for most-significant digit. */
    while (magnitude < n) magnitude *= 10, ++position;

    while (n > 0)
    {
        /* Adjust magnitude/position to next (non-zero) leading digit: */
        while (magnitude > n) magnitude /= 10, --position;

        leading = n/magnitude;
        trailing = n%magnitude;
        result += leading*(leading - 1)/2*magnitude;
        result += leading*position*magnitude*9/2;
        result += leading*trailing;

        n = trailing;
    }
    return result;
}

int main()
{
    int cases = 0;
    ull a, b;
    scanf("%d", &cases);
    while (cases-- > 0 && scanf("%llu %llu", &a, &b) == 2)
        printf("%llu\n", sumDigitsBelow(b + 1) - sumDigitsBelow(a));
    return 0;
}
