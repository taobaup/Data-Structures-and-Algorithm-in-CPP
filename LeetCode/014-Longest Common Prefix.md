英文链接: https://leetcode.com/problems/longest-common-prefix/  
中文链接: https://leetcode-cn.com/problems/longest-common-prefix/

```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) 
            return "";

        string res = "";
        for (int j = 0; j < strs[0].size(); ++j) 
        {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) 
            {
                if (j >= strs[i].size() || strs[i][j] != c) 
                {
                    return res;
                }
            }
            
            res.push_back(c);
        }
    
        return res;
    }
};
```



```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) 
            return "";

        for (int j = 0; j < strs[0].size(); ++j) 
        {
            for (int i = 0; i < strs.size() - 1; ++i) 
            {
                if (j >= strs[i].size() || j >= strs[i + 1].size() || strs[i][j] != strs[i + 1][j]) 
                {
                    return strs[i].substr(0, j);
                }   
            }
        }

        return strs[0];
    }
};
```
