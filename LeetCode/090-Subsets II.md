英文链接: https://leetcode.com/problems/subsets-ii/  
中文链接: https://leetcode-cn.com/problems/subsets-ii/

```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) 
            return res;
        
        vector<int> out;
        sort(nums.begin(), nums.end());
        getSubsets(nums, 0, out, res);

        return res;
    }

    void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res) 
    {
        res.push_back(out);

        for (int i = pos; i < nums.size(); ++i) 
        {
            out.push_back(nums[i]);
            getSubsets(nums, i + 1, out, res);
            out.pop_back();

            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                ++i;
        }
    }
};
```
