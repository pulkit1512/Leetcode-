class Solution {
public:
    int helper(int n, int k, int index, vector<bool>& visited,
               int person_left) {
        if (person_left == 1) {
            return index;
        }
        // person we have to kill
        int kill = (k - 1) % person_left;
        while (kill--) {
            index = (index + 1) % n;
            // skip the dead index means that index which are already out of the
            // game
            while (visited[index] == 1)
                index = (index + 1) % n;
        }
        visited[index] = 1;
        // find the next alive person
        while (visited[index] == 1) {
            index = (index + 1) % n;
        }
        return helper(n, k, index, visited, person_left - 1);
    }

    int findTheWinner(int n, int k) {
        vector<bool> visited(n, 0);
        return helper(n, k, 0, visited, n) + 1;
    }
};