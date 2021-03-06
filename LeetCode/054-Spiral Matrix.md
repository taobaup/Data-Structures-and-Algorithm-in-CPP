英文链接: https://leetcode.com/problems/spiral-matrix/  
中文链接: https://leetcode-cn.com/problems/spiral-matrix/


从左到右，从上到下，从右到左，从下到上依次遍历即可，注意边界的判断

```
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;

		if (matrix.empty())
			return result;

		int beginX = 0, endX = matrix.size() - 1;
		int beginY = 0, endY = matrix[0].size() - 1;

		while (true)
		{
			for (int j = beginY; j <= endY; ++j)
				result.push_back(matrix[beginX][j]);
			if (++beginX > endX)
				break;

			for (int i = beginX; i <= endX; ++i)
				result.push_back(matrix[i][endY]);
			if (--endY < beginY)
				break;

			for (int j = endY; j >= beginY; --j)
				result.push_back(matrix[endX][j]);
			if (--endX < beginX)
				break;

			for (int i = endX; i >= beginX; --i)
				result.push_back(matrix[i][beginY]);
			if (++beginY > endY)
				break;
		}

		return result;
	}
};
```
```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if (matrix.empty())
            return result;

        int beginX = 0, endX = matrix.size() - 1;
        int beginY = 0, endY = matrix[0].size() - 1;

        int begin = 0;
        int end = matrix.size() - 1;
        while (begin <= end)
        {
            for (int j = beginY; j <= endY; ++j)
                result.push_back(matrix[beginX][j]);
            if (++beginX > endX)
                break;

            for (int i = beginX; i <= endX; ++i)
                result.push_back(matrix[i][endY]);
            if (--endY < beginY)
                break;

            for (int j = endY; j >= beginY; --j)
                result.push_back(matrix[endX][j]);
            if (--endX < beginX)
                break;

            for (int i = endX; i >= beginX; --i)
                result.push_back(matrix[i][beginY]);
            if (++beginY > endY)
                break;

            ++begin;
            --end;
        }

        return result;
    }
};
```
