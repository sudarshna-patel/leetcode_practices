// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        
        for(int i = 0; i < nums.size(); i++)
            if (m.find(nums[i]) == m.end())
                m.insert({nums[i], 1});
            else
                m[nums[i]] += 1;
        
        priority_queue<pair<int,int>> pq;
        map<int, int>::iterator itr;
        
        for(itr = m.begin(); itr != m.end(); itr++)
            pq.push(make_pair(itr->second, itr->first));
        
        vector<int> res;
        while (k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return res;
    }
};