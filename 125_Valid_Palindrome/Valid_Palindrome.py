class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = ''.join(char for char in s if char.isalnum())
        if len(string) == 0 or len(string) == 1:
            return True
        for i in range(len(string) // 2):
            if (string[i]).lower() != (string[-i-1]).lower():
                return False
        return True
