英文链接: https://leetcode.com/problems/word-search/  
中文链接: https://leetcode-cn.com/problems/word-search/



```
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		const int m = board.size();
		const int n = board[0].size();

		if (m <= 0 || n <= 0)
		{
			return false;
		}

		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (search(board, word, 0, i, j, visited))
				{
					return true;
				}
			}
		}

		return false;
	}

private:
	bool search(vector<vector<char>>& board, string word, int level,
		 int i, int j, vector<vector<bool>>& visited)
	{
		if (level == word.size())
		{
			return true;
		}

		const int m = board.size();
		const int n = board[0].size();
		if (i < 0 || j < 0 || i >= m || j >= n)
		{
			return false;
		}

		// || 而不是 &&
		if (visited[i][j] || board[i][j] != word[level])
		{
			return false;
		}

		visited[i][j] = true;

		bool res = search(board, word, level + 1, i - 1, j, visited)
			|| search(board, word, level + 1, i + 1, j, visited)
			|| search(board, word, level + 1, i, j - 1, visited)
			|| search(board, word, level + 1, i, j + 1, visited);

		visited[i][j] = false;

		return res;
	}
};
```


```
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		const int m = board.size();
		const int n = board[0].size();

		if (m <= 0 || n <= 0)
		{
			return false;
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (search(board, word, 0, i, j))
				{
					return true;
				}
			}
		}

		return false;
	}

private:
	bool search(vector<vector<char>>& board, string word, int level, int i, int j)
	{
		if (level == word.size())
		{
			return true;
		}

		const int m = board.size();
		const int n = board[0].size();
		if (i < 0 || j < 0 || i >= m || j >= n)
		{
			return false;
		}

		if (board[i][j] != word[level])
		{
			return false;
		}

		char c = board[i][j];
		// '' 而不是 ""
		board[i][j] = '#';

		bool res = search(board, word, level + 1, i - 1, j)
			|| search(board, word, level + 1, i + 1, j)
			|| search(board, word, level + 1, i, j - 1)
			|| search(board, word, level + 1, i, j + 1);

		board[i][j] = c;

		return res;
	}
};
```
