英文链接: https://leetcode.com/problems/roman-to-integer/  
中文链接: https://leetcode-cn.com/problems/roman-to-integer/

```
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < s.size(); ++i) 
        {
            int val = m[s[i]];
            if (i == s.size() - 1 || m[s[i]] >= m[s[i+1]]) 
                res += val;
            else 
                res -= val;
        }

        return res;
    }
};
```



```
class Solution {
public:
    	int romanToInt(string s) {
        	int result = 0;

		for(size_t i = 0; i < s.size(); i++) 
		{
			if(i > 0 && map(s[i]) > map(s[i - 1])) 
			{
				result += (map(s[i]) - 2 * map(s[i - 1]));
			} 
			else
			{
				result += map(s[i]);
			}
		}
		
		return result;
    	}

private:
	inline int map(const char c) 
	{
		switch(c) 
		{
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}
};
```
