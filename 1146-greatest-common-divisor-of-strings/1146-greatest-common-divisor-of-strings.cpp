class Solution {
public:
        string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();

        if (len1 < len2) {
            swap(str1, str2);
            swap(len1, len2);
        }

        for (int i = len2; i >= 1; i--) {
            if (len1 % i == 0 && len2 % i == 0) {
                bool isCommonDivisor = true;

                for (int j = 0; j < len1; j++) {
                    if (str1[j] != str1[j % i]) {
                        isCommonDivisor = false;
                        break;
                    }
                }

                if (isCommonDivisor) {
                    for (int j = 0; j < len2; j++) {
                        if (str2[j] != str1[j % i]) {
                            isCommonDivisor = false;
                            break;
                        }
                    }
                }

                if (isCommonDivisor) {
                    return str1.substr(0, i);
                }
            }
        }

        return "";
    }
};