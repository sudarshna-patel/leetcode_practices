// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> m;
        for(int i = 0 ; i < J.size(); i++)
            m.insert({J[i], i});
        
        int count = 0;
        for (int i = 0; i < S.size(); i++)
            if (m.find(S[i]) != m.end())
                count++;
        
        return count;
    }
};