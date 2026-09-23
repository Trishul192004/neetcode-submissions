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
