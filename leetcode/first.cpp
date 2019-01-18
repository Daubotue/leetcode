#include "libstd.h"

/* 1. Two Sum */
//vector<int> twoSum(vector<int>& nums, int target) 
//{
//	vector<int> vec;
//	map<int, int> ma;
//	map<int, int>::iterator iter;
//	for (int i = 0; i < (int)nums.size(); i++)
//	{
//		iter = ma.find(target - nums[i]);
//		if (iter == ma.end())
//		{
//			ma[nums[i]] = i;
//		}
//		else
//		{
//			vec.push_back(iter->second);
//			vec.push_back(i);
//			break;
//		}
//	}
//	return vec;
//}
//
//int main()
//{
//	int num[] = { 2, 7, 11, 15 };
//	vector<int> numbers(num, num + 4);
//	int target = 9;
//	vector<int> result = twoSum(numbers, target);
//	for (int i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << endl;
//	}
//	system("pause");
//	return 0;
//}

/* 2. Add Two Numbers */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//{
//	ListNode* resList = new ListNode(0);
//	ListNode* p = resList;
//	int flag = 0;
//	while (l1 != NULL && l2 != NULL)
//	{
//		int sum = l1->val + l2->val + flag;
//		flag = 0;
//		if (sum > 9)
//		{
//			flag = 1;
//			sum -= 10;
//		}
//		p->next = new ListNode(sum);
//		p = p->next;
//		l1 = l1->next;
//		l2 = l2->next;
//	}
//	while (l1 != NULL)
//	{
//		int sum = l1->val + flag;
//		flag = 0;
//		if (sum > 9)
//		{
//			flag = 1;
//			sum -= 10;
//		}
//		p->next = new ListNode(sum);
//		p = p->next;
//		l1 = l1->next;
//	}
//	while (l2 != NULL)
//	{
//		int sum = l2->val + flag;
//		flag = 0;
//		if (sum > 9)
//		{
//			flag = 1;
//			sum -= 10;
//		}
//		p->next = new ListNode(sum);
//		p = p->next;
//		l2 = l2->next;
//	}
//	if (flag != 0)
//	{
//		p->next = new ListNode(1);
//		p = p->next;
//	}
//	return resList->next == NULL ? resList : resList->next;
//}
//
//int main()
//{
//	ListNode *list1, *list2;
//	//list1 = new ListNode(2);
//	//list1->next = new ListNode(4);
//	//list1->next->next = new ListNode(3);
//	//list2 = new ListNode(5);
//	//list2->next = new ListNode(6);
//	//list2->next->next = new ListNode(4);
//	list1 = new ListNode(5);
//	list2 = new ListNode(5);
//
//	ListNode *newList = addTwoNumbers(list1, list2);
//	int sum = 0;
//	while (newList != NULL)
//	{
//		cout << newList->val;
//		newList = newList->next;
//	}
//
//	delete newList;
//	delete list1;
//	delete list2;
//
//	system("pause");
//	return 0;
//}

/* 3. Longest Substring Without Repeating Characters */
//int lengthOfLongestSubstring(string s)
//{
//	map<int, int> ma;
//	int left = -1, res = 0;
//	int nLen = (int)s.length();
//	for (int i = 0; i < nLen; i++)
//	{
//		if (ma.count(s[i]) && ma[s[i]] > left)
//		{
//			left = ma[s[i]];
//		}
//		ma[s[i]] = i;
//		res = max(res, i - left);
//	}
//	return res;
//}
//
//int main()
//{
//	string str = "pwwkewrerer";
//	cout << lengthOfLongestSubstring(str) << endl;
//	system("pause");
//	return 0;
//}

/* 4. Median of Two Sorted Arrays */
//int auxFindMedian(vector<int>& nums1, int i, vector<int>& nums2, int j, int pos)
//{
//	if (i >= nums1.size())
//		return nums2[j + pos - 1];
//	if (j >= nums2.size())
//		return nums1[i + pos - 1];
//	if (pos == 1)
//		return min(nums1[i], nums2[j]);
//	int midLeft  = (i + pos / 2 - 1 < nums1.size()) ? nums1[i + pos / 2 - 1] : INT_MAX;
//	int midRight = (j + pos / 2 - 1 < nums2.size()) ? nums2[j + pos / 2 - 1] : INT_MAX;
//	if (midLeft > midRight)
//	{
//		return auxFindMedian(nums1, i, nums2, j + pos / 2, pos - pos / 2);
//	}
//	else
//	{
//		return auxFindMedian(nums1, i + pos / 2, nums2, j, pos - pos / 2);
//	}
//}
//
//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//{
//	int m = nums1.size();
//	int n = nums2.size();
//	int left = (m + n + 1) / 2;
//	int right = (m + n + 2) / 2;
//	return (auxFindMedian(nums1, 0, nums2, 0, left) + auxFindMedian(nums1, 0, nums2, 0, right)) / 2.0;
//}
//
//int main()
//{
//	vector<int> nums1{ 1,2 };
//	vector<int> nums2{ 3,4 };
//	cout << findMedianSortedArrays(nums1, nums2) << endl;
//	system("pause");
//	return 0;
//}

/*5. Longest Palindromic Substring */
//string longestPalindrome(string s) 
//{
//	string res;
//	int nMax = 0;
//	int nLen = s.length();
//	if (nLen < 2)
//		return s;
//	for (int i = 0; i < nLen-1; i++)
//	{
//		int jl = i, jr = i;
//		while (jl >= 0 && jr < nLen && s[jl] == s[jr])
//		{
//			--jl;
//			++jr;
//		}
//		++jl; --jr;
//		if (nMax < jr - jl + 1)
//		{
//			nMax = jr - jl + 1;
//			res = s.substr(jl, nMax);
//		}
//		if (s[i] == s[i + 1])
//		{
//			jl = i, jr = i + 1;
//			while (jl >= 0 && jr < nLen && s[jl] == s[jr])
//			{
//				--jl;
//				++jr;
//			}
//			++jl; --jr;
//			if (nMax < jr - jl + 1)
//			{
//				nMax = jr - jl + 1;
//				res = s.substr(jl, nMax);
//			}
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	string strs[3] = { "s", "babad", "cbbd" };
//	for (auto &it : strs)
//		cout << longestPalindrome(it) << endl;
//	system("pause");
//	return 0;
//}

