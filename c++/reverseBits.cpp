// https://leetcode.com/problems/reverse-bits/

// leetcode submission
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int times = 32;
        vector<int> v;
        while(times > 0) {
            int t = n & 1;
            n >>= 1;
            v.push_back(t);
            times--;
        }
        
        uint32_t res = 0;
        for (auto t : v) {
            res <<= 1;
            res |= t;
        }
        return res;
    }
};

// local system
#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint32_t n;
    cin >> n;

    int times = 32;
    vector<int> v;
    while(times > 0) {
        int t = n & 1;
        n >>= 1;
        v.push_back(t);
        times--;
    }
    
    uint32_t res = 0;
    for (auto t : v) {
        res <<= 1;
        res |= t;
    }

    cout << "output is " << res;
    return 0;
}