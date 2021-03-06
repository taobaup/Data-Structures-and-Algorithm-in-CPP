英文链接: https://leetcode.com/problems/symmetric-tree/  
中文链接: https://leetcode-cn.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) 
        {
            return true;
        }

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) 
    {
        if (left == NULL && right == NULL) 
        {
            return true;
        }

        if (left != NULL && right == NULL) 
        {
            return false;
        }
        else if (left == NULL && right != NULL)
        {
            return false;
        }
        else if (left->val != right->val) 
        {
            return false;
        }

        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    
};
```


```
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty()) 
        {
            TreeNode *node1 = q1.front();
            TreeNode *node2 = q2.front();
            q1.pop();
            q2.pop();

            if (node1 != NULL && node2 == NULL) 
            {
                return false;
            }
            else if (node1 == NULL && node2 != NULL) 
            {
                return false;
            }

            if (node1 != NULL) 
            {
                if (node1->val != node2->val) 
                {
                    return false;
                }

                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
        }

        return true;
    }
};
```