/* 7. Reverse Integer */
//int reverse(int x)
//{
//	long long res = 0;
//	while (x)
//	{
//		res = res * 10 + x % 10;
//		x /= 10;
//	}
//	return (res > INT_MAX || res < INT_MIN) ? 0 : res;
//}
//
//int main()
//{
//	cout << reverse(-120) << endl;
//	system("pause");
//	return 0;
//}

/*8. String to Integer (atoi) */
//int myAtoi(string str) 
//{
//	if (str == "")
//		return 0;
//	int i = 0;
//	while (str[i] == '\0' || str[i] == ' ')
//	{
//		++i;
//	}
//	int flag = 1;
//	if (str[i] == '-')
//	{
//		flag = -1;
//		++i;
//	}
//	else if (str[i] == '+')
//	{
//		++i;
//	}
//	long long res = 0;
//	while (i < str.length())
//	{
//		if (str[i] >= '0' && str[i] <= '9')
//		{
//			res = res * 10 + str[i] - '0';
//			if (res > INT_MAX)
//			{
//				if (flag == 1)
//					return INT_MAX;
//				else
//					return INT_MIN;
//			}
//			++i;
//		}
//		else
//			break;
//	}
//	return (int)(flag * res);
//}
//
//int main()
//{
//	string strs[5] = { "42", "   -42", "4193 with words", "words and 987", "-91283472332" };
//	for (int i = 0; i < 5; i++)
//	{
//		cout << myAtoi(strs[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/* 9. Palindrome Number */
//bool isPalindrome(int x) 
//{
//	if (x < 0 || (x % 10 == 0 && x != 0))
//		return false;
//	int reverse = 0;
//	while (x > reverse)
//	{
//		reverse = reverse * 10 + x % 10;
//		x /= 10;
//	}
//	return reverse == x || reverse / 10 == x;
//}
//
//int main()
//{
//	int num = 1221;
//	if (isPalindrome(num))
//		cout << "true" << endl;
//	else
//		cout << "false" << endl;
//	system("pause");
//	return 0;
//}

/*10. Regular Expression Matching */
//bool isMatch(string s, string p) 
//{
//	if (p.empty())
//		return s.empty();
//	if (p.size() == 1)
//		return (s.size() == 1 && (s == p || p[0] == '.'));
//	if (p[1] != '*')
//	{
//		if (s.empty())
//			return false;
//		return ((s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)));
//	}
//	while (!s.empty() && (s[0] == p[0] || p[0] == '.'))
//	{
//		if (isMatch(s, p.substr(2)))
//			return true;
//		s = s.substr(1);
//	}
//	return isMatch(s, p.substr(2));
//}
//
//int main()
//{
//	string ss[5] = { "aa", "aa", "ab", "aab", "mississippi" };
//	string ps[5] = { "a", "a*", ".*", "c*a*b", "mis*is*p*." };
//	for (int i = 0; i < 5; i++)
//	{
//		cout << isMatch(ss[i], ps[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*11. Container With Most Water */
//int maxArea(vector<int>& vheight)
//{
//	int res = 0;
//	int nl = 0;
//	int nr = vheight.size() - 1;
//	while (nl < nr)
//	{
//		int height = min(vheight.at(nl), vheight.at(nr));
//		int contain = height * (nr - nl);
//		if (contain > res)
//			res = contain;
//		if (vheight.at(nl) > vheight.at(nr))
//			--nr;
//		else
//			++nl;
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1,8,6,2,5,4,8,3,7 };
//	cout << maxArea(vec) << endl;
//	system("pause");
//	return 0;
//}

