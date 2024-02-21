Simple card validator using Luhn algorithm.

Suppose we have a credit card number 347609692102916 and want to check whether it's valid.

1.Take the last digit 6. That is our check digit.

2.Now take the rest of the sequence 34760969210291.

3.Double every other digit starting from the right 3,8,7,12,0,18,6,18,2,2,0,4,9,2.

4.Sum up the digits of the products 12 = 1 + 2 = 3, same with 18, which gives you 9.

5.Add all the digits together 3+8+7+3+0+9+6+9+2+2+0+4+9+2 = 64.

6.Multiply the result by 9 (64 * 9 = 576).

7.Take the last digit of the result 6. If this matches the check digit, then we have a valid sequence.
