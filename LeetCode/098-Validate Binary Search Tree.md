英文链接: https://leetcode.com/problems/validate-binary-search-tree/  
中文链接: https://leetcode-cn.com/problems/validate-binary-search-tree/


> 给定一个二叉树，判断其是否是一个有效的二叉搜索树。

>假设一个二叉搜索树具有如下特征：  
节点的左子树只包含小于当前节点的数。  
节点的右子树只包含大于当前节点的数。  
所有左子树和右子树自身必须也是二叉搜索树。

一般的二叉搜索树是左<=根<右，而这道题设定为左<根<右，那么就可以用中序遍历来做

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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode *root, long mn, long mx) 
    {
        if (root == NULL) 
            return true;

        if (root->val <= mn || root->val >= mx) 
            return false;

        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};
```

```
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> result;

        inorder(result, root);

        bool isValidBST  = true;
        if(result.size() > 1)
        {
            for(int i = 0; i < result.size() - 1; ++i)
            {
                if(result[i] >= result[i + 1])
                    isValidBST = false;
            }
        }
       
        return isValidBST;
    }

    void inorder(vector<int> &result, TreeNode *root) {
        if(root == NULL)
            return;

        inorder(result, root->left);
        result.push_back(root->val);
        inorder(result, root->right);
    }
};
```

```

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> result;

        result = inorderTraversal(root);

        bool isValidBST  = true;
        if(result.size() > 1)
        {
            for(int i = 0; i < result.size() - 1; ++i)
            {
                if(result[i] >= result[i + 1])
                    isValidBST = false;
            }
        }

        return isValidBST;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        if(root == NULL)
            return res;

        stack<const TreeNode*> s;
        const TreeNode *p = root;

        while(!s.empty() || p != NULL)
        {
            if(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
            else
            {
                const TreeNode *t = s.top();
                s.pop();

                res.push_back(t->val);
                p = t->right;
            }
        }

        return res;
    }
};

```