/*12. Integer to Roman */
//string intToRoman(int num)
//{
//	string ROMAN[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//	int nums[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
//	int tmp;
//	string res;
//	for (int i = 0; i < 13; i++)
//	{
//		tmp = num / nums[i];
//		while (tmp)
//		{
//			res += ROMAN[i];
//			tmp--;
//		}
//		num = num % nums[i];
//	}
//	return res;
//}
//
//int main()
//{
//	int nn[5] = { 3,4,9,58,1994 };
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << intToRoman(nn[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*13. Roman to Integer*/
//int romanToInt(string s) 
//{
//	map<char, int> ma{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
//	int Len = s.length();
//	int res = 0;
//	for (int i = 0; i < Len; i++)
//	{
//		if (i == Len - 1 || ma[s[i + 1]] <= ma[s[i]])
//			res += ma[s[i]];
//		else
//			res -= ma[s[i]];
//	}
//	return res;
//}
//
//int main()
//{
//	string str[2] = {"LVIII" , "MCMXCIV" };
//	for (int i = 0; i < 2; i++)
//		cout << romanToInt(str[i]) << endl;
//
//	system("pause");
//	return 0;
//}

/*14. Longest Common Prefix */
//string longestCommonPrefix(vector<string>& strs)
//{
//	if (0 == strs.size())
//		return "";
//	int nMaxLen = INT_MAX;
//	string res;
//	for (auto &it : strs)
//	{
//		if (nMaxLen > it.length())
//			nMaxLen = it.length();
//	}
//	if (0 == nMaxLen)
//		return "";
//	bool flag = true;
//	for (int i = 0; i < nMaxLen; i++)
//	{
//		for (auto &it : strs)
//		{
//			if (it[i] != strs[0][i])
//			{
//				flag = false;
//				break;
//			}
//		}
//		if (!flag)
//			break;
//		res += strs[0][i];
//	}
//	return res;
//}
//
//int main()
//{
//	vector<string> vec/*{ "flower","flow","flight" }*/;
//	cout << longestCommonPrefix(vec) << endl;
//	system("pause");
//	return 0;
//}

/*15. 3Sum */
//vector<vector<int>> threeSum(vector<int>& nums) 
//{
//	vector<vector<int> > res;
//	if ((int)nums.size() < 3)
//		return res;
//	sort(nums.begin(), nums.end());
//	int sum, nFront, nLast, nLen = (int)nums.size();
//	for (int i=0; i< nLen-2; i++)
//	{
//		while (i > 0 && i < nLen - 2 && nums[i] == nums[i - 1])
//			++i;
//		sum = nums[i];
//		nFront = i + 1;
//		nLast = nLen - 1;
//		while (nFront < nLast)
//		{
//			if (sum + nums[nFront] + nums[nLast] == 0)
//			{
//				res.push_back(vector<int>{sum, nums[nFront], nums[nLast]});
//				++nFront;
//				while (nFront < nLast && nums[nFront] == nums[nFront - 1])
//					++nFront;
//			}
//			else if (sum + nums[nFront] + nums[nLast] > 0)
//			{
//				--nLast;
//				while (nFront < nLast && nums[nLast] == nums[nLast + 1])
//					--nLast;
//			}
//			else
//			{
//				++nFront;
//				while (nFront < nLast && nums[nFront] == nums[nFront - 1])
//					++nFront;
//			}
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ -1, 0, 1, 2, -1, -4 };
//	vector<vector<int> > res = threeSum(vec);
//	for (int i = 0; i < (int)res.size(); ++i)
//	{
//		for (int j = 0; j < (int)res[i].size(); ++j)
//		{
//			cout << res[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*17. Letter Combinations of a Phone Number */
//void auxSearch(vector<string> &res, string &digits, int cur, string strT, int nSize, string *strs)
//{
//	if (cur == nSize)
//	{
//		res.push_back(strT);
//		return;
//	}
//	for (int i = 0; i < strs[digits[cur] - '0'].size(); i++)
//	{
//		strT += strs[digits[cur] - '0'][i];
//		auxSearch(res, digits, cur+1, strT, nSize, strs);
//		strT.pop_back();
//	}
//}	
//
//vector<string> letterCombinations(string digits) 
//{
//	vector<string> res;
//	string tmp;
//	if (digits == "")
//		return res;
//	string strs[10] = {"","" ,"abc" ,"def",
//						"ghi", "jkl", "mno",
//						"pqrs", "tuv", "wxyz"};
//	int nSize = digits.length();
//	auxSearch(res, digits, 0, tmp, nSize, strs);
//	return res;
//}
//
//int main()
//{
//	string str = "23";
//	vector<string> res = letterCombinations(str);
//	for (auto &it : res)
//		cout << it << endl;
//	system("pause");
//	return 0;
//}

/*19. Remove Nth Node From End of List */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* removeNthFromEnd(ListNode* head, int n)
//{
//	if (head == nullptr)
//		return head;
//	ListNode* pre = head;
//	ListNode* cur = head;
//	for (int i = 0; i < n; i++)
//		cur = cur->next;
//	if (cur == nullptr)
//		return head->next;
//	while (cur->next)
//	{
//		pre = pre->next;
//		cur = cur->next;
//	}
//	pre->next = pre->next->next;
//	return head;
//}
//
//int main()
//{
//	ListNode *root = new ListNode(1);
//	root->next = new ListNode(2);
//	root->next->next = new ListNode(3);
//	root->next->next->next = new ListNode(4);
//	root->next->next->next->next = new ListNode(5);
//	ListNode *after = removeNthFromEnd(root, 2);
//	while (after)
//	{
//		cout << after->val << " -> ";
//		after = after->next;
//	}
//	system("pause");
//	return 0;
//}

/*20. Valid Parentheses */
//bool isValid(string s) 
//{
//	map<char, char> ma{ {')', '('}, {'}', '{'}, {']', '['} };
//	stack<char> sta;
//	int len = s.length();
//	for (int i = 0; i < len; ++i)
//	{
//		switch (s[i])
//		{
//		case ')':
//			if (sta.empty() || sta.top() != ma[s[i]])
//				 return false;
//			else
//				sta.pop();
//			break;
//		case '}':
//			if (sta.empty() || sta.top() != ma[s[i]])
//				return false;
//			else
//				sta.pop();
//			break;
//		case ']':
//			if (sta.empty() || sta.top() != ma[s[i]])
//				return false;
//			else
//				sta.pop();
//			break;
//		default:
//			sta.push(s[i]);
//		}
//	}
//	return sta.empty();
//}
//
//int main()
//{
//	string strs[3] = { "()", "()[]{}", "(]" };
//	for (int i = 0; i < 3; i++)
//		cout << isValid(strs[i]) << endl;
//	system("pause");
//	return 0;
//}

/*21. Merge Two Sorted Lists */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
//{
//	if (l1 == NULL)
//		return l2;
//	if (l2 == NULL)
//		return l1;
//	int init;
//	if (l1->val < l2->val)
//	{
//		init = l1->val;
//		l1 = l1->next;
//	}
//	else
//	{
//		init = l2->val;
//		l2 = l2->next;
//	}
//	ListNode* answer = new ListNode(init);
//	ListNode* res = answer;
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			res->next = new ListNode(l1->val);
//			l1 = l1->next;
//			res = res->next;
//		}
//		else
//		{
//			res->next = new ListNode(l2->val);
//			l2 = l2->next;
//			res = res->next;
//		}
//	}
//	while (l1)
//	{
//		res->next = new ListNode(l1->val);
//		l1 = l1->next;
//		res = res->next;
//	}
//	while (l2)
//	{
//		res->next = new ListNode(l2->val);
//		l2 = l2->next;
//		res = res->next;
//	}
//	return answer;
//}
//
//int main()
//{
//	ListNode* str1 = new ListNode(1);
//	str1->next = new ListNode(2);
//	str1->next->next = new ListNode(4);
//	ListNode* str2 = new ListNode(1);
//	str2->next = new ListNode(3);
//	str2->next->next = new ListNode(4);
//	ListNode* res = mergeTwoLists(str1, str2);
//	while (res)
//	{
//		cout << res->val << " ";
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

/*22. Generate Parentheses */
//void recurParenthesis(vector<string> &res, string &curStr, int &n, int length, int left, int right)
//{
//	if (length == 2 * n)
//	{
//		res.push_back(curStr);
//		return;
//	}
//	if (left < n)
//	{
//		curStr += '(';
//		recurParenthesis(res, curStr, n, length+1, left+1, right);
//		curStr = curStr.substr(0, curStr.length() - 1);
//	}
//	if (right < left)
//	{
//		curStr += ')';
//		recurParenthesis(res, curStr, n, length + 1, left, right + 1);
//		curStr = curStr.substr(0, curStr.length() - 1);
//	}
//}
//
//vector<string> generateParenthesis(int n) 
//{
//	vector<string> res;
//	string curStr;
//	int length = 0, left = 0, right = 0;
//	if (n > 0)
//	{
//		recurParenthesis(res, curStr, n, length, left, right);
//	}
//	return res;
//}
//
//int main()
//{
//	vector<string> res = generateParenthesis(3);
//	for (auto &it : res)
//		cout << it << endl;
//	system("pause");
//	return 0;
//}

/*23. Merge k Sorted Lists */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//struct cmp
//{
//	bool operator ()(const ListNode* A, const ListNode* B)
//	{
//		return A->val > B->val;
//	}
//};
//
//ListNode* mergeKLists(vector<ListNode*>& lists) 
//{
//	priority_queue < ListNode*, vector< ListNode*>, cmp> que;
//	for (auto &it : lists)
//	{
//		if (it)
//		{
//			que.push(it);
//		}
//	}
//	if (que.empty())
//	{
//		return nullptr;
//	}
//	ListNode* res = que.top();
//	que.pop();
//	if (res->next != nullptr)
//	{
//		que.push(res->next);
//	}
//	ListNode* tail = res;
//	while (!que.empty())
//	{
//		tail->next = que.top();
//		que.pop();
//		tail = tail->next;
//		if (tail->next != nullptr)
//		{
//			que.push(tail->next);
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<ListNode*> total;
//	ListNode* listNd1 = new ListNode(1);
//	listNd1->next = new ListNode(4);
//	listNd1->next->next = new ListNode(5);
//	total.push_back(listNd1);
//	ListNode* listNd2 = new ListNode(1);
//	listNd2->next = new ListNode(3);
//	listNd2->next->next = new ListNode(4);
//	total.push_back(listNd2);
//	ListNode* listNd3 = new ListNode(2);
//	listNd3->next = new ListNode(6);
//	total.push_back(listNd3);
//
//	ListNode *res = mergeKLists(total);
//	while (res != nullptr)
//	{
//		cout << res->val;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

/*24. Swap Nodes in Pairs */
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//ListNode* swapPairs(ListNode* head) 
//{
//	if (head == nullptr)
//		return nullptr;
//	ListNode *res = new ListNode(-1);
//	ListNode *tail = res;
//	tail->next = head;
//	while (tail->next != nullptr && tail->next->next != nullptr)
//	{
//		ListNode *tmp = tail->next->next;
//		tail->next->next = tmp->next;
//		tmp->next = tail->next;
//		tail->next = tmp;
//		tail = tail->next->next;
//	}
//	return res->next;
//}
//
//int main()
//{
//	ListNode *listN = new ListNode(1);
//	listN->next = new ListNode(2);
//	listN->next->next = new ListNode(3);
//	listN->next->next->next = new ListNode(4);
//	ListNode *res = swapPairs(listN);
//	while (res)
//	{
//		cout << res->val << endl;
//		res = res->next;
//	}
//	system("pause");
//	return 0;
//}

/*26. Remove Duplicates from Sorted Array */
//int removeDuplicates(vector<int>& nums)
//{
//	if (nums.empty())
//		return 0;
//	int i = 0, j = 0;
//	for (;j < nums.size(); )
//	{
//		if (nums[i] != nums[j])
//			nums[++i] = nums[j++];
//		else
//			++j;
//	}
//	return i + 1;
//}
//
//int main()
//{
//	vector<int> vec{ 1,2,3 };
//	cout << removeDuplicates(vec) << endl;
//	system("pause");
//	return 0;
//}

/*27. Remove Element */
//int removeElement(vector<int>& nums, int val) 
//{
//	int i = 0, j = nums.size();
//	while (i < j)
//	{
//		if (nums[i] == val)
//		{
//			nums[i] = nums[--j];
//		}
//		else
//		{
//			++i;
//		}
//	}
//	return j;
//}
//
//int main()
//{
//	vector<int> vec{ 3,2,2,3 };
//	cout << removeElement(vec, 2);
//	system("pause");
//	return 0;
//}

/*28. Implement strStr() */
//int strStr(string haystack, string needle) 
//{
//	if (haystack == "" && needle != "")
//		return -1;
//	if (needle == "")
//		return 0;
//	int nLen = haystack.length() - needle.length();
//	for (int i = 0; i <= nLen; ++i)
//	{
//		if (haystack[i] == needle[0])
//		{
//			int k = i + 1;
//			bool flag = true;
//			for (int j = 1; j < needle.length(); ++j)
//			{
//				if (haystack[k++] != needle[j])
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag)
//				return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	string haystack = "mississippi", needle = "issip";
//	cout << strStr(haystack, needle) << endl;
//	system("pause");
//	return 0;
//}

