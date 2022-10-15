from cmath import inf

class Solution:
    def longestPalindrome(self, s: str) -> int:
        res = len(s)
        dic = {}
        for x in s:
            dic.setdefault(x, 0)
            dic[x] += 1
        flag = False
        for x in dic.values():
            if x % 2 != 0:
                res -= 1
                flag = True
        if flag:
            res += 1
        return res
        