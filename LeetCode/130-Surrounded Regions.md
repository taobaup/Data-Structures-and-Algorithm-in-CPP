英文链接: https://leetcode.com/problems/surrounded-regions/  
中文链接: https://leetcode-cn.com/problems/surrounded-regions/

```
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (i == 0 || i == board.size() - 1
					|| j == 0 || j == board[0].size() - 1)
				{
					if (board[i][j] == 'O')
					{
						dfs(board, i, j);
					}
				}
			}
		}

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				else if (board[i][j] == '$')
				{
					board[i][j] = 'O';
				}
			}
		}
	}

private:
	void dfs(vector<vector<char>>& board, int i, int j)
	{
		if (board[i][j] == 'O')
		{
			board[i][j] = '$';

			if (i > 0 && board[i - 1][j] == 'O')
			{
				dfs(board, i - 1, j);
			}

			if (i < board.size() - 1 && board[i + 1][j] == 'O')
			{
				dfs(board, i + 1, j);
			}
	
			if (j > 0 && board[i][j - 1] == 'O')
			{
				dfs(board, i, j - 1);
			}

			// j < board[i].size() - 1 也是一样的
			if (j < board[0].size() - 1 && board[i][j + 1] == 'O')
			{
				dfs(board, i, j + 1);
			}
		}
	}
};
```




```
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (i == 0 || i == board.size() - 1
					|| j == 0 || j == board[0].size() - 1)
				{
					if (board[i][j] == 'O')
					{
						bfs(board, i, j);
					}
				}
			}
		}

		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				else if (board[i][j] == '$')
				{
					board[i][j] = 'O';
				}
			}
		}
	}

private:
	void bfs(vector<vector<char>>& board, int i, int j)
	{
		board[i][j] = '$';
		queue<pair<int, int>> q;
		q.push({ i, j });

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x > 0 && board[x - 1][y] == 'O')
			{
				board[x - 1][y] = '$';
				q.push({ x - 1, y });
			}
			
			if (x < board.size() - 1 && board[x + 1][y] == 'O')
			{
				board[x + 1][y] = '$';
				q.push({ x + 1, y });
			}

			if (y > 0 && board[x][y - 1] == 'O')
			{
				board[x][y - 1] = '$';
				q.push({ x, y - 1 });
			}

			if (y < board[0].size() - 1 && board[x][y + 1] == 'O')
			{
				board[x][y + 1] = '$';
				q.push({ x, y + 1});
			}
		}
	}
};
```