/*29. Divide Two Integers */
//int divide(int dividend, int divisor)
//{
//	long long res = 0, m = abs((long long)dividend), n = abs((long long)divisor);
//	int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
//	while (m >= n)
//	{
//		long long k = n, f = 1;
//		while ((k << 1) < m)
//		{
//			k = k << 1;
//			f = f << 1;
//		}
//		m -= k;
//		res += f;
//	}
//	if (sign == -1)
//		res *= -1;
//	if (res < INT_MIN)
//		return INT_MIN;
//	else if (res > INT_MAX)
//		return INT_MAX;
//	else
//		return res;
//}
//
//int main()
//{
//	cout << divide(-2147483647,-1) << endl;
//	system("pause");
//	return 0;
//}
/*33. Search in Rotated Sorted Array */
//int search(vector<int>& nums, int target) 
//{
//	int nl = 0, nr = nums.size() - 1;
//	while (nl <= nr)
//	{
//		int nm = nl + (nr - nl) / 2;
//		if (target == nums[nm])
//			return nm;
//		else if (nums[nl] <= nums[nm])
//		{
//			if (nums[nm] >= target && nums[nl] <= target)
//				nr = nm - 1;
//			else
//				nl = nm + 1;
//		}
//		else
//		{
//			if (nums[nm] <= target && nums[nr] >= target)
//				nl = nm + 1;
//			else
//				nr = nm - 1;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	vector<int> vec{ 3,1 };
//	cout << search(vec, 1) << endl;
//	system("pause");
//	return 0;
//}

