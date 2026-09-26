class Solution {
public:
    void solve(vector<int>&nums,vector<bool>&used,vector<int>&current,vector<vector<int>>&ans){
        int n = nums.size();

        if(current.size() == n){
            ans.push_back(current);
            return;
        }

        //try every ele
        for(int i = 0 ;i < n ;i++){
            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue; //duplicate
             
             //take 
            used[i] = true; 
            current.push_back(nums[i]);
        

            solve(nums,used,current,ans);

            //backtrack
            used[i] = false;
            current.pop_back();
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool>used(nums.size(),false);
        vector<vector<int>>ans;
        vector<int>current;
        solve(nums,used,current,ans);
        return ans;
    }
};