class Solution {

private:

    int bfs(int row, int col,
            vector<vector<int>>& vis,
            vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        q.push({row, col});

        vis[row][col] = 1;

        int area = 1;

        int delr[4] = {-1, 0, 1, 0};
        int delc[4] = {0, 1, 0, -1};

        while (!q.empty()) {

            row = q.front().first;
            col = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {

                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if (nrow >= 0 && ncol >= 0 &&
                    nrow < n && ncol < m &&
                    grid[nrow][ncol] == 1 &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;

                    area++;

                    q.push({nrow, ncol});
                }
            }
        }

        return area;
    }

public:

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis
        (n, vector<int>(m, 0));

        int maxArea = 0;

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < m; col++) {

                if (!vis[row][col] &&
                    grid[row][col] == 1) {

                    int area =
                    bfs(row, col, vis, grid);

                    maxArea =
                    max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};