class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        int cnt = 0 ;
        mpp[0] = 1;
        int prefixsum = 0;

        for( int i = 0 ; i < n ; i++){
            prefixsum += nums[i];

            int required = prefixsum - k;

            if(mpp.find(required) != mpp.end()){
                cnt += mpp[required];
            }

            mpp[prefixsum]++;
        }


        return cnt;

    }
};