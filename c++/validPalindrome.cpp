// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        
        for (int i = 0, j = s.size()-1; i < j; ) {
            if (is_alphanumeric(s[i]) && is_alphanumeric(s[j])) {
                if (tolower(s[i]) == tolower(s[j])) {
                    i++;
                    j--;
                } else
                    return false;
            } else if (!(is_alphanumeric(s[i])))
                i++;
            else
                j--;
        }
        return true;
    }
    
    bool is_alphanumeric(char c) {
        if ((65 <= c && c <= 90) || (97 <= c && c <= 122) || (48 <= c && c <= 57))
            return true;
        return false;
    }


    // ==================== other way to do it ========================
    // isalnum(int c) => return 0 or 1, inbuilt method in c++ =====> replacement of is_alphanumeric which i defined above
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        
        for (int i = 0, j = s.size()-1; i < j; ) {
            while (!(isalnum(s[i])) && i < j)
                i++;
            while (!(isalnum(s[j])) && i < j)
                j--;
            
            if (tolower(s[i]) == tolower(s[j])) {
                i++;
                j--;
            } else return false;
        }
        return true;
    }
};