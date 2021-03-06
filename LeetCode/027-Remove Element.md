英文链接: https://leetcode.com/problems/remove-element/  
中文链接: https://leetcode-cn.com/problems/remove-element/


遍历数组, 将不等于val的值放回原数组   
注意此前已经++index;所以最后return index;即可, 不需要return index + 1; 

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int index = 0;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != val)
			{
				nums[index] = nums[i];
				++index;
			}
		}

		return index;
	}
};
```


每找到一个等于val的元素, 将数组末尾的数移到该位置   
这样可以保证如果没有重复就没有写操作 
```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = nums.size();

		for (int i = 0; i < len; ++i)
		{
			if (nums[i] == val)
			{
				nums[i] = nums[len - 1];
				--len;
				--i;
			}
		}

		return len;
	}
};
```


借助STL也可以AC, 但不推荐

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0)
			return 0;

		return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
	}
};
```

```
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{
			if (*it == val)
			{
				it = nums.erase(it);
				--it;
			}
		}

		return nums.size();
	}
};
```