/*34. Find First and Last Position of Element in Sorted Array */
//vector<int> searchRange(vector<int>& nums, int target)
//{
//	vector<int> res{ -1, -1 };
//	if (nums.empty())
//		return res;
//	int nl = 0, nr = nums.size() - 1;
//	while (nl <= nr)
//	{
//		int nmid = nl + (nr - nl) / 2;
//		if (nums[nmid] > target)
//			nr = nmid - 1;
//		else if (nums[nmid] < target)
//			nl = nmid + 1;
//		else
//		{
//			nl = nr = nmid;
//			while ((nl - 1)>=0 && nums[nl - 1] == target)
//				--nl;
//			while ((nr + 1) < nums.size() && nums[nr + 1] == target)
//				++nr;
//			break;
//		}
//	}
//	if (nl < nums.size() && 0<=nr && nums[nl] == target)
//	{
//		res[0] = nl;
//		res[1] = nr;
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ -1};
//	vector<int> res = searchRange(vec, 2);
//	for (auto &it : res)
//		cout << it << "  ";
//	system("pause");
//	return 0;
//}

/*46. Permutations */
//void recursion(vector<vector<int>> &res, vector<int>& nums, int cur)
//{
//	if (cur == nums.size() - 1)
//	{
//		res.push_back(nums);
//		return;
//	}
//	for (int i = cur; i < nums.size(); ++i)
//	{
//		swap(nums[i], nums[cur]);
//		recursion(res, nums, cur + 1);
//		swap(nums[i], nums[cur]);
//	}
//}
//
//vector<vector<int>> permute(vector<int>& nums) 
//{
//	vector<vector<int>> res;
//	recursion(res, nums, 0);
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1,2,3 };
//	vector<vector<int>> res = permute(vec);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//		{
//			cout << iter << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*49. Group Anagrams */
//vector<vector<string>> groupAnagrams(vector<string>& strs) 
//{
//	vector<vector<string> > res;
//	map<string, multiset<string> > ma;
//	for (auto &it : strs)
//	{
//		string sortstr = it;
//		sort(sortstr.begin(), sortstr.end());
//		ma[sortstr].insert(it);
//	}
//	for (auto &it : ma)
//	{
//		vector<string> tmp;
//		for (auto &iter : it.second)
//		{
//			tmp.push_back(iter);
//		}
//		res.push_back(tmp);
//	}
//	return res;
//}
//
//int main()
//{
//	vector<string> vec{ "eat", "tea", "tan", "ate", "nat", "bat" };
//	vector<vector<string> > res = groupAnagrams(vec);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//		{
//			cout << iter << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*56. Merge Intervals */
//struct Interval 
//{
//	int start;
//	int end;
//	Interval() : start(0), end(0) {}
//	Interval(int s, int e) : start(s), end(e) {}
//};
//
//static bool cmp(const Interval &A, const Interval &B)
//{
//	return A.start < B.start;
//}
//
//vector<Interval> merge(vector<Interval>& intervals) 
//{
//	vector<Interval> res;
//	if ((int)intervals.size() == 0)
//		return res;
//	sort(intervals.begin(), intervals.end(), cmp);
//	res.push_back(intervals.at(0));
//	for (int i = 1; i < (int)intervals.size(); ++i)
//	{
//		if (intervals.at(i).start <= res.back().end)
//		{
//			res.back().end = max(res.back().end, intervals.at(i).end);
//		}
//		else
//		{
//			res.push_back(intervals.at(i));
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	vector<Interval> vec{ Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18) };
//	vector<Interval> res = merge(vec);
//	for (auto &it : res)
//	{
//		cout << it.start << " " << it.end << endl;
//	}
//	system("pause");
//	return 0;
//}
//

