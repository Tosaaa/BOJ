// 수열과 쿼리 15
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

class TreeNode {
   public:
    int idx;
    int val;
    int n;  // # of child nodes
    int l, r;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _idx = 0, int _val = 0, int _l = 0, int _r = 0, TreeNode *_left = NULL, TreeNode *_right = NULL) {
        this->idx = _idx;
        this->val = _val;
        this->l = _l;
        this->r = _r;
        this->left = _left;
        this->right = _right;
    }
};

TreeNode *buildTree(vi &input, int left, int right) {
    if (left == right) {
        TreeNode *root = new TreeNode(left, input[left], left, right);
        return root;
    }
    int mid = (right - left) / 2 + left;
    TreeNode *root = new TreeNode(0, 0, left, right);
    root->left = buildTree(input, left, mid);
    root->right = buildTree(input, mid + 1, right);
    if (root->left->val > root->right->val) {
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
    cout << root->val << endl;
    inorder(root->right);
}

int findMin(TreeNode *root) {
    return root->idx + 1;
}

TreeNode *update(TreeNode *root, int left, int right, int idx, int val) {
    if (root->l == idx && root->r == idx) {
        root->val = val;
        return root;
    }
    int mid = (right - left) / 2 + left;
    if (idx <= mid) {
        root->left = update(root->left, left, mid, idx, val);
    } else {
        root->right = update(root->right, mid + 1, right, idx, val);
    }

    if (root->left->val > root->right->val) {
        root->val = root->right->val;
        root->idx = root->right->idx;
    } else {
        root->val = root->left->val;
        root->idx = root->left->idx;
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vi input(N);
    REP(i, 0, N) {
        cin >> input[i];
    }
    TreeNode *root = buildTree(input, 0, N-1);
    int M;
    cin >> M;
    int a, b, c;
    //inorder(root);
    REP(i, 0, M) {
        cin >> a;
        if (a == 2) {
            cout << findMin(root) << endl;
        } else {
            cin >> b >> c;
            root = update(root, 0, N-1, b-1, c);
        }
    }

    return 0;
}