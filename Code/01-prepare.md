#### Memmove

有问题的代码
```
void *memmove(void *dest, const void *src, size_t n)
{
	char *p1 = dest;
	char *p2 = src;
	while (*p2 != \0)
		*p1++ = *p2++;
	return p1;
}
```

#### C语言的陷阱
* 内存重叠的处理 
* 临时变量太多或者没安全释放 
* 没有测试内存越界 
* 指针操作不熟悉

内存是否重叠？

```
void *memmove(void *dest, const void *src, size_t n)
{
	char *p1 = (char *)dest;
	const char *p2 = (const char *)src;
	if (p2 < p1) 
	{
		p2 += n;
		p1 += n;

		while (n-- != 0)
		{
			*--p1 = *--p2;
		}	
	}
	else 
	{
		while (n-- != 0)
		{
			*p1++ = *p2++;
		}
	}
	
	return p1;
}
```

LeetCode 226. Invert Binary Tree
```
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

```
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}

		TreeNode *tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return root;
	}
};
```
```
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
		{
			return NULL;
		}

		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode *node = q.front();
			q.pop();

			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;

			if (node->left)
			{
				q.push(node->left);
			}

			if (node->right)
			{
				q.push(node->right);
			}
		}

		return root;
	}
};
```




#### 全排列
>字符串“abc”的全排列：
abc acb bac bca cba cab

* 无重复的全排列
```
#include<iostream>  
#include<assert.h>  

using namespace std;

void Permutation(char *pStr, char *pBegin)
{
	assert(pStr && pBegin);

	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
		{
			swap(*pCh, *pBegin);
			Permutation(pStr, pBegin + 1);
			swap(*pCh, *pBegin);
		}
	}
}

int main()
{
	char str[] = "abc";
	Permutation(str, str);

	return 0;
}
```

```
#include<iostream>  
#include<string>

using namespace std;

void permutationRecursion(string &s, int start)
{
	if (start == s.size())
	{
		cout << s << endl;
		return;
	}

	// 注意这里是 i = start; 而不是 i = 0;
	for (int i = start; i < s.size(); ++i)
	{
		swap(s[i], s[start]);
		permutationRecursion(s, start + 1);
		swap(s[i], s[start]);
	}
}

int main()
{
	string s = "abc";
	permutationRecursion(s, 0);

	return 0;
}
```

LeetCode 46. Permutations
```
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		permute(res, nums, 0);

		return res;
	}

	// 注意 res 要用引用
	void permute(vector<vector<int>>& res, vector<int>& nums, int start)
	{
		if (start >= nums.size())
		{
			res.push_back(nums);
		}

		for (int i = start; i < nums.size(); ++i)
		{
			swap(nums[i], nums[start]);
			permute(res, nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
};
```

>组合问题  
题目：输入一个字符串，输出该字符串中字符的所有组合。
举个例子，如果输入abc，它的组合有a、b、c、ab、ac、bc、abc。  
对于每一个元素，可以有选与不选两个状态，因而从排列第一个元素开始，不选它然后求解 S[2:n]的全子集；选它然后求解S[2:n]的全子集，两个结果的合并就是整个集合的全子集了。


LeetCode 47. Permutations II
```
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		permute(res, nums, 0);

		return res;
	}

	bool findRepeat(vector<int> &nums, int start, int end)
	{
		bool find = false;
		for (int i = start; i < end; ++i)
		{
			if (nums[i] == nums[end])
			{
				find = true;
				break;
			}
		}

		return find;
	}

	//  注意 vector<vector<int>>& res 要用引用
	void permute(vector<vector<int>>& res, vector<int> &nums, int start)
	{
		if (start >= nums.size())
		{
			res.push_back(nums);
		}

		for (int i = start; i < nums.size(); ++i)
		{
			if (findRepeat(nums, start, i))
			{
				continue;
			}	

			swap(nums[i], nums[start]);
			permute(res, nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
};
```
