/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 ;
        int high = n - 1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target) return mid;

            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};

*/


class Solution{
    public:

    int searchInsert(vector<int>&nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n  ;

        while(low<high){
            int mid = (low + high)/2;

            if(nums[mid] >= target){
                high = mid ;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};