

/* BF
class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int>partitions;
        int n = s.size();

        for(int i =0 ; i< n ;i++){
            int startindex = i;
            int endindex = s.rfind(s[i]);

            for(int j = startindex + 1 ; j <= endindex ; j++){
            int lastindexofnextchar = s.rfind(s[j]);

            if(lastindexofnextchar > endindex){
                endindex = lastindexofnextchar;
                }
            }
            partitions.push_back(endindex - startindex + 1);
            //jump to next partition
            i = endindex ;
        }
        return partitions;
    }
};
*/


class Solution{
    public:
    vector<int> partitionLabels(string s){
        vector<int>ans;
        vector<int>last(26);

        // store last occurence for every ch..
        for(int i = 0 ;i < s.size() ;i++){
            last[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = 0;

        for(int i =0 ; i < s.size(); i++){
            //extend curr partiton
            end = max(end, last[s[i]  - 'a']);

            //partition 
            if(i == end){
                    ans.push_back(end - start + 1);
                    start = i + 1;
            }
        }

        return ans;
    }
};