/*57. Insert Interval */
//struct Interval {
//	int start;
//	int end;
//	Interval() : start(0), end(0) {}
//	Interval(int s, int e) : start(s), end(e) {}
//};
//
//vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
//{
//	vector<Interval> res;
//	if ((int)intervals.size() == 0)
//		return vector<Interval>{newInterval};
//	for (int i = 0; i < (int)intervals.size(); ++i)
//	{
//		if (newInterval.start > intervals[i].end)
//		{
//			res.push_back(Interval(intervals[i].start, intervals[i].end));
//		}
//		else if (newInterval.end < intervals[i].start)
//		{
//			res.push_back(Interval(newInterval.start, newInterval.end));
//			for (int j = i; j < (int)intervals.size(); ++j)
//			{
//				res.push_back(Interval(intervals[j].start, intervals[j].end));
//			}
//			return res;
//		}
//		else
//		{
//			newInterval.start = min(newInterval.start, intervals[i].start);
//			newInterval.end = max(newInterval.end, intervals[i].end);
//		}
//	}
//	res.push_back(Interval(newInterval.start, newInterval.end));
//	return res;
//}
//
//int main()
//{
//	vector<Interval> vec{ Interval(1,5) };
//	Interval newIn(2, 3);
//	vector<Interval> res = insert(vec, newIn);
//	for (auto &it : res)
//	{
//		cout << it.start << " " << it.end << endl;
//	}
//	system("pause");
//	return 0;
//}

/*67. Add Binary */
//string addBinary(string a, string b) 
//{
//	string res;
//	int i = a.length() - 1;
//	int j = b.length() - 1;
//	int flag = 0;
//	while (i >= 0 || j >= 0 || flag > 0)
//	{
//		int tmp = 0;
//		if (i >= 0)
//			tmp += a[i--] - '0';
//		if (j >= 0)
//			tmp += b[j--] - '0';
//		tmp += flag;
//		if (tmp > 1)
//		{
//			flag = 1;
//			tmp -= 2;
//		}
//		else
//			flag = 0;
//		char ch = tmp + '0';
//		res = ch + res;
//	}
//	return res;
//}
//
//int main()
//{
//	string a = "1010", b = "1011";
//	cout << addBinary(a, b) << endl;
//	system("pause");
//	return 0;
//}

/*69. Sqrt(x) */
//int mySqrt(int x) 
//{
//	if (x < 0)
//		return 0;
//	int left = 1, right = x;
//	int mid = left + (right - left) / 2;
//	while (left <= right)
//	{
//		if (mid == x / mid)
//			return mid;
//		if (mid > x / mid)
//			right = mid - 1;
//		else
//			left = mid + 1;
//		mid = left + (right - left) / 2;
//	}
//	return right;
//}
//
//int main()
//{
//	cout << mySqrt(8) << endl;
//	system("pause");
//	return 0;
//}

/*70. Climbing Stairs */
//int climbStairs(int n) 
//{
//	if (n == 0) return 0;
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//
//	int first = 1;
//	int second = 2;
//	int all = 0;
//	for (int i = 3; i <= n; ++i)
//	{
//		all = first + second;
//		first = second;
//		second = all;
//	}
//	return all;
//}

/*73. Set Matrix Zeroes */
//void setZeroes(vector<vector<int>>& matrix) 
//{
//	int row = (int)matrix.size();
//	if (0 == row)
//		return;
//	int col = (int)matrix[0].size();
//	if (0 == col)
//		return;
//	bool *flag = new bool[row + col];
//	memset(flag, false, sizeof(bool)*(row + col));
//	for (int i = 0; i < row; ++i)
//	{
//		for (int j = 0; j < col; ++j)
//		{
//			if (0 == matrix[i][j])
//			{
//				flag[i] = flag[row + j] = true;
//			}
//		}
//	}
//	for (int i = 0; i < row; ++i)
//	{
//		if (flag[i])
//		{
//			for (int j = 0; j < col; ++j)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//	}
//	for (int j = 0; j < col; ++j)
//	{
//		if (flag[row + j])
//		{
//			for (int i = 0; i < row; ++i)
//			{
//				matrix[i][j] = 0;
//			}
//		}
//	}
//}
//
//int main()
//{
//	vector < vector<int> > vec{ {1,1,1}, {1,0,1}, {1,1,1} };
//	setZeroes(vec);
//	for (int i = 0; i < (int)vec.size(); ++i)
//	{
//		for (int j = 0; j < (int)vec[i].size(); ++j)
//		{
//			cout << vec[i][j] << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*77. Combinations */
//void auxCombine(int n, int k, vector<vector<int> >& res, vector<int>& tmp, int index)
//{
//	if (tmp.size() == k)
//	{
//		res.push_back(tmp);
//		return ;
//	}
//	for (int i = index + 1; i <= n; ++i)
//	{
//		tmp.push_back(i);
//		auxCombine(n, k, res, tmp, i);
//		tmp.pop_back();
//	}
//}
//
//vector<vector<int>> combine(int n, int k) 
//{
//	vector<vector<int> > res;
//	vector<int> tmp;
//	auxCombine(n, k, res, tmp, 0);
//	return res;
//}
//
//int main()
//{
//	vector<vector<int> > res = combine(4, 2);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//		{
//			cout << iter << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*78. Subsets */
//void auxsubsets(vector<vector<int> >& res, vector<int>& tmp, vector<int>&nums, int index)
//{
//	if (tmp.size() <= nums.size())
//	{
//		res.push_back(tmp);
//	}
//	if (tmp.size() == nums.size())
//	{
//		return;
//	}
//	else
//	{
//		for (int i = index; i < nums.size(); ++i)
//		{
//			tmp.push_back(nums[i]);
//			auxsubsets(res, tmp, nums, i+1);
//			tmp.pop_back();
//		}
//	}
//}
//
//vector<vector<int> > subsets(vector<int>& nums)
//{
//	vector<vector<int> > res;
//	vector<int> tmp;
//	auxsubsets(res, tmp, nums, 0);
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1, 2, 3 };
//	vector<vector<int> > res = subsets(vec);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*79. Word Search */
//int steps[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
//int rows, cols;
//
//bool isValid(int x_, int y_)
//{
//	if (x_ >= 0 && x_ < rows && y_ >= 0 && y_ < cols)
//		return true;
//	return false;
//}
//
//bool auxExist(vector<vector<char> >&board, string &word, vector<vector<bool> > &visited, int len, int i, int j)
//{
//	if (len == word.length() - 1)
//		return board[i][j] == word[len];
//	if (board[i][j] == word[len])
//	{
//		visited[i][j] = true;
//		for (int index = 0; index < 4; ++index)
//		{
//			int nX = i + steps[index][0];
//			int nY = j + steps[index][1];
//			if (isValid(nX, nY) && !visited[nX][nY] &&auxExist(board, word, visited, len + 1, nX, nY))
//				return true;
//		}
//		visited[i][j] = false;
//	}
//	return false;
//}
//
//bool exist(vector<vector<char>>& board, string word)
//{
//	rows = board.size();
//	cols = board.at(0).size();
//	vector<vector<bool> > visited(rows, vector<bool>(cols, false));
//	for (int i = 0; i < rows; ++i)
//	{
//		for (int j = 0; j < cols; ++j)
//		{
//			if (auxExist(board, word, visited, 0, i, j))
//				return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{
//	vector<vector<char> > board{ {'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'} };
//	string word[3] = { "ABCCED", "SEE", "ABCB" };
//	for (auto &it : word)
//	{
//		cout << exist(board, it) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*88. Merge Sorted Array */
//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
//{
//	int index = m + n - 1;
//	--m;
//	--n;
//	while (m >= 0 && n >= 0)
//	{
//		if (nums1[m] > nums2[n])
//		{
//			nums1[index--] = nums1[m--];
//		}
//		else
//		{
//			nums1[index--] = nums2[n--];
//		}
//	}
//	while (n >= 0)
//	{
//		nums1[index--] = nums2[n--];
//	}
//}
//
//int main()
//{
//	vector<int> vec1{ 1,2,3,0,0,0 };
//	vector<int> vec2{ 2,5,6 };
//	merge(vec1, 3, vec2, 3);
//	for (auto &it : vec1)
//	{
//		cout << it << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}

