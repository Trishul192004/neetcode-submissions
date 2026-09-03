class Solution {
public:
    int calPoints(vector<string>& operations) {

        stack<int> st;

        int n = operations.size();

        for(int i = 0; i < n; i++) {

            // Case 1: New score
            if(operations[i] != "+" &&
               operations[i] != "D" &&
               operations[i] != "C") {

                st.push(stoi(operations[i]));
            }

            // Case 2: Sum of previous two scores
            else if(operations[i] == "+") {

                int a = st.top();
                st.pop();

                int b = st.top();

                st.push(a);
                st.push(a + b);
            }

            // Case 3: Double previous score
            else if(operations[i] == "D") {

                st.push(2 * st.top());
            }

            // Case 4: Cancel previous score
            else if(operations[i] == "C") {

                st.pop();
            }
        }

        // Calculate total score
        int ans = 0;

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};