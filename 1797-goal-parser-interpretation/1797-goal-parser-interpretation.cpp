class Solution {
public:
    string interpret(string command) {
        unordered_map<string, string> d = 
        {
            { "(al)" , "al"},
            { "()" , "o" }, 
            { "G" , "G" },
        };
        string tmp = "", res = "";
        for(char c: command){
            tmp+=c;
            if(d.find(tmp)!=d.end()){
                res += d[tmp] ;
                tmp = "" ;
            }
        }
        return res;
    }
};

