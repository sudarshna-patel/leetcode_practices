// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        unordered_map<char, int> mp;
        
        for (auto c : s)
            if (mp.find(c) == mp.end())
                mp.insert({c, 1});
            else
                mp[c] += 1;
        
        for (auto c : t) {
            if (mp.find(c) == mp.end())
                return false;
            else
                mp[c] -= 1;
        }
        
        for (auto m : mp)
            if (m.second != 0)
                return false;
        
        return true;
    }
};