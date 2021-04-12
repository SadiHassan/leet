class Solution {
public:
    bool flag;
    bool check_single_row_or_col(vector<char>& s){
        map<char, bool> m;
        for(auto ch: s)
            if(m.find(ch) != m.end())
                return false;
            else
                m[ch] = true;
        return true;
    }
    
    bool check_row(vector<vector<char>>& board){
        for(int i = 0; i < board.size(); i++){
            if( !check_single_row_or_col(board[i]) )
                return false;
        }
        return true;
    }
    
    vector<char> make_column(vector<vector<char>>& board, int col){
        vector<char> res;
        for(int i = 0; i < board.size(); i++)
            res.push_back(board[i][col]);
        return res;
    }
    
    bool check_col(vector<vector<char>>& board){
        for(int j = 0; j < board[0].size(); j++){
            vector<char> col_str = make_column(board, j);
            if( !check_single_row_or_col(col_str) )
                return false;
        }
        return true;
    }
    
    bool check_single_box(vector<vector<char>>& board, int r1, int c1, int r2, int c2){
        map<char, bool> m;
        for(int i = r1; i < r2; i++)
            for(int j = c1; j < c2; j++)
                if(m.find(board[i][j]) != m.end())
                    return false;
                else
                    m[ board[i][j] ] = true;
        return true;
    }
    
    bool check_boxes(vector<vector<char>>& board){
        
        for(int i = 0; i < board.size(); i += 3)
            for(int j = 0; j < board[i].size(); j += 3){
                int r1 = i;
                int c1 = j;
                int r2 = i + 3;
                int c2 = j + 3;
                
                if( !check_single_box(board, r1, c1, r2, c2) )
                    return false;
            }
        return true;
    }
    
    void rec(vector<vector<char>>& board, int rem, int row, int col){
        if(rem == 0){
            if(check_row(board) && check_col(board) && check_boxes(board)){
                flag = true;
            }
            return;
        }
        for(int i = row; i < board.size(); i++){
            for(int j = col; j < board[i].size(); j++){
                if(board[i][j] == '.'){
                    for(int v = 1; v <= 9; v++){
                        board[i][j] = 48 + v;
                        rec(board, rem - 1, row, col + 1);
                        if(flag) return;
                    }
                     board[i][j] = '.';
                }
            }
        }
            
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        int rem = 0;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] == '.') rem++;
        if(rem == 0) return;
        flag = false;
        rec(board, rem, 0, 0);
    }
};