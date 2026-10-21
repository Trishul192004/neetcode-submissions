class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        int cnt = 0;
        unordered_map<int,int>mpp;
        
        for(int i = 0 ; i < n ;i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second > (n/3)){
                arr.push_back(it.first);
            }
            else continue;
        }

        return arr;
    }
};