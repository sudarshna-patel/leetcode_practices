//  https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int, int>> st;
        
        int n = T.size();
        vector<int> res (n, 0);
        res[n-1] = 0;
        
        st.push({T[n-1], 0});
        
        for (int i = n-2; i >= 0; i--) {
            int count = 0;
            while (!st.empty()) {
                if (st.top().first > T[i]){
                    res[i] = count + 1;
                    st.push({T[i], res[i]});
                    break;
                } else {
                    count += st.top().second;
                    st.pop();
                }
            }
            if (st.empty()) {
                res[i] = 0;
                st.push({T[i], 0});
            }
        }
        
        return res;
    }
};

// slightly different approach, same logic
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s; //First is the number while second is the position
        
        int n= T.size();
        vector<int> result(n,0);
        
        for(int i=n-1; i>=0; i--)
        {
            int curr = T[i];
            while(!s.empty() && s.top().first <= curr) s.pop();
            
            result[i] = s.empty() ? 0 : s.top().second - i;

            s.push({curr,i});
        }
        
        return result;
    }
};