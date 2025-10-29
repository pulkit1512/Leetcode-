/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* temp1 = q.front();
                q.pop();
                if (i != n - 1) {
                    temp1->next = q.front();
                } else {
                    temp1->next = NULL;
                }
                if (temp1->left) {
                    q.push(temp1->left);
                }
                if (temp1->right) {
                    q.push(temp1->right);
                }
            }
        }
        return root;
    }
};
