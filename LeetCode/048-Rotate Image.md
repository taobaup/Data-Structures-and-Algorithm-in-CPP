英文链接: https://leetcode.com/problems/rotate-image/  
中文链接: https://leetcode-cn.com/problems/rotate-image/

先将数组沿行的中线对折   
1 2         
3 4 翻转为 

3 4  
1 2

再沿主对角线翻转   
3 4          
1 2 翻转为 

3 1  
4 2

```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();

        for(int i = 0; i < n / 2; ++i)
        {
        	for(int j = 0; j < n; ++j)
        	{
        		swap(matrix[i][j], matrix[n - 1 - i][j]);
        	}
        }

        for(int i = 0; i < n; ++i)
        {
        	for(int j = 0; j < i; ++j)
        	{
        		// not swap(matrix[i][j], matrix[i][j]);
        		swap(matrix[i][j], matrix[j][i]);
        	}
        }
    }
};
```
