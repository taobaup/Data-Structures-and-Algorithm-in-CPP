英文链接: https://leetcode.com/problems/container-with-most-water/   
中文链接: https://leetcode-cn.com/problems/container-with-most-water/


```
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = INT_MIN;

		int start = 0;
		int end = height.size() - 1;

		while (start < end)
		{
			int h = min(height[start], height[end]);
			res = max(res, h * (end - start));

			if (height[start] < height[end])
			{
				++start;
			}
			else
			{
				--end;
			}
		}

		return res;
	}
};
```

```
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = INT_MIN;

		int start = 0;
		int end = height.size() - 1;

		while (start < end)
		{
			int h = min(height[start], height[end]);
			res = max(res, h * (end - start));

			while (start < end && height[start] == h)
			{
				++start;
			}

			while (start < end && height[end] == h)
			{
				--end;
			}
		}

		return res;
	}
};
```
