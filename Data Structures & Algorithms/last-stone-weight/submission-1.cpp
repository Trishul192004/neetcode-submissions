class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        
        //put all stones into pq
        for(int i =0 ; i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            //get largest 
            int x = pq.top();
            pq.pop();
            //get 2nd largest
            int y = pq.top();
            pq.pop();

            if(x != y) {
                pq.push(x-y);
            }

            //if x==y both oost, ntg to push
        }

      return pq.empty() ? 0: pq.top();
    }
};
