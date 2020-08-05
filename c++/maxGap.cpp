// https://leetcode.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int min_val = nums[0], max_val = nums[0];
        
        for (int i = 1; i < n; i++) {
            max_val = max(max_val, nums[i]);
            min_val = min(min_val, nums[i]);
        }
        
        int avg_diff = ceil((max_val-min_val)/(n-1));
        
        vector<int> maxBucket (n-1, INT_MIN);
        vector<int> minBucket (n-1, INT_MAX);
        for(int i = 0; i < n; i++) {
            if (nums[i] == min_val || nums[i] == max_val)
                continue;
            
            int bucket_index = floor((nums[i] - min_val)/avg_diff);
            minBucket[bucket_index] = min(minBucket[bucket_index], nums[i]);
            maxBucket[bucket_index] = max(maxBucket[bucket_index], nums[i]);
        }
        
        int prev_val = min_val;
        int max_gap = 0;
        for (int i = 0; i < n-1; i++) {
            if (minBucket[i] == INT_MAX)
                continue;
            max_gap = max(max_gap, minBucket[i] - prev_val);
            prev_val = maxBucket[i];
        }
        max_gap = max(max_gap, max_val - prev_val);
        
        return max_gap;
    }
};