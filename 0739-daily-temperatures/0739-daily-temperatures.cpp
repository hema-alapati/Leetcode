class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
    int n = t.size();
    vector<int> result(n, 0);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && t[i] > t[s.top()]) {
            int idx = s.top();
            s.pop();
            result[idx] = i - idx;
        }
        s.push(i);
    }

    return result;
}
};