class Solution {
public:

    int possible(vector<int>&weights,int cap){
        int n = weights.size();

        int load = 0;
        int days = 1;

        for(int i =0 ; i < n ;i++){
            if(load + weights[i] > cap){
                days++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
            return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
            int n = weights.size();
            int low = *max_element(weights.begin(),weights.end()) ;
            int high = accumulate(weights.begin(),weights.end(),0);

            while(low < high){
                int mid = (low + high)/2;
                int reqDays = possible(weights,mid);
                if(reqDays <= days){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }

            return low;
    }
};