class KthLargest {
private :
        int k;

        //min heap
        priority_queue<int,vector<int>,greater<int>>minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int num : nums){
            add(num);
        }
    }

    
    int add(int val) {
        //add new value
        minHeap.push(val);

        //keep only k largest eles
        if(minHeap.size() > k){
            minHeap.pop();
        }

        //root = kth largest
        return minHeap.top();
    }
};
