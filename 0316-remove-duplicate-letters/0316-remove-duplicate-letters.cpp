class Solution {
public:
    string removeDuplicateLetters(std::string s) {
        stack<char> stack;
        unordered_set<char> seen;
        unordered_map<char, int> last_occ;
        for (int i = 0; i < s.size(); i++) {
            last_occ[s[i]] = i;
        }
        
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (seen.find(ch) == seen.end()) {
                while (!stack.empty() && ch < stack.top() && i < last_occ[stack.top()]) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(ch);
                stack.push(ch);
            }
        }
        
        string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};