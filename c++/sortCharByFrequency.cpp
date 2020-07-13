// https://leetcode.com/problems/sort-characters-by-frequency/

// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> mp;
//         priority_queue<pair<int, char>> pq;
        
//         for (auto c : s)
//             mp[c]++;
        
//         unordered_map<char, int>::iterator it = mp.begin();
//         while (it != mp.end()) {
//             pq.push(make_pair(it->second, it->first));
//             it++;
//         }
        
//         string res;
//         while(!pq.empty()) {
//             string temp(pq.top().first, pq.top().second);
//             res += temp;
//             pq.pop();
//         }
        
//         return res;
//     }
// };

#include <iostream>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    string s = "school";

    unordered_map<char, int> mp;
    priority_queue<pair<int, char>> pq;
    
    for (auto c : s)
        mp[c]++;
    
    unordered_map<char, int>::iterator it = mp.begin();
    while (it != mp.end()) {
        pq.push(make_pair(it->second, it->first));
        it++;
    }
    
    string res;
    while(!pq.empty()) {
        string temp(pq.top().first, pq.top().second);
        res += temp;
        pq.pop();
    }
    cout << res;
    return 0;
}