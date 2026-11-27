class Solution{
    public:

    vector<int> asteroidCollision(vector<int>&asteroids){
        int n = asteroids.size();
        stack<int>st;

        for(int i = 0 ; i < n ;i++){
            int current = asteroids[i];

            while(!st.empty() && st.top() > 0 && current < 0){

                if(abs(st.top()) > abs(current)){
                    current = 0 ;
                    break;
                }

                else if(abs(st.top()) < abs(current)){
                    st.pop();
                }

                else{
                    //both equal
                    st.pop();
                    current = 0;
                    break;
                }
            }

            if(current != 0)st.push(current);

        }

        vector<int>ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }   

        reverse(ans.begin(),ans.end());

        return ans;
    }
};