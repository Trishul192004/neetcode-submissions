class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0 ; i< n ;i++){
            int cnt = 0;
            for(int j = i+1 ; j <n ; j++){
                cnt++;
                if(cnt <= k){
                    if(nums[j] == nums[i]) return true;
                }
     
            }
        }
        return false;
    }
};