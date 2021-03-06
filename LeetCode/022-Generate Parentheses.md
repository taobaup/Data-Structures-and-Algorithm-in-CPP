英文链接: https://leetcode.com/problems/generate-parentheses/  
中文链接: https://leetcode-cn.com/problems/generate-parentheses/
 

>考虑递归求解   
字符串只有’(‘和’)’两种字符，而且最终结果必定是3个’(‘，3个’)’   
定义变量left和right表示左右括号的剩余个数   
分为3种情况   
1: left>right   
即出现’)(‘这样的非法串，直接返回，不继续处理   
2: left和right都为0   
则此时生成的字符串已有n个左括号和n个右括号   
且字符串合法，则存入结果中后返回   
3: 以上两种情况都不满足，   
若left>0，则调用递归函数，注意left-1   
若right>0，也调用递归函数，注意right-1


```
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;

		dfs(res, n, n, "");

		return res;
	}

private:
	void dfs(vector<string> &res, int left, int right, string str)
	{
		if (left < 0 || right < 0 || left > right)
		{
			return;
		}

		if (left == 0 && right == 0)
		{
			res.push_back(str);
			return;
		}
		else
		{
			// not > 1
			// if (left > 0)
			// {
			dfs(res, left - 1, right, str + '(');
			// }
			// not else if (right > 0)
			// if (right > 0)
			// {
			dfs(res, left, right - 1, str + ')');
			// }

			return;
		}
	}
};
```

```
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;

		dfs(res, n, n, "");

		return res;
	}

private:
	void dfs(vector<string> &res, int left, int right, string str)
	{
		if (left < 0 || right < 0 || left > right)
		{
			return;
		}

		if (left == 0 && right == 0)
		{
			res.push_back(str);
			return;
		}
		else
		{
			
		    	if (left > 0)
			{
                	    str.push_back('(');
			    dfs(res, left - 1, right, str);
                            str.pop_back();
			}
			
			if (right > 0)
			{
                            str.push_back(')');
			    dfs(res, left, right - 1, str);
                            str.pop_back();
			}

			return;
		}
	}
};
```


思路同上, 注意不要遗漏str.size() == n * 2   
第2步的判断right < left不要写错
```
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string str;

		dfs(res, n, 0, 0, str);

		return res;
	}

private:
	void dfs(vector<string>&res, int n, int left, int right, string str)
	{
		if (left < n)
		{
			str.push_back('(');
			dfs(res, n, left + 1, right, str);
			str.pop_back();
		}

		if (right < left)
		{
			str.push_back(')');
			dfs(res, n, left, right + 1, str);
			str.pop_back();
		}

		// 也可移到函数开头
		if (str.size() == n * 2)
		{
			res.push_back(str);
		}

		return;
	}
};
```
