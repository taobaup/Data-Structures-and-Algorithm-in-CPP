
英文链接: https://leetcode.com/problems/gray-code/  
中文链接: https://leetcode-cn.com/problems/gray-code/


```
Int    Gray Code    Binary
 0  　　  000        000
 1  　　  001        001
 2   　 　011        010
 3   　 　010        011
 4   　 　110        100
 5   　 　111        101
 6   　 　101        110
 7   　　 100        111
```

Convertion of gray code and binary 格雷码和二进制数之间的转换 

```
unsigned int binaryToGray(unsigned int num)
{
    return (num >> 1) ^ num;
}
 

unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }

    return num;
}
```

```
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;

        for(int i = 0; i < pow(2, n); ++i)
        {
            res.push_back((i >> 1) ^ i);
        }

        return res;
    }
};
```
