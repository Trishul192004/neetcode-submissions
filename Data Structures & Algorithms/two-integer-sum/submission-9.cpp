/*
2 FOR LOOPS
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i =0 ;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                    if(nums[j] == target - nums[i]){
                        return {i,j};
                    }
        }
    }
                    return {};
    };
};
*/

class Solution{
    public:
    vector<int> twoSum(vector<int> &nums,int target){
        map<int ,int >mpp;
        int n= nums.size();
        for(int i=0;i<n;i++){
         int difference = target - nums[i];

         if(mpp.find(difference) != mpp.end()){
            return{mpp[difference],i};
         }
         mpp[nums[i]] = i;
        }

        return {};
        }
        
    };
