给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1 :

输入 : s = "anagram", t = "nagaram"
输出 : true
	 示例 2 :

 输入 : s = "rat", t = "car"
  输出 : false

//解题思路：为字符串s, t设置两个辅助数组a、b，用来统计字母出现次数。

class Solution {
	 public:
		 bool isAnagram(string s, string t) 
		 {
			 int a[26] = { 0 }, b[26] = { 0 };
			 int lengths = s.length();
			 int lengtht = t.length();
			 for (int i = 0; i<lengths; ++i)
			 {
				 a[s[i] - 'a']++;
			 }
			 for (int i = 0; i<lengtht; ++i)
			 {
				 b[t[i] - 'a']++;
			 }
			 //比较
			 for (int i = 0; i<26; ++i)
			 {
				 if (a[i] != b[i])
					 return false;
			 }
			 return true;
		 }
};

