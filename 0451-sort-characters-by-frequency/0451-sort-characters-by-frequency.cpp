class Solution {
    public:
        struct CharFrequency {
        char ch;
        int freq;
        
        bool operator<(const CharFrequency& other) const {
            return freq < other.freq;
        }
    };


    string frequencySort(string s) {
        unordered_map<char, int> charCount;
        
        for (char c : s) {
            charCount[c]++;
        }
        
        priority_queue<CharFrequency> maxHeap;
        
        for (const auto& entry : charCount) {
            maxHeap.push({entry.first, entry.second});
        }
        
        string result = "";
        
        while (!maxHeap.empty()) {
            CharFrequency cf = maxHeap.top();
            maxHeap.pop();
            
            for (int i = 0; i < cf.freq; i++) {
                result += cf.ch;
            }
        }
        
        return result;
    }
};