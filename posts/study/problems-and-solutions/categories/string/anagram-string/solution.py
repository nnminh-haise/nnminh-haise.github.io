class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        f = [0] * 26
        g = [0] * 26
        for i in s:
            f[ord(i) - 97] += 1
        for i in t:
            g[ord(i) - 97] += 1
        if f==g:
            return True
        else:
            return False
