
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();

        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
            if(arr[j]== target - arr[i]){
                    return {i+1,j+1};
            }
        }
        }
        return {};
    }
};
*/


/*
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();

        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
            if(arr[j]== target - arr[i]){
                    return {i+1,j+1};
            }
        }
        }
        return {};
    }
};
*/


class Solution{
    public:
    vector<int> twoSum(vector<int> &arr,int target){
        int left = 0;
        int right = arr.size()-1;
        while(left <right){
            int sum = arr[left] + arr[right];
            if(sum == target){
                return{left+1,right+1};
            }
            else if(sum >target){
                right--;
            }
            else{
                left++;
            }
        }
            return {};
    }
};