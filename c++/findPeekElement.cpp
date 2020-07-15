// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        
        int left = 0, right = nums.size()-1, mid;
        
        while(left <= right) {
            mid = left + (right-left)/2;
            
            if (mid != 0 && mid != nums.size()-1) {
                if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                    return mid;
                else if (nums[mid] < nums[mid+1])
                    left = mid + 1;
                else if (nums[mid-1] > nums[mid])
                    right = mid - 1;
            } else if (mid == 0) {
                if (nums[mid] > nums[mid+1])
                    return mid;
                else
                    left = mid + 1;
            } else {
                if (nums[mid-1] < nums[mid])
                    return mid;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};