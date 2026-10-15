class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(2*n);
        for(int i =0 ; i< n ;i++){
            temp[i] = nums[i];
            temp[i+n] = nums[i];
        }


        return temp;
    }
};