class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0 ;
        int j = 0 ;

        string res = "";
        while( i < n && j < m){
            res.push_back(word1[i]);
            res.push_back(word2[j]);
            
            i++;
            j++;
        }

        while (i < n) { res.push_back(word1[i]); i++; } 
        while (j < m) { res.push_back(word2[j]); j++; }

        return res;
    }
};