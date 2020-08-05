// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        
        while(left < right) {
            mid = left + (right - left)/2;
            
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else { // when nums[mid] and nums[hi] are same
                if (right != 0 && nums[right] >= nums[right-1])
                    right--;
                else {
                    left = right;
                    break;
                }
            }
        }
        
        return nums[left];
    }
};