/*91. Decode Ways */
//bool isValid(char ch)
//{
//	if (ch >= '1' && ch <= '26')
//		return true;
//	return false;
//}
//
//bool isValid(char ch1, char ch2)
//{
//	if (ch2 == '0')
//		return false;
//	string str;
//	str += ch2;
//	str += ch1;
//	int integer = stoi(str);
//	if (integer >= 1 && integer <= 26)
//		return true;
//	return false;
//}
//
//int numDecodings(string s) 
//{
//	if (s.length() == 0 || s[0] == '0')
//		return 0;
//	if (s.length() == 1)
//		return 1;
//	int dp1 = 1, dp2 = 1;
//	for (int i = 1; i < s.length(); ++i)
//	{
//		int cur = 0;
//		if (isValid(s[i]))
//			cur += dp2;
//		if (isValid(s[i], s[i - 1]))
//			cur += dp1;
//		dp1 = dp2;
//		dp2 = cur;
//	}
//	return dp2;
//}
//
//int main()
//{
//	string strs[2] = { "12", "226" };
//	for (auto &it : strs)
//	{
//		cout << numDecodings(it) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*98. Validate Binary Search Tree */
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//TreeNode *pre = NULL;
//bool isValidBST(TreeNode* root) 
//{
//	if (root != NULL)
//	{
//		if (!isValidBST(root->left))
//		{
//			return false;
//		}
//		if (pre != NULL && root->val <= pre->val)
//		{
//			return false;
//		}
//		pre = root;
//		return isValidBST(root->right);
//	}
//	return true;
//}
//
//int main()
//{
//	TreeNode *tree = new TreeNode(5);
//	tree->left = new TreeNode(1);
//	tree->right = new TreeNode(4);
//	tree->right->left = new TreeNode(3);
//	tree->right->right = new TreeNode(6);
//	cout << isValidBST(tree) << endl;
//	system("pause");
//	return 0;
//}

/*102. Binary Tree Level Order Traversal */
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//vector<vector<int>> levelOrder(TreeNode* root) 
//{
//	vector<vector<int> > res;
//	if (root == nullptr)
//		return res;
//	queue<TreeNode*> que;
//	TreeNode* tmp = root;
//	que.push(tmp);
//	while (!que.empty())
//	{
//		int nSize = que.size();
//		vector<int> vec;
//		for (int i = 0; i < nSize; ++i)
//		{
//			TreeNode* val = que.front();
//			que.pop();
//			vec.push_back(val->val);
//			if (val->left != nullptr)
//				que.push(val->left);
//			if (val->right != nullptr)
//				que.push(val->right);
//		}
//		res.push_back(vec);
//	}
//	return res;
//}
//
//int main()
//{
//	TreeNode *root = new TreeNode(3);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(20);
//	root->right->left = new TreeNode(15);
//	root->right->right = new TreeNode(7);
//	vector<vector<int>> res = levelOrder(root);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0; 
//}

/*125. Valid Palindrome */
//void toLower(string &s)
//{
//	for (int i = 0; i < (int)s.length(); ++i)
//	{
//		if (s[i] >= 'A' && s[i] <= 'Z')
//			s[i] += 'a' - 'A';
//	}
//}
//
//bool isPalindrome(string s) 
//{
//	toLower(s);
//	int nFront = 0, nTail = (int)s.length() - 1;
//	while (nFront < nTail)
//	{
//		while (!isalnum(s[nFront]))
//			++nFront;
//		while (!isalnum(s[nTail]))
//			--nTail;
//		if (nFront >= nTail)
//			return true;
//		if (s[nFront] != s[nTail])
//			return false;
//		++nFront;
//		--nTail;
//	}
//	return true;
//}
//
//int main()
//{
//	string strs[2] = { "0P" , "race a car" };
//	for (int i = 0; i < 2; i++)
//	{
//		cout << isPalindrome(strs[i]) << endl;
//	}
//	system("pause");
//	return 0;
//}

