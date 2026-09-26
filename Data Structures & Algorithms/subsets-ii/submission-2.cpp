class Solution {
public:
    void solve(vector<int>&nums,int start,vector<int>&current,vector<vector<int>>&ans){

            int n = nums.size();


            ans.push_back(current);


            for( int i = start ;i < n  ;i++){
                if(i > start &&  nums[i] == nums[i - 1]) continue; // skip duplicates
                
                current.push_back(nums[i]); //take
                solve(nums, i + 1 ,current,ans);
                current.pop_back(); //backtrack , remove while returning
            }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>current;
        solve(nums,0,current,ans);
        return ans;
    }
};
