// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int searchUtil(vector<int> nums, int target, int left, int right) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }
        
        int left = 0, right = nums.size()-1, rotated = 0;
        while(left <= right) {
            rotated = left + (right-left)/2;
            if (nums[rotated] > nums[rotated+1]) {
                break;
            } else {
                if (nums[rotated] > nums[nums.size()-1])
                    left = rotated + 1;
                else
                    right = rotated - 1;
            }
        }
        
        int res;
        left = 0;
        right = rotated;
        res = searchUtil(nums, target, left, right);

        if (res == -1) {
            left = rotated + 1;
            right = nums.size()-1;
            res = searchUtil(nums, target, left, right);
        }
        
        return res;
    }
};


// class Solution {
// public:
//     int smallest(vector<int>& nums, int left, int right){
//         if(right < left)
//             return -1;
        
//         int mid = left + (right-left)/2;
        
//         if (nums[mid] < nums[mid-1])
//             return mid;
//         else if (nums[mid] > nums[mid+1])
//             return mid + 1;
//         else{
//             return min(smallest(nums, left, mid-1), smallest(nums, mid+1, right));
//         }
//     }
    
//     int searchValue(vector<int>& nums, int left, int right, int target){
//         if(right < left)
//             return -1;
        
//         int mid = left + (right-left)/2;
        
//         if (nums[mid] == target)
//             return mid;
//         else if (nums[mid] < target)
//             return searchValue(nums, mid+1, right, target);
//         else
//             return searchValue(nums, left, mid-1, target);
//     }
    
//     int search(vector<int>& nums, int target) {
//         if (nums.size()==0)
//             return -1;
//         else if (nums.size() == 1 && nums[0]==target)
//             return 0;
//         else if (nums.size() == 1 && nums[0]!=target)
//             return -1;
        
//         int smallestindex = smallest(nums, 0, nums.size()-1);
//         int ind;
//         if(nums[0] <= target)
//             ind = searchValue(nums, 0, smallestindex-1, target);
//         else
//             ind = searchValue(nums, smallestindex, nums.size()-1, target);
//         return ind;
//     }
//     int search(vector<int>& nums, int target) {
//         if (nums.size()==0)
//             return -1;

//         int left = 0, right = nums.size()-1;
        
//         while(left<right){
//             int mid = left + (right-left)/2;
//             if(nums[mid] > nums[right])
//                 left = mid+1;
//             else
//                 right = mid;
//         }
        
//         int start = left;
//         left = 0;
//         right = nums.size()-1;
        
//         if(target >= nums[start] && target <= nums[right])
//             left = start;
//         else
//             right = start;
        
//         while(left <= right){
//             int mid = left + (right-left)/2;
//             if(target == nums[mid])
//                 return mid;
//             else if (target < nums[mid])
//                 right = mid-1;
//             else
//                 left = mid+1;
//         }
//         return -1;
//     }
// };