from ast import List

class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        while i < len(chars):
            currChar = chars[i]
            cnt = 1
            i += 1
            back = i
            while i < len(chars) and chars[i] == currChar:
                cnt += 1
                i += 1
            if cnt > 1:
                for x in str(cnt):
                    chars[back] = x
                    back += 1
            del chars[back:i]
            i -= i - back
        return len(chars)