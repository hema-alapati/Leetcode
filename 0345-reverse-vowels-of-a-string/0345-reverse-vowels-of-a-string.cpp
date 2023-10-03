class Solution {
private:
    bool isVowel(char ch) {
        ch = tolower(ch); // Convert to lowercase for case insensitivity
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            while (i < j && !isVowel(s[i])) {
                i++;
            }
            while (i < j && !isVowel(s[j])) {
                j--;
            }
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
