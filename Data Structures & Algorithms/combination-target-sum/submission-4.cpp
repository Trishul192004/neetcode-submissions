class Solution {
public:
    void findcombination(int ind , int target, vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds){
        int n = nums.size();
        if(ind == n){
            if(target ==0){
                ans.push_back(ds);
               
            }
            return;
        }

        //pickup ele
        if(nums[ind] <= target){
            ds.push_back(nums[ind]);
            findcombination(ind,target - nums[ind],nums,ans,ds);
            ds.pop_back();
        }
        //not pick ele
        findcombination(ind+1,target,nums,ans,ds);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,nums,ans,ds);

        return ans;

    }
};
