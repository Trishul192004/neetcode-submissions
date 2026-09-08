/* BF N2, 1
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
                else{
                break;
                }
            }
        }
        return false;
    }
};
*/

class Solution{
    public:

     bool containsNearbyDuplicate(vector<int> &nums,int k){
        int n = nums.size();
        unordered_map<int,int>mpp;

        for(int i = 0 ; i< n ; i ++){
            if(mpp.find(nums[i]) != mpp.end()){  // get element again in map
                int previndex = mpp[nums[i]];
                if(i - previndex <= k) return true;
            }
            mpp[nums[i]] = i;
        }
        return false;

     }
};