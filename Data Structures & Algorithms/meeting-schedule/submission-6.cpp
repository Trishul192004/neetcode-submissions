/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/* BF
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();

        for(int i =0 ;i < n ;i++){
            for(int j = i + 1; j < n ;j++){
                
                //no overlap
                if(intervals[i].end <= intervals[j].start || intervals[j].end <= intervals[i].start){
                    continue;
                }

                //overlap hai
                else{
                    return false;
                }
            }
        }
            return true;
    }
};
*/

class Solution{
    public:
    bool canAttendMeetings(vector<Interval> &intervals){
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),
        [](Interval &a, Interval &b){
            return a.start < b.start;
        });

        for(int i = 1 ; i < n ; i++){
            if(intervals[i].start < intervals[i-1].end){
                return false;
            }
        }
        return true;
    }
};