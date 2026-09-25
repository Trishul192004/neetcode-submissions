class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
         int n = nums.size();
         int total = 0;

         //or all numbers
         for(int num : nums){
            total = total | num;
         }

         //each set bit appears in half of all subsets
         return total * ( 1<< (n - 1));
    }
};