/* BF found apprch
N2,N
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        
        int n =arr.size();
        vector<int> temp;
    
        for(int i=0;i<n;i++){
            int cnt =1 ;
            bool found = false;
            for(int j = i+1;j<n;j++){
                   
                    if(arr[j]>arr[i]){
                        temp.push_back(cnt);
                        found = true;
                        break;
                    }
                    cnt++;
            }
                    if(!found){
                        temp.push_back(0);
                    }
            }
             return temp;
        }
       
    };

*/

class Solution{
    public:
    vector<int> dailyTemperatures(vector<int> &arr){
        int n = arr.size();
        vector<int>ans(n,0);//ans vector of size n 0's

        stack<int>st;

        for(int i =0 ;i<n;i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                int index = st.top();
                st.pop();
                ans[index] = i - index;
            }
            st.push(i);
        }
            return ans;

    }
};

