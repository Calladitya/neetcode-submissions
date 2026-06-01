class Solution {
private:

    void bfs(int row, int col, vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> region;

        q.push({row,col});
        board[row][col] = '#';

        bool touchesBoundary = false;

        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            region.push_back({r,c});

            if(r == 0 || c == 0 ||
               r == n-1 || c == m-1)
            {
                touchesBoundary = true;
            }

            for(int i=0;i<4;i++)
            {
                int nr = r + delr[i];
                int nc = c + delc[i];

                if(nr >= 0 &&
                   nr < n &&
                   nc >= 0 &&
                   nc < m &&
                   board[nr][nc] == 'O')
                {
                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
        }

        if(touchesBoundary)
        {
            for(auto &it : region)
            {
                board[it.first][it.second] = 'O';
            }
        }
        else
        {
            for(auto &it : region)
            {
                board[it.first][it.second] = 'X';
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        for(int row=0; row<n; row++)
        {
            for(int col=0; col<m; col++)
            {
                if(board[row][col] == 'O')
                {
                    bfs(row,col,board);
                }
            }
        }
    }
};
