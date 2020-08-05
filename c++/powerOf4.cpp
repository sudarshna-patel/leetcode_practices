// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    // // based on one set bit and even number of trailing zeros
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        int count = 0;
        
        /*Check if there is only one bit set in n*/
        if ( n && !(n&(n-1)) ) {
            
            /* count 0 bits before set bit */
            while (n > 1) {
                n >>= 1;
                count++;
            }
            
            /*If count is even then return true else false*/
            return (count%2 == 0) ? true : false;
        }
        
        /* If there are more than 1 bit set then n is not a power of 4 */
        return false;
    }
};