class Solution {
public:
    int calctotalhours(vector<int> &piles,int k){
        long double totalH = 0 ;
        int n = piles.size();
        for(int i = 0; i< n ;i++){
            totalH += ceil((long double)(piles[i])/(k));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =  1 ;
        int high = *max_element(piles.begin(),piles.end());
        while(low < high){
            int mid = (low + high)/2;
      
            if(calctotalhours(piles,mid) <= h){
                    high = mid ;
            }
            else
            {
                low = mid  + 1 ;
            }
        }
        return low;
    }
};
