class Solution {
public:
    bool possible(vector<int>&nums,int barrier,int k){
        int n = nums.size();
        int subarrays = 1;
        int sum = 0;

        for(int i =0 ;i < n;i++){
            if(sum + nums[i] > barrier){
                subarrays++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }

        return subarrays <= k;
    }


    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        int ans = high;

        while(low <= high){
            int mid = (low + high)/2;

            if(possible(nums,mid,k)){

                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};