/*127. Word Ladder */
//bool isAdjacent(string &strF, string &strT)
//{
//	int index = 0;
//	for (int i = 0; i < (int)strF.length(); ++i)
//	{
//		if (strF[i] != strT[i])
//			++index;
//		if (index > 1)
//			return false;
//	}
//	return index == 1;
//}
//
//int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
//{
//	queue<string> que;
//	que.push(beginWord);
//	int res = 0;
//	while (!que.empty())
//	{
//		int nSize = (int)que.size();
//		for (int i = 0; i < nSize; ++i)
//		{
//			string tmp = que.front();
//			que.pop();
//			if (tmp == endWord)
//				return res + 1;
//			for (vector<string>::iterator it = wordList.begin(); it!= wordList.end(); )
//			{
//				if (isAdjacent(*it, tmp))
//				{
//					que.push(*it);
//					it = wordList.erase(it);
//				}
//				else
//					++it;
//			}
//		}
//		++res;
//	}
//	return 0;
//}
//
//int main()
//{
//	string sbegin = "hit";
//	string send = "cog";
//	vector<string> wordList{ "hot","dot","dog","lot","log","cog" };
//	cout << ladderLength(sbegin, send, wordList) << endl;
//	system("pause");
//	return 0;
//}

/*129. Sum Root to Leaf Numbers */
//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//void auxSumNumbers(TreeNode* root, int sum, int &res)
//{
//	if (root == nullptr)
//		return;
//	sum = sum * 10 + root->val;
//	if (root->left == nullptr && root->right == nullptr)
//	{
//		res += sum;
//		return;
//	}
//	else
//	{
//		if (root->left != nullptr)
//		{
//			auxSumNumbers(root->left, sum, res);
//		}
//		if (root->right != nullptr)
//		{
//			auxSumNumbers(root->right, sum, res);
//		}
//	}
//}
//
//int sumNumbers(TreeNode* root) 
//{
//	if (root == nullptr)
//		return 0;
//	int res = 0;
//	auxSumNumbers(root, 0, res);
//	return res;
//}
//
//int main()
//{
//	TreeNode *root = new TreeNode(4);
//	root->left = new TreeNode(9);
//	root->right = new TreeNode(0);
//	root->left->left = new TreeNode(5);
//	root->left->right = new TreeNode(1);
//	cout << sumNumbers(root) << endl;
//	system("pause");
//	return 0;
//}

/*131. Palindrome Partitioning */
//bool isPalindrome(string str)
//{
//	int nf = 0, nt=str.length()-1;
//	while (nf < nt)
//	{
//		if (str[nf++] != str[nt--])
//			return false;
//	}
//	return true;
//}
//
//void auxpartition(vector<vector<string> > &res, vector<string> &tmp, string &s, int pos)
//{
//	if (pos == s.length())
//	{
//		res.push_back(tmp);
//	}
//	for (int i = pos; i < s.length(); ++i)
//	{
//		string substr = s.substr(pos, i - pos + 1);
//		if (isPalindrome(substr))
//		{
//			tmp.push_back(substr);
//			auxpartition(res, tmp, s, i+1);
//			tmp.pop_back();
//		}
//	}
//}
//
//vector<vector<string>> partition(string s) 
//{
//	vector<vector<string> > res;
//	vector<string> tmp;
//	auxpartition(res, tmp, s, 0);
//	return res;
//}
//
//int main()
//{
//	string str = "aab";
//	vector<vector<string> > res = partition(str);
//	for (auto &it : res)
//	{
//		for (auto &iter : it)
//			cout << iter << " ";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

/*234. Palindrome Linked List*/
//struct ListNode
//{
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//
//};
//
//bool isPalindrome(ListNode* head)
//{
//	ListNode* slow = head;
//	ListNode* fast = head;
//	if (slow == NULL || fast->next == NULL)
//		return true;
//	while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL)
//	{
//		slow = slow->next;
//		fast = fast->next->next;
//	}
//	ListNode* middle = new ListNode(slow->next->val);
//	fast = slow->next->next;
//	while (fast != NULL)
//	{
//		ListNode* tmp = fast->next;
//		fast->next = middle;
//		middle = fast;
//		fast = tmp;
//	}
//	slow = head;
//	while (slow != NULL && middle != NULL)
//	{
//		if (slow->val != middle->val)
//			return false;
//		slow = slow->next;
//		middle = middle->next;
//	}
//	return true;
//}
//
//int main()
//{
//	ListNode *link = new ListNode(1);
//	link->next = new ListNode(2);
//	link->next->next = new ListNode(2);
//	link->next->next->next = new ListNode(1);
//	cout << isPalindrome(link) << endl;
//	system("pause");
//	return 0;
//}

/*532. K-diff Pairs in an Array */
//int findPairs(vector<int>& nums, int k) 
//{
//	int res = 0;
//	sort(nums.begin(), nums.end(), [&](const int &A, const int &B) {return A < B; });
//	int left = 0, right = 1;
//	while (right < nums.size())
//	{
//		if (nums[right] - nums[left] < k)
//			++right;
//		else if (nums[right] - nums[left] > k)
//			++left;
//		else
//		{
//			++res;
//			while (++left < nums.size() && nums[left] == nums[left - 1]) {}
//			while (++right < nums.size() && nums[right] == nums[right - 1]) {}
//		}
//		if (left == right)
//			++right;
//	}
//	return res;
//}
//
//int main()
//{
//	vector<int> vec{ 1,3,1,5,4 };
//	cout << findPairs(vec, 0) << endl;
//	system("pause");
//	return 0;
//}