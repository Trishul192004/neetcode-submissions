class Solution {
public:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();

        // Base case: no elements left
        if (ind == n) return 0;

        // Check if the answer is already calculated
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        // Choice 1: Not take the current element
        int nottake = 0 + f(ind + 1, prev, nums, dp);

        // Choice 2: Take the current element if it is increasing
        int take = 0;

        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + f(ind + 1, ind, nums, dp);
        }

        // Store and return the maximum length
        return dp[ind][prev + 1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // n rows and n + 1 columns to handle prev = -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return f(0, -1, nums, dp);
    }
};
