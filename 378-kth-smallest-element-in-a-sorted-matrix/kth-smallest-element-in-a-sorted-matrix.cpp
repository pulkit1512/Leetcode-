#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                pq.push(matrix[i][j]);
            }
        }

        for (int i = 1; i < k; i++) {
            pq.pop();
        }

        return pq.top(); 
    }
};
