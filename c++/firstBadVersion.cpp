// https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n, mid;
        
        while (left <= right) {
            mid = left + (right-left)/2;
            if (isBadVersion(mid)) {
                if (isBadVersion(mid-1))
                    right = mid - 1;
                else
                    return mid;
            } else {
                if (isBadVersion(mid+1))
                    return mid + 1;
                else
                    left = mid + 1;
            }
        }
        
        return -1;
    }
};