class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0); // #people who trust i
        vector<int>outdegree(n+1,0); // #people i  trusts

        for(auto &edge : trust){
            int a = edge[0];
            int b = edge[1];

            outdegree[a]++;
            indegree[b]++;
        }

        for(int person = 1 ; person <= n ; person++){
            if(indegree[person] == n-1 && outdegree[person] == 0){
                return person;
            }
        }
            return -1;
    }
};
