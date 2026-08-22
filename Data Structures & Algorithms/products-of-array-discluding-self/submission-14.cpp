
/* BRUTE FORCE
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int>result;
            int index;
            for(int i =0;i<n;i++){
                int product = 1;
                for(int j =0 ;j<n;j++){
                    if(j == i) continue;
                     product = product * nums[j];
                   
                }
                 result.push_back(product);
            }
            return result;
    }
};

*/

class Solution{
    public:
    vector<int> productExceptSelf(vector<int>&nums){
        int n = nums.size();
        vector<int>left_products(n);
        vector<int>right_products(n);
        vector<int>result(nums.size());

        left_products[0] = 1;
        for(int i =1 ; i < nums.size();i++){
            left_products[i] = left_products[i-1] * nums[i-1];
        }

        right_products[nums.size()-1] = 1;
        for(int i = nums.size()-2 ;i >=0;i--){
            right_products[i] = right_products[i+1] * nums[i+1];
        }

        for(int i =0;i<nums.size();i++){
            result[i] = left_products[i] * right_products[i];
        }
        return result;
    }

};
