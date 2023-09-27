//follow this soln for interviews
// class Solution {
// public:
// 
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string>st(wordList.begin(),wordList.end()); // for better time complexity, stroing the words in an unordered list, which avoids linear time complexity
//         queue<vector<string>>q; // the queue has to store a list of strings 
//         q.push({beginWord});
//         vector<string>usedOnLevel;
//         usedOnLevel.push_back(beginWord);
//         int level=0;
//         vector<vector<string>>ans;
//         while(!q.empty()){
//             vector<string>vec=q.front();
//             q.pop();
//             //erasing words used in previous levels to transform
//             if(vec.size()>level){
//                 level++;
//                 for(auto it:usedOnLevel){
//                     st.erase(it);
//                 }
//                 usedOnLevel.clear();
//             }

//             string word=vec.back();
//             if(word==endWord){
//                 // the first sequence where we reached end
//                 if(ans.size()==0) {
//                     ans.push_back({vec});
//                 }
//                 else if(ans[0].size()==vec.size()){
//                     ans.push_back({vec});
//                 }
//                 // we will push only if they are of same size
//             }
//             for(int i=0;i<word.size();i++){
//                 char original=word[i];
//                 for(char c='a';c<='z';c++){
//                     word[i]=c;
//                     if(st.count(word)>0){
//                         vec.push_back(word);
//                         q.push({vec});
//                         usedOnLevel.push_back(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i]=original;
//             }
//         }
//         return ans;
//     }
// };
// BFS gives TLE if we store path while traversing because whenever we find a better visit time for a word, we have to clear/make a new path vector everytime. 
// The idea is to first use BFS to search from beginWord to endWord and generate the word-to-children mapping at the same time. 
// Then, use DFS (backtracking) to generate the transformation sequences according to the mapping. 
// The reverse DFS allows us to only make the shortest paths, never having to clear a whole sequence when we encounter better result in BFS
// No string operations are done, by dealing with indices instead.

class Solution {
public:
bool able(string s,string t){
    int c=0;
    for(int i=0;i<s.length();i++)
        c+=(s[i]!=t[i]);
    return c==1;
}
void bfs(vector<vector<int>> &g,vector<int> parent[],int n,int start,int end){
    vector <int> dist(n,1005);
    queue <int> q;
    q.push(start);
    parent[start]={-1};
    dist[start]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int u:g[x]){
            if(dist[u]>dist[x]+1){
                dist[u]=dist[x]+1;
                q.push(u);
                parent[u].clear();
                parent[u].push_back(x);
            }
            else if(dist[u]==dist[x]+1)
                parent[u].push_back(x);
        }
    }
}
void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[],int node){
    if(node==-1){
        // as parent of start was -1, we've completed the backtrack
        Paths.push_back(path);
        return ;
    }
    for(auto u:parent[node]){
        path.push_back(u);
        shortestPaths(Paths,path,parent,u);
        path.pop_back();
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // start and end are indices of beginWord and endWord
    int n=wordList.size(),start=-1,end=-1;
    vector<vector<string>> ANS;
    for(int i=0;i<n;i++){
        if(wordList[i]==beginWord)
            start=i;
        if(wordList[i]==endWord)
            end=i;
    }
    
    // if endWord doesn't exist, return empty list
    if(end==-1)
        return ANS;
    
    // if beginWord doesn't exist, add it in start of WordList
    if(start==-1){
        wordList.emplace(wordList.begin(),beginWord);
        start=0;
        end++;
        n++;
    }
    // for each word, we're making adjency list of neighbour words (words that can be made with one letter change)
    // Paths will store all the shortest paths (formed later by backtracking)
    vector<vector<int>> g(n,vector<int>()),Paths;
    
    // storing possible parents for each word (to backtrack later), path is the current sequence (while backtracking)
    vector<int> parent[n],path;
    
    // creating adjency list for each pair of words in the wordList (including beginword)
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(able(wordList[i],wordList[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
    
    bfs(g,parent,n,start,end); 
    
    // backtracking to make shortestpaths
    shortestPaths(Paths,path,parent,end);
    for(auto u:Paths){
        vector <string> now;
        for(int i=0;i<u.size()-1;i++)
            now.push_back(wordList[u[i]]);
        reverse(now.begin(),now.end());
        now.push_back(wordList[end]);
        ANS.push_back(now);
    }
    return ANS;
}
}; 