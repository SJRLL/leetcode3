����һ���ַ������飬����ĸ��λ�������һ����ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ�����

ʾ�� :

���� : ["eat", "tea", "tan", "ate", "nat", "bat"]
��� :
   [
	   ["ate", "eat", "tea"],
	   ["nat", "tan"],
	   ["bat"]
   ]

//����˼·
//��ÿ����ĸ����ord�����õ�ascii��ֵ�������б���ÿ���ַ������õ�һ��ascii���ֵ䣬����
//��������ת��Ϊ�ַ�����������Ϊkey��valueΪ[str[i]]
//�۲�ÿ���ַ����Ƿ����ֵ��У�������ھ��½�һ��ڵĻ��ͽ������key��value,�������dict.values�õ����

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
			 a = '_'.join(r) #����_���Ϸ�ֹ���ظ�������
		 if a not in di :
		 di[a] = [strs[i]]
		 else:
		 di[a].append(strs[i])
			 return list(di.values())
