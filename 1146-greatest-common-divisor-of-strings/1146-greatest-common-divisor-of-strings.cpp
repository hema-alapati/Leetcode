class Solution {
public:
    bool isCommonDivisor(string& str, string& candidate) {
        int n = str.length();
        int m = candidate.length();
        
        for (int i = 0; i < n; i++) {
            if (str[i] != candidate[i % m]) {
                return false;
            }
        }
        
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 < len2) {
            swap(str1, str2);
            swap(len1, len2);
        }

        for (int i = len2; i >= 1; i--) {
            if (len1 % i == 0 && len2 % i == 0) {
                string commonDivisor = str1.substr(0, i);

                if (isCommonDivisor(str1, commonDivisor) && isCommonDivisor(str2, commonDivisor)) {
                    return commonDivisor;
                }
            }
        }

        return "";
    }
};