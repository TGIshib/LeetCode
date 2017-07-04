class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int c = 0;
		if (board.size() == 0 || board[0].size() == 0) return 0;
		int n = board.size();
		int m = board[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'X') {
					c++;
					if (j > 0 && board[i][j - 1] == 'X') c--;
					if (i > 0 && board[i - 1][j] == 'X') c--;
				}
			}
		}
		return c;
	}
};