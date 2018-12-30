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

/*28. Implement strStr() */

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