#include<bits/stdc++.h>
class Solution {
public:
    vector<int> topKFrequent(vector<int>&nums,int k){
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
             mpp[nums[i]]++;
        }
        vector<pair<int,int>>freq;
        for(auto p: mpp){
            freq.push_back({p.first,p.second});
        }
        //sort accn freq
        sort(freq.begin(),freq.end(),[](pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        });

        //top k elements get
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].first);
        }

        return ans;
    }

};