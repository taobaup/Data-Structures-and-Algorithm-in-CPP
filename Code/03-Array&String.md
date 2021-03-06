>例子1:

Determine if all characters of a string are unique.
* 一般来说，一旦出现“unique”，就落入使用hash table或者bitset来判断元素出现与否的范畴。
```
#include <iostream>      
#include <bitset>        

using namespace std;

bool isUnique(string &s)
{
	bitset<256> hashMap;

	for (int i = 0; i < s.size(); ++i)
	{
		if (hashMap[s[i]])
		{
			return false;
		}

		hashMap[s[i]] = 1;
	}

	return true;
}

int main()
{
	string s = "leetcode";
	bool flag = isUnique(s);
	cout << flag << endl;

	s = "code";
	flag = isUnique(s);
	cout << flag << endl;

	return 0;
}
```

LeetCode 387. First Unique Character in a String
```
class Solution {
public:
	int firstUniqChar(string s) {
		int count[256] = { 0 };

		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i]];
		}

		for (int i = 0; i < s.size(); ++i)
		{
			// 不要写成 if(count[s[i]])
			if (count[s[i]] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};
```

```
class Solution {
public:
	int firstUniqChar(string s) {
		int count[26] = { 0 };

		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i] - 'a'];
		}

		for (int i = 0; i < s.size(); ++i)
		{
			// 不要写成 if(count[s[i] - 'a'])
			if (count[s[i] - 'a'] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};
```

>例子2:
Given two strings, determine if they are permutations of each other.
置换的特性：无论如何变化，每个字符出现的次数一定相同。一旦需要统计一个
元素集中元素出现的次数，我们就应该想到hash table。
hash table 需要扫描整个string，平均时间复杂度都是O(n)。最后比较两个hash
是否相同，每个合法字符都有可能出现，假设字符集大小为m，则需要的时间复
杂度是O(m)，故总的时间复杂度O(m+n)。空间上，平均空间是O(m)。
解法2:
对每个string中的字符按照ASCII编码顺序进⾏行排序。如果是一个置换，那么排序
完的两个string应该相等。这样做的时间复杂度是O(n log n)，空间复杂度是
O(n)。

>Given a newspaper and message as two strings, check if the message can be composed using letters in the newspaper.  
解题分析：message中用到的字符必须出现在newspaper中。其次，message中任意字符出现的次数一定少于其在newspaper中出现的次数。统计一个元素集中元素出现的次数，我们就应该想到hash table  
复杂度分析：假设message长度为m ，newspaper长度为n，我们的算法需要hash整条message和整个newspaper，故时间复杂度O(m+n)。  
假设字符集大小为c，则平均空间是O(c)

```
#include <iostream>      
#include <unordered_map>    

using namespace std;

bool canCompose(string &s, string &t)
{
	// 不要写成 if (s.size() != t.size())
	if (s.size() < t.size())
	{
		return false;
	}

	unordered_map<char, int> hashMap;

	for (int i = 0; i < s.size(); ++i)
	{
		++hashMap[s[i]];
	}

	for (int i = 0; i < t.size(); ++i)
	{
		if (hashMap.count(t[i]) == 0)
		{
			return false;
		}

		--hashMap[t[i]];

		if (hashMap[t[i]] < 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string s = "leetcode";
	string t = "codeleet";
	bool flag = canCompose(s, t);
	cout << flag << endl;

	s = "leetcode";
	t = "lintcode";
	flag = canCompose(s, t);
	cout << flag << endl;

	return 0;
}
```

>Anagram  
Write a method anagram(s,t) to decide if two strings are anagrams or not.  
Example  
Given s="abcd", t="dcab", return true.  
Challenge  
O(n) time, O(1) extra space

模式识别  
当处理当前节点需要依赖于之前的部分结果时，可以考虑使用hash table记录之前的处理结果。  
其本质类似于Dynamic Programming，利用hash table以O(1)的时间复杂度获得之前的结果。

LintCode 158. Valid Anagram

```
class Solution {
public:
	/**
	* @param s: The first string
	* @param t: The second string
	* @return: true or false
	*/
	bool anagram(string &s, string &t) {
		if (s.empty() || t.empty())
		{
			return false;
		}

		if (s.size() != t.size())
		{
			return false;
		}

		int count[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i]];
			// 不要写成 --count[s[i]]; 
			--count[t[i]];
		}

		for (int i = 0; i < s.size(); ++i)
		{
			if (count[s[i]] != 0)
			{
				return false;
			}
		}

		return true;
	}
};
```


```
class Solution {
public:
	/**
	* @param s: The first string
	* @param t: The second string
	* @return: true or false
	*/
	bool anagram(string &s, string &t) {
		if (s.empty() || t.empty())
		{
			return false;
		}

		if (s.size() != t.size())
		{
			return false;
		}

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}
};
```

>例子4
Find a pair of two elements in an array, whose sum is a given target
number.
最直观的方法是再次扫描数组，判断target – array[i]是否存在在数组中。
这样做的时间复杂度是O(n^2)
如何保存之前的处理结果？可以使⽤用hash table “target – array[i]是否存
在在数组中
复杂度分析：数组中的每个元素进⾏行上述hash处理，从头至尾扫描数组，判断对
应的另一个数是否存在在数组中，时间复杂度O(n)


>例子5
Get the length of the longest consecutive elements sequence in an array
For example, given [31, 6, 32, 1, 3, 2],the longest consecutive elements
sequence is [1, 2, 3]. Return its length: 3.
判断array[i] – 1，array[i] + 1是否存在于数组中。如何保存之前的处理结果？可
以使用hash table 由于序列是一系列连续整数，所以只要序列的最小值以及最
大值，就能唯一确定序列。而所谓的“作为后继加入序列”，“作为前驱加入序
列”，更新最大最小值。hash table的value可以是一个记录最大／最小值的
structure，用以描述当前节点参与构成的最长序列。
时间复杂度O(n)，附加空间O(n)

LintCode 79. Longest Common Substring
>Longest Common Substring  
Given two strings, find the longest common substring.  
Return the length of it.  
Example  
Given A="ABCD", B="CBCE", return 2.  
Note  
The characters in substring should occur continuously in original string.  
This is different with subsequence.

```
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
    	if (A.empty() || B.empty())
    	{
    		return 0;
    	}

    	int lcs = 0, lcs_temp = 0;
    	for (int i = 0; i < A.size(); ++i)
    	{
    		for (int j = 0; j < B.size(); ++j)
    		{
    			lcs_temp = 0;
    			while (i + lcs_temp < A.size()
    				&& j + lcs_temp < B.size()
    				&& A[i + lcs_temp] == B[j + lcs_temp])
    			{
    				++lcs_temp;
    			}

    			if (lcs_temp > lcs)
    			{
    				lcs = lcs_temp;
    			}
    		}
    	}

    	return lcs;
    }
};
```
