
/* BF--
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i< n; i++){
            int sum = 0; 
            for(int j = i;j<n;j++){
                sum += nums[j];
                maxi = max(maxi,sum);
            }
        }
        return maxi;
    }
};
*/


class Solution{
    public:

    int maxSubArray(vector<int>&nums){
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxi = INT_MIN;
        
        while(right < n){
            sum += nums[right];
            maxi = max(maxi,sum);
            
            if(sum < 0){
                sum = 0;
                left = right +1;
            }

            right++;
        }

        return maxi;
    }
};