from cmath import inf

class Solution:
    def firstUniqChar(self, s: str) -> int:
        track = {}
        for i in range(26):
            track[i] = inf

        for i in range(len(s)):
            char = ord(s[i]) - ord('a')
            if not char in track:
                continue
            if track[char] == inf:
                track[char] = i
            else:
                del track[char]

        return min(track.values()) if len(track) > 0 and min(track.values()) != inf else -1

string = "leetcode"
s = Solution
print(s.firstUniqChar(s, string))