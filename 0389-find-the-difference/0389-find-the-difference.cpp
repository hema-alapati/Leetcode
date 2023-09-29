class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> m;
        for (int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++){
            if (m[t[i]] > 0) m[t[i]]--;
            else return t[i];
        }
        // return '\0';
        return 0;
    }
};