英文链接: https://leetcode.com/problems/add-binary/  
中文链接: https://leetcode-cn.com/problems/add-binary/

从尾到头遍历字符串   
每次取出1个字符，转为数字，若无字符则按0处理   
定义进位carry，初始值为0   
将三者加起来，对2取余即为当前位的数字，对2取商即为进位的值   
注意return时候，carry千万不要遗漏，如果carry为1，要在结果最前面加上1

```
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;

        while(m >= 0 || n >= 0)
        {
        	int p = m >= 0 ? a[m--] - '0' : 0;
        	// 注意不要写成 a[n--]
        	int q = n >= 0 ? b[n--] - '0' : 0;
        	int sum = p + q	+ carry;

        	res = to_string(sum % 2) + res;
        	carry = sum / 2;
        }

        return carry == 0 ? res : "1" + res;
    }
};
```



```
class Solution {
public:
    string addBinary(string a, string b) {
        string res;

        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;

        while(m >= 0 || n >= 0)
        {
        	int p = m >= 0 ? a[m--] - '0' : 0;
        	// 注意不要写成 a[n--]
        	int q = n >= 0 ? b[n--] - '0' : 0;
        	int sum = p + q	+ carry;
        	
        	int val = sum % 2;
        	res.insert(res.begin(), val + '0');
        	carry = sum / 2;
        }

        if(carry == 1)
        	res.insert(res.begin(), '1');

        return res;
    }
};
```
