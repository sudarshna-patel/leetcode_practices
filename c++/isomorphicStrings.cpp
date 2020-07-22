// https://leetcode.com/problems/isomorphic-strings/

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if (s.size() != t.size()) return false;
        
//         unordered_map<char, char> mp;
//         set<char> vals;
        
//         for(int i = 0; i < s.size(); i++) {
//             if (mp.find(s[i]) != mp.end()) {
//                 if (mp[s[i]] != t[i])
//                     return false;
//             } else {
//                 if (vals.find(t[i]) == vals.end()) {
//                     mp.insert({s[i], t[i]});
//                     vals.insert(t[i]);
//                 }
//                 else
//                     return false;
//             }
//         }
        
//         return true;
//     }
// };

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    string s = "ab", t = "aa";
    bool res = true;

    if (s.size() != t.size()) return false;
    
    unordered_map<char, char> mp;
    set<char> vals;
    
    for(int i = 0; i < s.size(); i++) {
        if (mp.find(s[i]) != mp.end()) {
            if (mp[s[i]] != t[i]) {
                res = false;
                break;
            }
        } else {
            if (vals.find(t[i]) == vals.end()) {
                mp.insert({s[i], t[i]});
                vals.insert(t[i]);
            }
            else {
                res = false;
                break;
            }
        }
    }

    cout << "Strings are " << (res ? "isomorphic" : "not isomorphic");
    return 0;
}