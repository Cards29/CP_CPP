#include <iostream>
#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& data) {
        // Build the tree by inserting data at leaf nodes
        for (int i = 0; i < n; ++i) {
            tree[n + i] = data[i];
        }
        // Build the tree by calculating parents
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

public:
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        tree.resize(2 * n);
        build(data);
    }

    void update(int index, int value) {
        // Set value at position p
        index += n;
        tree[index] = value;
        
        // Move upward and update parents
        for (index /= 2; index > 0; index /= 2) {
            tree[index] = tree[2 * index] + tree[2 * index + 1];
        }
    }

    int rangeSum(int left, int right) {
        // Sum over range [left, right)
        int sum = 0;
        left += n;
        right += n;

        while (left < right) {
            if (left & 1) {
                sum += tree[left++];
            }
            if (right & 1) {
                sum += tree[--right];
            }
            left /= 2;
            right /= 2;
        }

        return sum;
    }
};

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    // Range sum query
    std::cout << segTree.rangeSum(1, 3) << std::endl; // Output: 8 (3 + 5)

    // Update
    segTree.update(1, 10);  // Update index 1 to value 10

    // Range sum query after update
    std::cout << segTree.rangeSum(1, 3) << std::endl; // Output: 15 (10 + 5)

    return 0;
}
