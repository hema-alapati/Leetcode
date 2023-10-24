class Solution {
public:
    string reverseWords(string s) {
        stack<string>words;
        string word="";
        int n=s.length();
        for(int i=0;i<n;i++){
            string word="";
            while (i < n && s[i] == ' ') {
                i++; // Skip leading spaces
            }
            if (i >= n) {
                break;
            }
            while(s[i]!=' '&&i<s.length()){
                word+=s[i];
                i++;
            }
            words.push(word);
        }
        word="";
        while(!words.empty()){
            word+=words.top();
            words.pop();
            if(!words.empty()){
                word+=' ';
            }
        }
        return word;
    }
};