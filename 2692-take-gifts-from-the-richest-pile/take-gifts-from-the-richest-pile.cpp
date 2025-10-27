class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        while(k--){
            long long x=sqrt(pq.top());
            pq.pop();
            if(x)pq.push(x);
        }
         while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
         }
         return ans;
    }
};