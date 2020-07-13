// https://leetcode.com/problems/happy-number/

//  using hashmap
class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> m;
        
        while (true) {
            int sum = 0;
            while( n != 0) {
                int r = n%10;
                n /= 10;
                sum += r*r;
            }
            
            if (m.find(sum) != m.end())
                return false;
            else
                m.insert({sum, true});
            
            if (sum == 1)
                return true;
            n = sum;
        }
    }
};

//  using sets
class Solution {
public:
    int numSquareSum(int n) 
    { 
        int squareSum = 0; 
        while (n) 
        { 
            squareSum += (n % 10) * (n % 10); 
            n /= 10; 
        } 
        return squareSum; 
    } 

    bool isHappy(int n) {
        set<int> st; 
        while (1) 
        { 
            n = numSquareSum(n); 
            if (n == 1) 
                return true; 
            if (st.find(n) != st.end()) 
                return false; 
            st.insert(n); 
        } 
    }
};