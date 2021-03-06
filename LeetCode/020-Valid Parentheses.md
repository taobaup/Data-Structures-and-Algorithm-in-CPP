英文链接: https://leetcode.com/problems/valid-parentheses/  
中文链接: https://leetcode-cn.com/problems/valid-parentheses/


>括号匹配  
利用栈后进先出的特点即可   
时间复杂度为O(n)，空间复杂度也为O(n)   
注意一开始是要先让左括号入栈而非判断栈是否为空   
if(s[i] == ']' && parentheses.top() != '[')使用&&而非||不要写错

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '[' || s[i] == '(' || s[i] == '{')
                parentheses.push(s[i]);
            else
            {
                if(parentheses.empty())
                    return false;

                if(s[i] == ']' && parentheses.top() != '[')
                    return false;
                if(s[i] == ')' && parentheses.top() != '(')
                    return false;
                if(s[i] == '}' && parentheses.top() != '{')
                    return false;

                parentheses.pop();
            }
        }

        return parentheses.empty();
    }
};
```
