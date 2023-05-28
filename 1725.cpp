// 히스토그램
// https://www.acmicpc.net/problem/1725

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

class TreeNode {
   public:
    ll val;
    int idx;
    int l, r;
    TreeNode *left;
    TreeNode *right;
    TreeNode(ll _val = 0, int _l = 0, int _r = 0, int _idx = -1, TreeNode *_left = NULL, TreeNode *_right = NULL) {
        this->val = _val;
        this->l = _l;
        this->r = _r;
        this->idx = _idx;
        this->left = _left;
        this->right = _right;
    }
};

TreeNode *buildTree(vector<ll> &input, int left, int right) {
    if (left == right) {
        TreeNode *root = new TreeNode(input[left], left, right, left);
        return root;
    }
    int mid = (right - left) / 2 + left;
    TreeNode *root = new TreeNode(0, left, right);
    root->left = buildTree(input, left, mid);
    root->right = buildTree(input, mid + 1, right);
    if (root->left->val >= root->right->val) {
        root->val = root->right->val;
        root->idx = root->right->idx;
    } else {
        root->val = root->left->val;
        root->idx = root->left->idx;
    }
    return root;
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << "val, idx, l, r: " << root->val << root->idx << root->l << root->r << endl;
    inorder(root->right);
}

pair<ll, int> findMin(TreeNode *root, int left, int right) {
    if (left == root->l && right == root->r) return {root->val, root->idx};
    // if (left >= root->l && right <= root->r)
    int mid = (root->r - root->l) / 2 + root->l;
    if (right <= mid) {
        return findMin(root->left, left, right);
    } else if (left > mid) {
        return findMin(root->right, left, right);
    } else {
        pair<ll, int> s1 = findMin(root->left, left, mid);
        pair<ll, int> s2 = findMin(root->right, mid + 1, right);
        return s1.first > s2.first ? s2 : s1;
    }
}

TreeNode *update(TreeNode *root, int left, int right, int idx, ll val) {
    if (root->l == idx && root->r == idx) {
        root->val = val;
        return root;
    }
    int mid = (right - left) / 2 + left;
    if (idx <= mid) {
        root->left = update(root->left, left, mid, idx, val);
        root->val = root->left->val + root->right->val;
    } else {
        root->right = update(root->right, mid + 1, right, idx, val);
        root->val = root->left->val + root->right->val;
    }
    return root;
}

ll findMaxRect(TreeNode *root, int left, int right) {
    if (left > right) return 0;
    pair<ll, int> p = findMin(root, left, right);
    ll s0 = p.first * (right - left + 1);
    ll s1 = findMaxRect(root, left, p.second - 1);
    ll s2 = findMaxRect(root, p.second + 1, right);
    return max(max(s0, s1), s2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<ll> input(N);
    REP(i, 0, N) {
        cin >> input[i];
    }

    TreeNode *root = buildTree(input, 0, N - 1);
    ll ans = findMaxRect(root, 0, N - 1);
    cout << ans << endl;

    return 0;
}