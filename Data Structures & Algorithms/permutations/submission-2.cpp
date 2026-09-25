class Solution {
public:

    void solve(vector<bool>&used , vector<int> &current,vector<int>&nums,vector<vector<int>>&ans){
        //complete permuation
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }

        //try every number
        for(int i = 0 ; i < nums.size() ;i++){
            
            //already used , hence not consider
            if(used[i]) continue;

            //take
            current.push_back(nums[i]);
            used[i] = true;

            solve(used,current,nums,ans);

            //backtrack
            used[i] = false;
            current.pop_back();
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int>current;
        vector<bool>used(nums.size(),false);
        vector<vector<int>>ans;

        solve(used,current,nums,ans);

        return ans;
    }
};
