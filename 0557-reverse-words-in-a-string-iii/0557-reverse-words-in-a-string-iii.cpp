class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            string temp = "";
            while (i < s.size() && s[i] != ' ') {
                temp += s[i];
                i++; // Increment i here to avoid an infinite loop
            }
            reverse(temp.begin(), temp.end());
            res += temp;
            if (i < s.size()) {
                res += ' '; // Add a space after each reversed word except the last one
            }
        }
        return res;
    }
};
