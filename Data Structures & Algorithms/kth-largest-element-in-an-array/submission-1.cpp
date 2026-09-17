class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>>pq; //min heap
        
        for(auto num : nums){
            pq.push(num);

            if(pq.size() > k){ //keep only k largest eles
                pq.pop();
            }
        }

        return pq.top();
    }
};
