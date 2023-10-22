class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N=flowerbed.size();
        int count=0;
        if(n==0) return true;
        for(int i=0;i<N;i++){
            if(flowerbed[i]==0){
                bool prev=(i==0)||flowerbed[i-1]==0;
                bool next=(i==N-1)||flowerbed[i+1]==0;        
                if(prev && next){
                    flowerbed[i]=1;
                    count++;
                }
                if(count>=n) return true;
            }
        }
        return false;
    }
};