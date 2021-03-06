英文链接: https://leetcode.com/problems/unique-binary-search-trees-ii/  
中文链接: https://leetcode-cn.com/problems/unique-binary-search-trees-ii/


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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> res;

        if (n == 0) 
            return res;
        
        res = *generateTreesDFS(1, n);
        return res;
    }

private:
    vector<TreeNode*> *generateTreesDFS(int start, int end) 
    {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) 
        {
            subTree->push_back(NULL);
        }
        else 
        {
            for (int i = start; i <= end; ++i) 
            {
                vector<TreeNode*> *leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> *rightSubTree = generateTreesDFS(i + 1, end);

                for (int j = 0; j < leftSubTree->size(); ++j) 
                {
                    for (int k = 0; k < rightSubTree->size(); ++k) 
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = (*leftSubTree)[j];
                        node->right = (*rightSubTree)[k];

                        subTree->push_back(node);
                    }
                }
            }
        }

        return subTree;
    }
};
```
