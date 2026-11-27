class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>cars;
        
        for(int i= 0; i < n ;i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end(),greater<pair<int,int>>());


        int time;
        stack<double>fleet;

        for(int i =0 ; i < cars.size(); i++){
            int position = cars[i].first;
            int speed = cars[i].second;

            double time = (double)(target - position)/speed;

            if(fleet.empty() || time > fleet.top()){
                fleet.push(time);
            }
    }
    
    return fleet.size();
    }
};
