class Solution {
public:
    string reverseWords(string s) {
        string res="";
        for(int i=0;i<s.size();i++){
            string temp="";
            while(i<s.size()&&s[i]!=' '){
                temp+=s[i];
                i++;
            }
            reverse(temp.begin(),temp.end());
            res+=temp;
            if(i<s.size()){
                res+=' ';
            }
        }
        return res;
    }
};