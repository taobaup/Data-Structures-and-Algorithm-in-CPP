英文链接: https://leetcode.com/problems/copy-list-with-random-pointer/  
中文链接: https://leetcode-cn.com/problems/copy-list-with-random-pointer/


```
// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
```

```
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) 
		{
			return NULL;
		}

		RandomListNode *res = new RandomListNode(head->label);
		RandomListNode *node = res;
		
		RandomListNode *cur = head->next;
		map<RandomListNode*, RandomListNode*> m;
		m[head] = res;
		
		while (cur != NULL) 
		{
			RandomListNode *tmp = new RandomListNode(cur->label);
			node->next = tmp;
			m[cur] = tmp;
			node = node->next;
			cur = cur->next;
		}

		node = res;
		cur = head;
		while (node != NULL)
		{
			node->random = m[cur->random];
			node = node->next;
			cur = cur->next;
		}
		
		return res;
	}
};
```

```
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) 
		{
			return NULL;
		}

		cloneNodes(head);
		connectSiblingNodes(head);

		return reconnectNodes(head);
	}

	void cloneNodes(RandomListNode *head) 
	{
		RandomListNode *cur = head;
		while (cur != NULL) 
		{
			RandomListNode *node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur = node->next;
		}
	}

	void connectSiblingNodes(RandomListNode *head) 
	{
		RandomListNode *cur = head;
		while (cur != NULL) 
		{
			if (cur->random != NULL) 
			{
				cur->next->random = cur->random->next;
			}

			cur = cur->next->next;
		}
	}

	RandomListNode *reconnectNodes(RandomListNode *head) 
	{
		RandomListNode *cur = head;
		RandomListNode *res = head->next;
		while (cur != NULL) 
		{
			RandomListNode *tmp = cur->next;
			cur->next = tmp->next;
			
			if(tmp->next != NULL) 
			{
				tmp->next = tmp->next->next;
			}
			
			cur = cur->next;
		}
		
		return res;
	}
};
```
