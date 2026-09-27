class Solution {
public:

    bool backtrack(vector<int>&nums,vector<int>&buckets,int index,int target){
        
        if(index == nums.size()){
            return true;
        }

        //try putting current number to every bucket
        for(int b = 0 ; b < buckets.size();b++){
            if(buckets[b] + nums[index] <= target){
                //choose
                buckets[b] += nums[index];

                if(backtrack(nums,buckets,index + 1,target)) return true;

                buckets[b] -= nums[index];//backtrack
            }
        }
        return false;
    }


    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //not enough eles to create k subsets
        if(k > nums.size())return false;

        int total = 0;

        for(int num : nums){
            total += num;
        }

        if(total %  k != 0){
            return false;
        }

        int target = total / k; //reqd. sum of every subset

        sort(nums.rbegin() , nums.rend());

        if(nums[0] > target) return false;

        vector<int>buckets(k,0);

        return backtrack(nums,buckets,0,target);

    }
};