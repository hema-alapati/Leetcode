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
                string commonDivisor = str1.substr(0, i);
                string temp1 = commonDivisor, temp2 = commonDivisor;
                
                while (temp1.length() < len1) temp1 += commonDivisor;
                while (temp2.length() < len2) temp2 += commonDivisor;
                
                if (temp1 == str1 && temp2 == str2) {
                    return commonDivisor;
                }
            }
        }
        
        return "";
    }
};