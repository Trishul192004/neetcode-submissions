class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;

        for(auto point:points){
            int x = point[0];
            int y = point[1];

            int dist = (0-x)*(0-x) + (0-y)*(0-y);
            pq.push({dist,{x,y}});

            if(pq.size() > k){
                pq.pop();
            }
        }


        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
