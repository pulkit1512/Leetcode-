class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       int maxi=0,l=0,r=0;
       for(int i=0;i<k;i++){
        l+=cardPoints[i];
       }
       maxi=l;
       int index=cardPoints.size()-1;
       for(int i=k-1;i>=0;i--){
           l-=cardPoints[i];
           r+=cardPoints[index];
           maxi=max(maxi,l+r);
           index--;
       }
       return maxi ;
    }
};