class Solution {
public:
    bool checkString(string s) {
        int k=0;
        while(s[k]=='a') k++;
        for(char i=k;i<s.size()-1;i++){
            if(s[i]=='b'){
                if(s[i+1]=='b') continue;
                else return false;
            }
        }
        return true;
    }
};