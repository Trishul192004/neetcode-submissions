class Solution {
public:

    int f(int ind, vector<int>& coins, int amount) {

        // Base case
        if (ind == 0) {

            if (amount % coins[0] == 0)
                return amount / coins[0];

            return 1e9;
        }

        // Don't take current coin
        int nottake = f(ind - 1, coins, amount);

        // Take current coin
        int take = 1e9;

        if (coins[ind] <= amount) {
            take = 1 + f(ind, coins, amount - coins[ind]);
        }

        // We need minimum number of coins
        return min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        int ans = f(n - 1, coins, amount);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};