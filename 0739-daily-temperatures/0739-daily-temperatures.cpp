class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;
        st.push({t[n-1], n-1});
        for (int i = n - 2; i >= 0; i--){
            while(!st.empty() && st.top().first <= t[i]){
                st.pop();
            }
            if (st.empty()){
                st.push({t[i], i});
                ans[i] = 0;
            }
            else{
                int idx = st.top().second;
                ans[i] = idx - i;
                st.push({t[i], i});
            }
        }
        return ans;
    }
};