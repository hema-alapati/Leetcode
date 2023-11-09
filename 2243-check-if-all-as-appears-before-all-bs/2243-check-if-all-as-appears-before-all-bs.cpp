class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        for(char i=0;i<n-1;i++){
            if(s[i]=='b'){
                if(s[i+1]=='b') continue;
                else return false;
            }
        }
        return true;
    }
};