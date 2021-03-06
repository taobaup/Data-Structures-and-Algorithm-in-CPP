英文链接: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/  
中文链接: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

最多可以完成两笔交易

```
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();

		// 不要遗漏这个判断
		if (n < 2)
		{
			return 0;
		}

		vector<int> f(n, 0);
		vector<int> g(n, 0);

		int front_min = prices[0];
		for (int i = 1; i < n; ++i)
		{
			front_min = min(front_min, prices[i]);
			// 而不是 f[i] = max(f[i], prices[i] - front_min);
			f[i] = max(f[i - 1], prices[i] - front_min);
		}

		int back_max = prices[n - 1];
		for (int i = n - 2; i >= 0; --i)
		{
			back_max = max(back_max, prices[i]);
			g[i] = max(g[i], back_max - prices[i]);
		}

		int profit = 0;
		for (int i = 0; i < n; ++i)
		{
			profit = max(profit, f[i] + g[i]);
		}

		return profit;
	}
};
```
