class Solution {
public:
    void solve(vector<int>&nums,int i , vector<int> &current,vector<vector<int>>&ans){

        //we've considered every ele
        if(i == nums.size()){
            ans.push_back(current);
            return;
        }

        //dont take nums[i]
        solve(nums,i+1,current,ans);
       
        //take nums[i]
        current.push_back(nums[i]);
        solve(nums,i+1,current,ans);

        //backtrack -remove nums[i] before returning
        current.pop_back();

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>current;

        solve(nums,0,current,ans);
        return ans;
    }
};
