class Solution {
   public:
    void dfs(int r, int  c ,vector<vector<char>>& board, int n , int m ){
        board[r][c] = '#';
        int dr[] = {-1 ,0 , 1, 0};
        int dc[] = {0 , 1 , 0 , -1};

        for(int i = 0 ; i < 4 ; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc] ==
             'O'){
               dfs(nr , nc, board , n , m );
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(i , 0 ,board , n , m );
            }

            if(board[i][m-1] == 'O'){
                dfs(i , m-1 , board , n , m);
            }
        }

        for (int j = 0; j < m; j++){
            if(board[0][j] == 'O'){
                dfs(0 , j , board , n , m);
            }

            if(board[n-1][j] == 'O'){
                dfs(n-1 , j , board , n , m);
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j <m ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }

    }


};
