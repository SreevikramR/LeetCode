class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        # opening = ['[', '(', '{']
        # closing = [']', ')', '}']
        matching = {'(': ')', '{': '}', '[': ']'}
        for char in s:
            if char in matching:
                stack.append(char)
            else:
                if len(stack) == 0:
                    return False
                if char != matching[stack[-1]]:
                    return False
                stack.pop()
        if len(stack) == 0:
            return True
        return False
        
