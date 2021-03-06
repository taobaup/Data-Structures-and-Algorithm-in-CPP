英文链接: https://leetcode.com/problems/minimum-path-sum/  
中文链接: https://leetcode-cn.com/problems/minimum-path-sum/

动态规划，状态转移方程为  
dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];

```
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const int m = grid.size();
		const int n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; ++i)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}

		for (int j = 1; j < n; ++j)
		{
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}

		// not i<=m
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}

		return dp[m - 1][n - 1];
	}
};
```

动态规划+滚动数组
```
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		const int m = grid.size();
		const int n = grid[0].size();

		vector<int> dp(n, 0);

		dp[0] = grid[0][0];
		for (int j = 1; j < n; ++j)
		{
			dp[j] = dp[j - 1] + grid[0][j];
		}

		// not i<=m
		for (int i = 1; i < m; ++i)
		{
			// 注意i从0而非1开始
			for (int j = 0; j < n; ++j)
			{
				if (j == 0)
				{
					dp[j] = dp[j] + grid[i][0];
				}
				else
				{
					dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
				}
			}
		}

		return dp[n - 1];
	}
};
```
