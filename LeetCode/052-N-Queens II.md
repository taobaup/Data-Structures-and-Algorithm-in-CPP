英文链接: https://leetcode.com/problems/n-queens-ii/  
中文链接: https://leetcode-cn.com/problems/n-queens-ii/


统计N皇后的解的个数

N-Queens的简化版，直接使用一个计数变量即可，无需保存结果的值

```
class Solution {
public:
	int totalNQueens(int n) {
		vector<int> pos(n, -1);

		int res = 0;
		dfs(pos, 0, res);

		return res;
	}

private:
	// res 要用引用
	void dfs(vector<int> &pos, int row, int &res)
	{
		int n = pos.size();
		if (row == n)
		{
			++res;
		}
		else
		{
			for (int j = 0; j < n; ++j)
			{
				if (isValid(pos, row, j))
				{
					pos[row] = j;
					dfs(pos, row + 1, res);
					pos[row] = -1;
				}
			}
		}
	}

	bool isValid(vector<int> &pos, int row, int j)
	{
		// 不要写成两重循环
		for (int i = 0; i < row; ++i)
		{
			if (pos[i] == j || abs(j - pos[i]) == abs(row - i))
			{
				return false;
			}
		}

		return true;
	}
};
```
