class Solution {
public:
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int n = matrix.size();
        int m = matrix[0].size();


        if(dp[i][j] != -1) return dp[i][j];

        int maxi= 1;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        for(int k = 0 ;k < 4 ; k++){
            int ni = i + dr[k];
            int nj = j + dc[k]; 

            if(ni >=0 && ni < n &&  nj >=0 && nj<m){
                if(matrix[ni][nj] > matrix[i][j]){
                    int len = 1 + f(ni,nj,matrix,dp);
                    maxi = max(maxi,len);
                }
            }
        }
         return dp[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        int ans = 0 ;
        
        for(int i =0 ; i< n ;i++){
            for(int j = 0 ;j < m;j++){
                ans = max(ans,f(i,j,matrix,dp));
            }
        }
        return ans;
    }
};
