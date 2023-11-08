class Solution {
public:
    int nextGreater(int x, vector<int>arr){
        int i;
        int s=0;
        while(i!=x){
            i=arr[s];
            s++;
        }
        if(s>=arr.size()){
            return -1;
        }
        for(int i=s;i<arr.size();i++){
            if(arr[i]>x){
                return arr[i];
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int m=nums1.size();
        int n=nums2.size();
        for(int i=0;i<m;i++){
            if(nums1[i]==nums2[n-1]) res.push_back(-1);
            else{
                res.push_back(nextGreater(nums1[i],nums2));
            }
        }
        return res;
    }
};