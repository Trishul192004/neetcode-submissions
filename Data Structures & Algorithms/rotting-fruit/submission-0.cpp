class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;
        int time = 0;

        //put all rotten oranges into q and count fresh oranges
        for(int r= 0 ; r < rows; r++){
            for(int c =0 ; c < cols;c++){

                if(grid[r][c] == 1) fresh++;

                if(grid[r][c] == 2) q.push({r,c});
            }
        }

        //directions right,left down up
        int directions[4][2] ={
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };

        //bfs
        while(!q.empty() && fresh > 0){
            //number of oranges  currently rotten these oragnes belong to current minute

            int size = q.size();
            for(int i =0 ; i < size ; i++){
                auto[r,c] = q.front();
                q.pop();

                for(auto &dir : directions){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr < 0 || nr >= rows || nc<0 || nc >= cols)continue;

                    //only fresh oranges can be rotten
                    if(grid[nr][nc] != 1)continue;

                    //make fresh oranges rotten
                    grid[nr][nc] = 2;

                    q.push({nr,nc});//add only rotten orange to queue

                    fresh--; //fresh orange decres.
                }
            }
            time++; //1m passed
        }

        //if no fresh oranges remain r time elese - 1
        return (fresh ==0)? time : -1;
    }
};
