给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例 :

输入 : ["eat", "tea", "tan", "ate", "nat", "bat"]
输出 :
   [
	   ["ate", "eat", "tea"],
	   ["nat", "tan"],
	   ["bat"]
   ]

//解题思路
//将每个字母利用ord函数得到ascii码值，对于列表里每个字符串都得到一串ascii码字典，排序
//将排序结果转换为字符串，排序结果为key，value为[str[i]]
//观察每个字符串是否在字典中，如果不在就新建一项，在的话就将扩充该key的value,最后利用dict.values得到结果

class Solution :
		 def groupAnagrams(self, strs: List[str])->List[List[str]] :
		 di = {}
	 for i in range(len(strs)) :
		 r = []
		 for j in strs[i] :
			 r.append(ord(j))
			 r.sort()
		 for k in range(len(r)) :
			 r[k] = str(r[k])
			 a = '_'.join(r) #利用_隔断防止有重复的数字
		 if a not in di :
		 di[a] = [strs[i]]
		 else:
		 di[a].append(strs[i])
			 return list(di.values())
