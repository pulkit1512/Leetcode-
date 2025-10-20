class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> p;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            p.push(nums[i]);
            if (p.size() > k) {
                p.pop();
            }
        }
    }

    int add(int val) {
        p.push(val);
        if (p.size() > k) {
            p.pop();
        }
        return p.top();
    }
};
