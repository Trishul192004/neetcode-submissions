class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        for(int i = 0 ; i < n ; i ++){
            int current = asteroids[i];

            //collission is possible only when + - aprrch not <- - +->
/*colisn condn*/ while(!st.empty() && st.top()>0 && current <0){
                    //stack top is bigger
                    if(abs(st.top())  >  abs(current)){
                        current = 0 ; 
                        break; // while shud break as we need next current 
                    }
                    else if(abs(st.top())  < abs (current)){
                        st.pop();
                    }
                    //both equal
                    else{
                        st.pop();
                        current = 0 ; 
                        break;
                    }
                }

                //current survived;
                if(current != 0){
                    st.push(current);
                }
            }

            vector<int>ans(st.size());

            for(int i = ans.size() - 1; i>=0 ; i--){
                ans[i] =  st.top();
                st.pop();
            }

            return ans;

    
    }
};