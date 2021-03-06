英文链接: https://leetcode.com/problems/reverse-integer/  
中文链接: https://leetcode-cn.com/problems/reverse-integer/


>反转int型整数，溢出返回0  
按照数字位反转过来就可以   
但是要注意两点，1是符号，2是整数越界问题   
先将数字转为正数   
INT_MIN的绝对值比INT_MAX大1，所以单独处理   
要判断res*10+num%10>MAX_VALUE，因为该操作可能会越界   
所以必须先判断res>(MAX_VALUE-num%10)/10 

```
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return 0;

        int num = abs(x);
        int res = 0;

        while(num != 0)
        {
            if(res > (INT_MAX - num % 10) / 10)
                return 0;

            res = res * 10 + num % 10;
            num = num / 10;
        }

        return x > 0 ? res : -res;
    }
};
```

>考虑溢出，int的范围是 -2147483648～2147483647   
若翻转 1000000009 则为 9000000001 溢出   
用long long保存临时结果，确保不会溢出   
将临时结果与INT_MIN与INT_MAX比较大小，得出最终结果 

```
class Solution {
public:
    int reverse(int x) {
        long long res = 0;

        while(x != 0)
        {
            res = res * 10 + x % 10;
            x = x / 10;
        }

        return (res < INT_MIN || res > INT_MAX) ? 0 : res; 
    }
};
```


>每次遍历的时候直接判断下一步是否可能溢出   
由 -2147483648～2147483647 可以看出   
x的第1位、res的最后1位只能是1或2   
当res等于 214748364 时，   
若下一步   
res为 2147483641 ，则x为 1463847412   
res为 2147483642 ，则x为 2463847412， 不存在这样的x输入   
所以一定要注意abs(res)等于INT_MAX/10时不要return 0;
```
class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while(x != 0)
        {
            if(abs(res) > INT_MAX / 10)
                return 0;

            res = res * 10 + x % 10;
            x = x / 10;
        }

        return res;
    }
};
```
