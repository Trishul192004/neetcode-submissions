class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       
       int total = 0 ;
       
       int currMax = 0;
       int maxsum = INT_MIN;

       int currMin = 0;
       int minsum = INT_MAX;

       for(int x : nums){
        //max kadane
        currMax = max(x, currMax + x);
        maxsum = max(maxsum,currMax);

        //min kadane
        currMin = min(x,currMin + x );
        minsum = min(minsum,currMin);

        total += x;

       }
       
       //all eles are negative
       if(maxsum < 0) return maxsum;

       return max(maxsum,total - minsum);
    }
};