class Solution {
public:

/*
    int missingNumber(vector<int>& nums) {

        unordered_set<int>hash;
        //pushing to hash;
        for(int i =0;i<nums.size();i++){
            hash.insert(nums[i]);
        }

        //check numbers from 0 to n in hash ;
        for(int i =0 ;i<=nums.size();i++){
                if(hash.find(i) == hash.end()) return i;
        }
        return -1;
    }

    */

//XORR APPROACH

    int missingNumber(vector<int> &nums){
        int n = nums.size();
        int ans = 0;
        //xorr numbers from 0 to n i.e to be present
        for(int i =0;i<= n ;i++){
            ans = ans ^ i;
        }

        //xor array elements
        for(int i =0;i<n;i++){
            ans = ans ^nums[i];
        }

        return ans;
    }

};
