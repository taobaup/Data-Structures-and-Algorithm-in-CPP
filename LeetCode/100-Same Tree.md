英文链接: https://leetcode.com/problems/same-tree/  
中文链接: https://leetcode-cn.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;

        if(p == NULL && q != NULL)
            return false;

        if(p != NULL && q == NULL)
            return false;

        if(p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

使用栈

```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<const TreeNode*> s1, s2;

        if(p != NULL)
            s1.push(p);
        if(q != NULL)
            s2.push(q);

        while(!s1.empty() && !s2.empty())
        {
            const TreeNode *t1 = s1.top();
            s1.pop();
            const TreeNode *t2 = s2.top();
            s2.pop();

            if(t1->val != t2->val)
                return false;

            // 不要在判断完 left 非空以后写成 push right
            if(t1->left != NULL)
                s1.push(t1->left);
            if(t2->left != NULL)
                s2.push(t2->left);

            if(s1.size() != s2.size())
                return false;

            if(t1->right != NULL)
                s1.push(t1->right);
            if(t2->right != NULL)
                s2.push(t2->right);

            if(s1.size() != s2.size())
                return false;
        }

        // return s1.size() == s2.size();
        return s1.empty() && s2.empty();
    }
};
```

使用队列

```
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<const TreeNode*> s1, s2;

        if(p != NULL)
            s1.push(p);
        if(q != NULL)
            s2.push(q);

        while(!s1.empty() && !s2.empty())
        {
            const TreeNode *t1 = s1.front();
            s1.pop();
            const TreeNode *t2 = s2.front();
            s2.pop();

            if(t1->val != t2->val)
                return false;

            // 不要在判断完 left 非空以后写成 push right
            if(t1->left != NULL)
                s1.push(t1->left);
            if(t2->left != NULL)
                s2.push(t2->left);

            if(s1.size() != s2.size())
                return false;

            if(t1->right != NULL)
                s1.push(t1->right);
            if(t2->right != NULL)
                s2.push(t2->right);

            if(s1.size() != s2.size())
                return false;
        }

        // return s1.size() == s2.size();
        return s1.empty() && s2.empty();
    }
};
```
