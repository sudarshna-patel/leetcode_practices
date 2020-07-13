// https://leetcode.com/problems/subarray-sum-equals-k/

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int sum = 0, count = 0;
//         unordered_map<int, int> mp;
//         mp.insert({0, 1});
        
//         for (auto n : nums) {
//             sum += n;
//             if (mp.find(sum-k) != mp.end())
//                 count += mp[sum-k];
//             mp[sum] += 1;
//         }
        
//         return count;
//     }
// };

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> nums;
    int k = 7;

    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(-3);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(2);

    int sum = 0, count = 0;
    unordered_map<int, int> mp;
    mp.insert({0, 1});
    
    for (auto n : nums) {
        sum += n;
        if (mp.find(sum-k) != mp.end())
            count += mp[sum-k];
        mp[sum] += 1;
    }

    cout << count;
    return 0;
}