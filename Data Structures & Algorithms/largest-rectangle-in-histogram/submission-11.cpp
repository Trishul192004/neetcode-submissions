class Solution {
public:
//USING NSE,PSE concepts of stack 2* 2N, N   BF APPRCH..
    vector<int> nextsmallerelement(vector<int>& heights) {

        int n = heights.size();

        vector<int> nse(n);

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }


    vector<int> prevsmallerelement(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse(n);

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }   

        return pse;
    }


    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> pse = prevsmallerelement(heights);
        vector<int> nse = nextsmallerelement(heights);

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            int width = nse[i] - pse[i] - 1;

            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};