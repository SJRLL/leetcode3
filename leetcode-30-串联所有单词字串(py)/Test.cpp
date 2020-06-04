给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。



示例 1：

输入：
s = "barfoothefoobarman",
words = ["foo", "bar"]
输出：[0, 9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9, 0] 也是有效答案。
示例 2：

输入：
s = "wordgoodgoodgoodbestword",
words = ["word", "good", "best", "word"]
输出：[]

///解题思路
//通过滑动窗口在s中从前到后找出长度为words_letter的所有子列表
//在子列表中一个单词一个单词地滑动窗口，然后将一个一个窗口所划分出来的单词填入一个新的列表
//将words和新的列表分别放到哈希表中然后比较这两个哈希表是否相同，如果相同则返回位置

class Solution :
	def findSubstring(self, s: str, words : List[str])->List[int] :
	from collections import Counter
if not s or not words : return[]
		count_words = len(words)
		count_letter = len(words[0])
		words_letter = count_words*count_letter
		len_s = len(s)
		har_words = Counter(words)
		res = []
		for i in range(0, len_s - words_letter + 1) :
			sub_s = s[i:i + words_letter]
			sub_s_words = []
			for j in range(0, words_letter, count_letter) :
				sub_s_words.append(sub_s[j:j + count_letter])
				har_sub_s = Counter(sub_s_words)
			if har_sub_s == har_words :
				res.append(i)
				return res


