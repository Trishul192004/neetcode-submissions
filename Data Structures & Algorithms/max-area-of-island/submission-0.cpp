class Solution {
public:
    int dfs(vector<vector<int>>&grid,int row,int col){

        //out of bound/water
        if(row < 0 || col <0 || row>= grid.size() || col >= grid[0].size() || grid[row][col] == 0){
            return 0;
        }

        //marking cell visited i.e 1 land  as visted making
        grid[row][col] = 0;

        int area = 1 ;

        area += dfs(grid,row+1,col);
        area += dfs(grid,row -1 ,col);
        area += dfs(grid,row,col-1);
        area += dfs(grid,row,col+1);

        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0 ;

        for(int i =0 ;i < grid.size();i++){
            for(int j = 0 ; j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid,i,j);
                    maxArea = max(maxArea,area);
                }
            }
        }

        return maxArea;
    }
};
