class Solution {
public:
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
};
