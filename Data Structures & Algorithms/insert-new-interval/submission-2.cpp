class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {

            // Current interval is before newInterval
            if(intervals[i][1] < newInterval[0]) {
                ans.push_back(intervals[i]);
            }

            // Current interval is after newInterval
            else if(intervals[i][0] > newInterval[1]) {
                ans.push_back(newInterval);

                // Prevent inserting newInterval again
                newInterval = intervals[i];
            }

            // Overlapping
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        // Add the final newInterval
        ans.push_back(newInterval);

        return ans;
    }
};