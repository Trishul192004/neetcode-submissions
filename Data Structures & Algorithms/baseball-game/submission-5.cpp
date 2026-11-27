class Solution{
    public:

    int calPoints(vector<string>&operations){

        int n = operations.size();
        stack<int>st;
        for(int i = 0; i < n ;i++){
            if(operations[i] != "+" && operations[i] != "D" && operations[i] != "C"){
                st.push(stoi(operations[i]));
            }

            else if(operations[i] == "+"){
                int a = st.top();
                st.pop();

                int b = st.top();

                st.push(a);
                st.push(a+b);
            }

            else if(operations[i] == "D"){
                st.push(2 * st.top());
            }

            else if(operations[i] == "C"){
                int a = st.top();
                st.pop();
            }
        }

        int  sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }


        return sum;
    }
};