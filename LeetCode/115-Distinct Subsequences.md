英文链接: https://leetcode.com/problems/distinct-subsequences/  
中文链接: https://leetcode-cn.com/problems/distinct-subsequences/


```
用删除(也可以不删除)字符的方法将字符串s变换到字符串t，一共有多少种变换方法 
动态规划，定义dp[i][j]为字符串s变换到t的可变换次数 

1. 如果s[i-1]!=t[j-1]，那么dp[i][j] = dp[i-1][j]，s[i-1]只能删除 

2. 如果s[i-1]==t[j-1]，那么dp[i][j] = dp[i-1][j-1] + dp[i-1][j]，s[i-1]可以保留也可以删除

所以变换次数等于保留这个字母的变换次数加上删除这个字母的变换次数 

dp[i][0] = 0，因任意非空字符串变换为空串只有1个方法  
dp[1][1]可能用到dp[0][0]，所以dp[0][0] = 1
```


```
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.empty() || t.empty())
        {
            return 0;
        }
        if (s.size() < t.size())
        {
            return 0;
        }

        const int m = s.size();
        const int n = t.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
```
