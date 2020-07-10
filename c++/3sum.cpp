// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        
        for(int i = 0; i < size-2; i++){
            int target = -nums[i];
            for(int j=i+1, k=size-1; j < k;){
                int sum = nums[j] + nums[k];
                
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else{
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(nums[k]);
                    res.push_back(triplet);
                    
                    while (j < k && nums[j] == triplet[1]) j++;
                    while (j < k && nums[k] == triplet[2]) k--;
                }
            }
            while (i + 1 < size && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};