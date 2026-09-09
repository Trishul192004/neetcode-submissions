/*class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        
        int n = arr.size();
        int mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            
            int sum = 0;

            for(int j = i; j < n; j++) {
                
                sum += arr[j];

                if(sum >= target) {
                    mini = min(mini, j - i + 1);
                    break;
                }
            }
        }

        if(mini == INT_MAX)
            return 0;

        return mini;
    }
};
 BF - N2,1
*/


class Solution{
    public:
    int minSubArrayLen(int target,vector<int> &arr){
        int n = arr.size();
        int l = 0 ;
        int r = 0;
        int sum = 0;
        int minlen = INT_MAX;
        while(r < n){
            sum += arr[r];
            while(sum >= target){
                minlen = min(minlen,r-l+1);
                sum -= arr[l];
                l++;
            }
            r++;
        }
       return  minlen == INT_MAX ? 0 :minlen;
    }
};