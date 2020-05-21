//题目描述：
运用你所掌握的数据结构，设计和实现一个  LRU(最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥(key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 - 1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥 / 数据值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

//解题思路
//1.导入OrderedDict, 并建立有序字典
//2.熟悉OrderedDict方法
//3.按题意写代码

from collections import OrderedDict
class LRUCache :

	def __init__(self, capacity: int) :
	self.maxsize = capacity
	self.lrucache = OrderedDict()
	def get(self, key: int) -> int :
if key in self.lrucache :
self.lrucache.move_to_end(key)
return self.lrucache.get(key, -1)
def put(self, key: int, value : int)->None :
if key in self.lrucache :
del self.lrucache[key]
self.lrucache[key] = value
if len(self.lrucache)>self.maxsize:
self.lrucache.popitem(last = False)

//# Your LRUCache object will be instantiated and called as such :
//# obj = LRUCache(capacity)
//# param_1 = obj.get(key)
//# obj.put(key, value)
