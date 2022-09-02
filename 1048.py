from ast import List

class Solution:
    def longestStrChain(self, words) -> int:
        res = 1
        dic = {}
        words = sorted(words, key=lambda x: len(x))
        for w in words:
            dic[w] = 1
            for i in range(len(w)):
                sub = w[0:i] + w[i + 1:]
                if sub in dic:
                    dic[w] = max(dic[w], dic[sub] + 1)
            res = max(res, dic[w])
        return res

words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
s = Solution
print(s.longestStrChain(s, words))