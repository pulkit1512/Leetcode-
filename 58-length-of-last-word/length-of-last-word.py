class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i=len(s)-1
        ans=""
        while(i>=0):
            while s[i]==' ' and i>=0 and len(ans)==0:
                i-=1
            if s[i]==' ' and len(ans)!=0:
                break
            ans+=s[i]
            i-=1
        return len(ans)        