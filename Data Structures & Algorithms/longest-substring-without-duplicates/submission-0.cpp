class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int n = s.size();
        int left = 0 ;
        int right = 0;
        int maxlen = 0;
        int len = 0 ;
        while (right < n){
            if(hash[s[right]] != -1){//ch. already in hash
                if(hash[s[right]] >= left){
                    left = hash[s[right]] + 1;
                }
            }
            len = right - left + 1;
            maxlen = max(maxlen,len);
            hash[s[right]] = right;
            right++;
        }
        return maxlen;
    }
};
