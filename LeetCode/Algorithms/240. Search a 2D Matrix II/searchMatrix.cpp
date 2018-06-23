1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        	return false;

        const int row = matrix.size();
        const int column = matrix[0].size();

        int i = 0;
        int j = column - 1;
        while(i <= row - 1 && j >= 0)
        {
        	if(target == matrix[i][j])
        		return true;
        	else if(target < matrix[i][j])
        		--j;
        	else
        		++i;
        }

        return false;
    }
};




2)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
        	return false;

        const int row = matrix.size();
        const int column = matrix[0].size();

        int i = row - 1;
        int j = 0;
        while(i >= 0 && j <= column - 1)
        {
        	if(target == matrix[i][j])
        		return true;
        	else if(target < matrix[i][j])
        		--i;
        	else
        		++j;
        }

        return false;
    }
};
