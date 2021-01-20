/* https://leetcode.com/problems/divide-two-integers/ */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN and divisor == -1) return INT_MAX;
        
        bool neg = (dividend > 0) ^ (divisor > 0);
        long A = abs(dividend);
        long B = abs(divisor);
        
        long ans = 0, temp = 0;
        for (int i = 31; i >= 0; i--) {
            if (temp + (B << i) <= A) 
            { 
              temp += B << i; 
              ans |= 1LL << i; 
            } 
        }
        if (neg) ans = -ans;
        return ans;
    }
};