class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        for ch in s:
            if ch.isalnum()==False:        
                s = s.replace(ch, "")
        
        s=s.lower()

        if s == s[::-1]:
            return True
        else:
            return False