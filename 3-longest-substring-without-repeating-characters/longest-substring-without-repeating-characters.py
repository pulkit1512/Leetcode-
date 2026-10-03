class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        d = {}
        first = 0
        second = 0
        maxi = 0
        
        while second < n:
            char = s[second]
            d[char] = d.get(char, 0) + 1
            
            while d[char] > 1:
                d[s[first]] -= 1
                first += 1
                
            maxi = max(maxi, second - first + 1)
            second += 1
            
        return maxi