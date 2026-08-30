

/*
BRUTE FORCE ... O(n2)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n; i++){
            for(int j = i +1 ; j<n; j++){
                if(nums[j] == nums[i]) 

                    return nums[j];
                }
            }
             return 0;
        }
       
    };

*/

/* MAP NLOGN,N

class Solution{
    public:
    int findDuplicate(vector<int> &nums){
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i =0 ; i<n ; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == 2){
                return nums[i];
            }
        }
        return -1;
    }
}

*/


class Solution{
    public:
    int findDuplicate(vector<int> &nums){
        int n = nums.size();
        
        int slow = nums[0];
        int fast = nums[0];

        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow !=fast); // cycle detect


        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }// duplicate detect

        return slow;

    }
};