英文链接: https://leetcode.com/problems/add-two-numbers/  
中文链接: https://leetcode-cn.com/problems/add-two-numbers/

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode *cur = &dummy;
		
		int carry = 0;
		while (l1 != NULL || l2 != NULL)
		{
			int n1 = l1 != NULL ? l1->val : 0;
			int n2 = l2 != NULL ? l2->val : 0;
			int sum = n1 + n2 + carry;

			carry = sum / 10;
			cur->next = new ListNode(sum % 10);

			cur = cur->next;
			if (l1 != NULL)
			{
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				l2 = l2->next;
			}
		}

		// 不要遗漏这一步
		if (carry != 0)
		{
			cur->next = new ListNode(1);
		}

		return dummy.next;
	}
};
```
