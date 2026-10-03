class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        count =0
        str1=""
        temp=""
        i=0
        while(count<k and i<len(s)):
            if s[i]==' ':
                count+=1
                if count!=k:
                    str1+=' '
            else :
                str1+=s[i]
            i+=1
                
        return str1        
        