英文链接: https://leetcode.com/problems/spiral-matrix-ii/  
中文链接: https://leetcode-cn.com/problems/spiral-matrix-ii/


从左到右，从上到下，从右到左，从下到上依次遍历   
同时赋予一个自增的变量值   
注意边界的判断

```
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> result(n, vector<int>(n));

		int begin = 0, end = n - 1;
		int num = 1;

		while (begin < end)
		{
			for (int j = begin; j < end; ++j)
				result[begin][j] = num++;
			for (int i = begin; i < end; ++i)
				result[i][end] = num++;
			for (int j = end; j > begin; --j)
				result[end][j] = num++;
			for (int i = end; i > begin; --i)
				result[i][begin] = num++;
			++begin;
			--end;
		}

		if (begin == end)
			result[begin][begin] = num;

		return result;
	}
};
```
