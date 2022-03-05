#include <boost/algorithm/string.hpp>

class Solution {
public:
    string serialize(TreeNode * root) {
        _serialize(root);
        return boost::join(_segs, "|");
    }

    void _serialize(TreeNode * root) {
        if (root == NULL) {
            _segs.push_back("#");
            return;
        }
        _segs.push_back(std::to_string(root->val));
        _serialize(root->left);
        _serialize(root->right);
    }

    TreeNode * deserialize(string &data) {
        boost::split(_segs, data, boost::is_any_of("|"), boost::token_compress_on);
        TreeNode* root = nullptr;
        int idx = 0;
        _deserialize(&root, idx);
        return root;
    }

    void _deserialize(TreeNode ** root, int& idx) {
        if (idx >= _segs.size() || _segs[idx] == "#") {
            *root = nullptr;
            return;
        }
        *root = new TreeNode(atoi(_segs[idx].c_str()));
        _deserialize(&(*root)->left, ++idx);
        _deserialize(&(*root)->right, ++idx);
    }

    std::vector<std::string> _segs;
};
