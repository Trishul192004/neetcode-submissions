class Solution {
public:

    long long countPairs(vector<int>& nums, long long target) {

        int left = 0;
        int right = nums.size() - 1;

        long long cnt = 0;

        while(left < right) {

            long long sum = (long long)nums[left] + nums[right];

            if(sum <= target) {

                cnt += (right - left);
                left++;

            }
            else {
                right--;
            }
        }

        return cnt;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        sort(nums.begin(), nums.end());

        long long countUpper = countPairs(nums, upper);

        long long countLower = countPairs(nums, (long long)lower - 1);

        return countUpper - countLower;
    }
};