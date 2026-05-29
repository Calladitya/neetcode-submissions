class Solution {

    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if(nrow >= 0 &&
                   nrow < n &&
                   ncol >= 0 &&
                   ncol < m &&
                   grid[nrow][ncol] == 2147483647)
                {
                    grid[nrow][ncol] = grid[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }

        bfs(q, grid);
    }
};
