class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char original = word[j];
                    for (int k = 'a'; k <= 'z'; k++) {
                        word[j] = k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = original;
                }
            }
            ladder++;
        }
        return 0;
    }
};