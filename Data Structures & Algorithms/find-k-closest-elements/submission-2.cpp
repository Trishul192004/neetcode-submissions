 /*   nlogn , n
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>>v;
       
        for(int i =0 ;i<n;i++){
            int d = abs(arr[i] - x);
            v.push_back({d,arr[i]});
        }
     
        //sort by dist 
        sort(v.begin(),v.end());

        vector<int>ans;
        //take first k elements
        for(int i=0;i< k;i++){
            ans.push_back(v[i].second);
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};

*/

//BS ON WINDOW .. OPTIMA
class Solution{
    public:

    vector<int>findClosestElements(vector<int> &arr,int k,int x){
         int n = arr.size();

         int l = 0 ; 
         int r = n - k ; // as req. exact  valid window size

         while(l <r){
            int mid = l + (r-l) /2 ;

            if( x - arr[mid] > arr[mid + k] - x){
                l = mid +1; // left side farther from target x so elinimate left
            }
            else
            {
                r = mid ;
            }       
         }
            vector<int>ans;

            for(int i= l ;i< l+k ;i++){
                ans.push_back(arr[i]);
            }
            return ans;
    }

};