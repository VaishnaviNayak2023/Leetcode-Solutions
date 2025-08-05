//29. Divide Two Integers
/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. 
For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.*/
 //Solution

class Solution {
public:
    int divide(int dividend, int divisor) {

        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long for safe abs and use long long to avoid overflow
        long long divd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        long long result = 0;

        // Subtract the divisor multiplied by powers of 2
        while (divd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (divd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            divd -= temp;
            result += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            result = -result;

        // Clamp to 32-bit range
        return (int)result;

    }
};
