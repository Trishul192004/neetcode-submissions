class Solution {
public:
    int f(int ind, int target, vector<int>& nums,vector<vector<int>>& dp) {

        int n = nums.size();

        // Base case: all elements have been processed
        if (ind == n) {
            if (target == 0) return 1;
            return 0;
        }

        // Check if the answer is already calculated
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        // Choice 1: Do not take the current element
        int nottake = f(ind + 1, target, nums, dp);

        // Choice 2: Take the current element if possible
        int take = 0;

        if (nums[ind] <= target) {
            take = f(ind + 1, target - nums[ind], nums, dp);
        }

        // Count all valid subsets
        return dp[ind][target] = take + nottake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        // Calculate the total sum
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Target must lie between -sum and +sum
        if (target > sum || target < -sum) {
            return 0;
        }

        // sum + target must be even
        if ((sum + target) % 2 != 0) {
            return 0;
        }

        // Convert Target Sum into Count Subsets with Given Sum
        int newtarget = (sum + target) / 2;

        // Initialize the DP table
        vector<vector<int>> dp(n, vector<int>(newtarget + 1, -1));

        return f(0, newtarget, nums, dp);
    }
};

