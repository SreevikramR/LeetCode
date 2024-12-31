class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        hashMap = {}
        for char in s:
            if char in hashMap:
                hashMap[char] += 1
            else:
                hashMap[char] = 1
        
        for char in t:
            if char in hashMap:
                if hashMap[char] == 0:
                    return False
                if hashMap[char] == 1:
                    hashMap.pop(char)
                else:
                    hashMap[char] -= 1
            else:
                return False
            
        return len(hashMap) == 0
