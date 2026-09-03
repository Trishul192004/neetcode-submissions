class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
            int n = position.size();

            vector<pair<int,int>>cars;
    //storing respecitve cars pos ,speed together
            for(int i =0 ;i<n;i++){
                cars.push_back({position[i],speed[i]});
            }
    //sort accn position from closest to farest from target
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        stack<double>fleet;
    for(int i =0 ; i<n ;i++){
        int pos = cars[i].first;
        int spd = cars[i].second;

        //calc arrival time
        double time = (double)(target - pos) / spd;
        //if no fleet exists or current car cant catch fleet ahead
        if(fleet.empty() || time > fleet.top()){
            fleet.push(time);
        }
        //current car joins fleet ahead

    }
    return fleet.size();
    }
};
