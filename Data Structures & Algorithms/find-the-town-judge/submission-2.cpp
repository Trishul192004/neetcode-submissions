class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        // inDegree[i] = how many people trust i
        vector<int> inDegree(n + 1, 0);

        // outDegree[i] = how many people i trusts
        vector<int> outDegree(n + 1, 0);

        // Process every trust relationship
        for(auto &edge : trust) {

            int a = edge[0];
            int b = edge[1];

            // a trusts b
            outDegree[a]++;
            inDegree[b]++;
        }

        // Find the person who satisfies:
        // 1. Everybody else trusts them
        // 2. They trust nobody
        for(int person = 1; person <= n; person++) {

            if(inDegree[person] == n - 1 &&
               outDegree[person] == 0) {

                return person;
            }
        }

        // No town judge exists
        return -1;
    }
};