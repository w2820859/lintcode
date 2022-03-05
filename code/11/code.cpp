class Solution {
public:
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        _k1 = k1;
        _k2 = k2;
        _res.clear();
        _res.reserve(1000000);
        recur(root);
        return _res;
    }

    void recur(TreeNode * root) {
        if (root == nullptr) return;
        if (root->val > _k1) recur(root->left);
        if (root->val >= _k1 && root->val <= _k2) _res.push_back(root->val);
        if (root->val < _k2) recur(root->right);
    }

private:
    int _k1;
    int _k2;
    std::vector<int> _res;
};
