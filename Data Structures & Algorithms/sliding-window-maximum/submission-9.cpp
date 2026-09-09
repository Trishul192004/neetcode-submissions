
/* BF  nk,n
class Solution { 
public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { 
        
        int n = nums.size();
        vector<int> ans;
        
        // Start of every window
        for(int i = 0; i <= n - k; i++) {
            
            int maxi = nums[i];
            
            // Find maximum in current window
            for(int j = i; j < i + k; j++) {
                
                maxi = max(maxi, nums[j]);
            }
            
            // Store maximum of current window
            ans.push_back(maxi);
        }
        
        return ans;
    } 
};
*/


class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int> &arr,int k){
        int n= arr.size();
        vector<int>ans;
        deque<int>dq;

        for(int i =0 ; i<n; i++){
            //remvoe smaller eles outside window
            if(!dq.empty() && dq.front() <= i-k ){
                dq.pop_front();
            }

            //remove smaller eles from back
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }

            //add current index;
            dq.push_back(i);

            //window is ready
            if(i >= k-1){
                ans.push_back(arr[dq.front()]);
            }

        }
        return ans;
    }
};