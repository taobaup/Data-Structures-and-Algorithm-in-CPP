英文链接: https://leetcode.com/problems/combination-sum/  
中文链接: https://leetcode-cn.com/problems/combination-sum/


```
另写一个递归函数，新加入三个变量 
start记录当前递归到的下标，out保存每次递归的可能结果，result保存所有可能的结果 
每次调用新的递归函数时，target减去数组中当前元素
```

```
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> out;

		dfs(candidates, target, 0, out, res);

		return res;
	}

private:
	void dfs(vector<int>& candidates, int target,
			int start, vector<int> &out, vector<vector<int>> &res) {
		if (target < 0)
		{
			return;
		}
		else if (target == 0)
		{
			res.push_back(out);
			return;
		}
		else
		{
			for (int i = start; i < candidates.size(); ++i)
			{
				out.push_back(candidates[i]);
				// i 不要写成 start 或者 start + 1
				dfs(candidates, target - candidates[i], i, out, res);
				out.pop_back();
			}
		}
	}
};
```
