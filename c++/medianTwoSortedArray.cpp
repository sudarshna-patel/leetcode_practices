// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        
        if (m == 0 && n == 0)
            return double(0);
        else if (m == 0) {
            if (n % 2 == 0)
                return double(nums2[n/2] + nums2[n/2 - 1])/2;
            else
                return double(nums2[n/2]);
        } else {
            if (m % 2 == 0)
                return double(nums1[m/2] + nums1[m/2 - 1])/2;
            else
                return double(nums1[m/2]);
        }
            
        int l = (m+n+1)/2;
        int r = (m+n+2)/2;
        return double(getKth(nums1, 0, nums2, 0, l) + getKth(nums1, 0, nums2, 0, r))/2;
    }
    
    double getKth(vector<int> A, int aStart, vector<int> B, int bStart, int k){
        if (aStart > A.size()-1) return B[bStart + k - 1];
        if (bStart > B.size()-1) return A[aStart + k - 1];
        
        if (k==1) return min(A[aStart], B[bStart]);
        
        int aMid = INT_MAX, bMid = INT_MAX;
        if (aStart + k/2 - 1 < A.size()) aMid = A[aStart + k/2 - 1];
        if (bStart + k/2 - 1 < B.size()) bMid = B[bStart + k/2 - 1];
        
        if (aMid < bMid)
            return getKth(A, aStart + k/2, B, bStart, k - k/2);
        else
            return getKth(A, aStart, B, bStart + k/2, k - k/2);
    }
};