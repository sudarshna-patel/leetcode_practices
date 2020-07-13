// https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        
        if (s.size() < 11) return res;
        
        unordered_map<string, int> mp;
        set<string> st;
        
        for(int i = 0; i < s.size()-9; i++) {
            string temp = s.substr(i, 10);
            if (mp.find(temp) == mp.end())
                mp.insert({temp, 1});
            else {
                st.insert(temp);
                // mp[temp]++;
            }
        }
        
        for(auto t : st) {
            res.push_back(t);
        }
        
        return res;
    }
};