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

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
       vector<int>start;
       vector<int>end;

       for(auto interval : intervals){
        start.push_back(interval.start);
        end.push_back(interval.end);
       }
       
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i =0;
        int j = 0;
        int rooms = 0;
        int maxrooms = 0;

        while(i < start.size() && j < end.size()){
            
            if(start[i] < end[j]){
               
                //new meeting starts
                rooms++;
                i++;

                maxrooms = max(rooms,maxrooms);
            }

            else{
                //meeting finished ,free room
                rooms--;
                j++;
            }
        
        }

        return maxrooms;
    }
};
