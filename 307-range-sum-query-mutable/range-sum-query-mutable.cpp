class NumArray {
    vector<int> tree;
    int n;

    void buildTree(vector<int>& arr, int st, int end, int node) {
        if (st == end) {
            tree[node] = arr[st];
            return;
        }
        int mid = st + (end - st) / 2;
        buildTree(arr, st, mid, 2 * node + 1);
        buildTree(arr, mid + 1, end, 2 * node + 2);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int querySum(int qi, int qj, int si, int sj, int node) {
        // No overlap
        if (qj < si || qi > sj) return 0;
        
        // Complete overlap
        if (si >= qi && sj <= qj) return tree[node];
        
        // Partial overlap
        int mid = si + (sj - si) / 2;
        return querySum(qi, qj, si, mid, 2 * node + 1) +
               querySum(qi, qj, mid + 1, sj, 2 * node + 2);
    }

    void updateVal(int index, int val, int si, int sj, int node) {
        if (si == sj) {
            tree[node] = val;
            return;
        }
        int mid = si + (sj - si) / 2;
        if (index <= mid) {
            updateVal(index, val, si, mid, 2 * node + 1);
        } else {
            updateVal(index, val, mid + 1, sj, 2 * node + 2);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            tree.resize(4 * n);
            buildTree(nums, 0, n - 1, 0);
        }
    }

    void update(int index, int val) {
        if (n > 0) {
            updateVal(index, val, 0, n - 1, 0);
        }
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return querySum(left, right, 0, n - 1, 0);
    }
};
