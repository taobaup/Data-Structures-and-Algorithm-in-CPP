英文链接: https://leetcode.com/problems/binary-tree-maximum-path-sum/  
中文链接: https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

```
// Definition for a binary tree node.
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
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		helper(root, res);
		
		return res;
	}

private:
	int helper(TreeNode *node, int &res) 
	{
		if (node == NULL) 
		{
			return 0;
		}

		int left = max(helper(node->left, res), 0);
		int right = max(helper(node->right, res), 0);	
		res = max(res, left + right + node->val);
		
		return max(left, right) + node->val;
	}
};
```
