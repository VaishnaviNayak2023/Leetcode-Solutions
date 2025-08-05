// 2427. Number of Common Factors
/*Given two positive integers a and b, return the number of common factors of a and b.
An integer x is a common factor of a and b if x divides both a and b.*/

//Solution
class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        int minNum = min(a, b);  // Common factors can't be greater than the smaller number

        for (int i = 1; i <= minNum; ++i) {
            if (a % i == 0 && b % i == 0) {
                count++;
            }
        }
        return count;
    }
};
