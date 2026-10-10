
class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();

        // Base case: target achieved
        if (target == 0) return true;

        // Base case: no elements remain
        if (ind == n) return false;

        // Check if the state is already calculated
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        // Choice 1: Not take the current element
        bool nottake = f(ind + 1, target, nums, dp);

        // Choice 2: Take the current element if it does not exceed target
        bool take = false;

        if (nums[ind] <= target) {
            take = f(ind + 1, target - nums[ind], nums, dp);
        }

        // Either choice can succeed
        return dp[ind][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        // Calculate the total sum
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // An odd total cannot be divided into equal integer sums
        if (sum % 2 != 0) return false;

        // Required sum of each subset
        int target = sum / 2;

        // Initialize the DP table
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(0, target, nums, dp);
    }
};

