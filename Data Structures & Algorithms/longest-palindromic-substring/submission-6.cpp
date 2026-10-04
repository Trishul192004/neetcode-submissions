 /* LONGEST COMMON SUBSEQUENCE 
class Solution {
public:
    int f(int i,int j, string &s1,string &s2,vector<vector<int>>&dp){
        if(i < 0 || j <0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + f(i-1,j-1,s1,s2,dp) ;
        }
        return dp[i][j] = max(f(i-1,j,s1,s2,dp) , f(i,j-1,s1,s2,dp));
    }


    string longestPalindrome(string s) {
        string rev = s ;
        reverse(rev.begin(),rev.end());
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));

        return f(n-1,n-1,s,rev,dp);
    }
};

*/

class Solution{
public: 
        string longestPalindrome(string s){
            int n = s.size();

            if(n <=1) return s;

             int start = 0;
             int maxlen = 1;

             for(int i =0 ; i < n ; i++){
                //odd length palidnrome
                int l = i;
                int r = i;
                
                while( l>=0 && r < n && s[l] == s[r]){
                    if( r - l +1 > maxlen){
                        start = l;
                        maxlen = r - l +1;
                    }
                    l--;
                    r++;
                }

                //even lenght  palindrome
                l = i;
                r = i +1 ;
                while( l >=0 && r < n && s[l] == s[r]){
                    if(r-l+1 > maxlen){
                        start = l;
                        maxlen = r - l +1;
                    }
                    l--;
                    r++;
                }
             }
             return s.substr(start,maxlen);
        }
};

