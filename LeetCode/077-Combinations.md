英文链接: https://leetcode.com/problems/combinations/  
中文链接: https://leetcode-cn.com/problems/combinations/


```
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        helper(1, n, k, out, res);

        return res;
    }

public:
    void helper(int level, int n, int k, vector<int> &out, vector<vector<int>> &res)
    {
        if(out.size() == k)
            res.push_back(out);

        for(int i = level; i <= n; ++i)
        {
            out.push_back(i);
            // 不要写成 helper(level + 1, n, k, out, res);
            helper(i + 1, n, k, out, res);
            out.pop_back();
        }
    }
};
```
