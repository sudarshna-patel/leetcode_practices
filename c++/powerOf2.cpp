// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    // Solution 1
    // based on one set bit
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        return (n && !(n&(n-1))) ? true : false;
    }

    // Solution 2
    bool isPowerOfTwo(int n) {
        double d = 1;
        while(n >= d){
            if (n == d)
                return true;
            d *= 2;
        }
        return false;
    }

    // Solution 3
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n%2 == 0) n/=2;
        return n == 1;
    }
};