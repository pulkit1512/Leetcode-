class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int weight=pq.top();
            pq.pop();
            weight-=pq.top();
            pq.pop();
            if(weight!=0) pq.push(weight);
        }
        if(pq.empty())return 0;
        return pq.top();
    }
};