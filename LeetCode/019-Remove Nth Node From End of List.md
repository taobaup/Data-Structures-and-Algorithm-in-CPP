
英文链接: https://leetcode.com/problems/remove-nth-node-from-end-of-list/  
中文链接: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/


>只允许遍历一次   
所以我们不能用一次完整的遍历来统计链表长度   
而是遍历到对应位置就应该移除了   
可以使用快慢指针   
cur先走n步后, prev、cur再一起走   
当cur->next为空删掉prev->next即可   
时间复杂度为O(链表的长度), 空间复杂度为O(1)   
两个需要注意的点   
1: test中似乎没有给出i < n的测试数据   
2: 但是注意cur == nullptr时删去首节点




```
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;

        int i = 0;
        ListNode *cur = head;

        while(i < n && cur != nullptr)
        {
            cur = cur->next;
            ++i;
        }

        // if(i < n)
        //    return head;
        if(cur == nullptr)
            return head->next;

        ListNode *prev = head;
        while(cur->next != nullptr)
        {
            cur = cur->next;
            prev = prev->next;
        }

        ListNode *tmp = prev->next;
        prev->next = prev->next->next;
        delete tmp;

        return head;
    }
};
```
