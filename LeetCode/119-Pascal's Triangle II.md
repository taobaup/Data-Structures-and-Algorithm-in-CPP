英文链接: https://leetcode.com/problems/pascals-triangle-ii/  
中文链接: https://leetcode-cn.com/problems/pascals-triangle-ii/


```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        vector<int> result;

        for (int i = 0; i <= rowIndex; ++i) 
        {
            vector<int> out;
            out.push_back(1);

            if (i == 0) 
            {
                // 不要遗漏这一步
                res.push_back(out);
                result = out;
                continue;
            }

            for (int j = 1; j < i; ++j) 
            {
                out.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }

            out.push_back(1);
            res.push_back(out);

            if (i == rowIndex)
            {
                result = out;
            }
        }
    
        return result;
    }
};
```
