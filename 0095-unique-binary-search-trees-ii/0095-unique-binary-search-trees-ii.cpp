#include <vector>
#include <map>

// Definition for a binary tree node. (Provided by LeetCode)
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
    // Memoization map to store previously computed subtrees for a range [start, end]
    std::map<std::pair<int, int>, std::vector<TreeNode*>> memo;

public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    std::vector<TreeNode*> buildTrees(int start, int end) {
        // Base case: If start > end, there are no numbers to form a tree, 
        // so we return a vector containing a single null pointer.
        if (start > end) {
            return {nullptr};
        }

        // Return memoized result if we've already computed trees for this range
        if (memo.count({start, end})) {
            return memo[{start, end}];
        }

        std::vector<TreeNode*> all_trees;

        // Iterate through all values from start to end to pick as the root
        for (int i = start; i <= end; ++i) {
            // Generate all possible left and right subtrees
            std::vector<TreeNode*> left_trees = buildTrees(start, i - 1);
            std::vector<TreeNode*> right_trees = buildTrees(i + 1, end);

            // Connect every possible left subtree with every possible right subtree to the root 'i'
            for (TreeNode* left_node : left_trees) {
                for (TreeNode* right_node : right_trees) {
                    TreeNode* current_root = new TreeNode(i);
                    current_root->left = left_node;
                    current_root->right = right_node;
                    all_trees.push_back(current_root);
                }
            }
        }
        
        // Save the result to our memo map before returning
        return memo[{start, end}] = all_trees;
    }
};