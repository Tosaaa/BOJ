// 구간 합 구하기
// https://www.acmicpc.net/problem/2042

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
    int l, r;
    TreeNode *left;
    TreeNode *right;
    TreeNode(ll _val = 0, int _l = 0, int _r = 0, TreeNode *_left = NULL, TreeNode *_right = NULL) {
        this->val = _val;
        this->l = _l;
        this->r = _r;
        this->left = _left;
        this->right = _right;
    }
};

TreeNode *buildTree(vector<ll> &input, int left, int right) {
    if (left == right) {
        TreeNode *root = new TreeNode(input[left], left, right);
        return root;
    }
    int mid = (right - left) / 2 + left;
    TreeNode *root = new TreeNode(0, left, right);
    root->left = buildTree(input, left, mid);
    root->right = buildTree(input, mid + 1, right);
    root->val = root->left->val + root->right->val;
    return root;
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << endl;
    inorder(root->right);
}

ll findSum(TreeNode *root, int left, int right) {
    if (left == root->l && right == root->r) return root->val;
    // if (left >= root->l && right <= root->r)
    int mid = (root->r - root->l) / 2 + root->l;
    if (right <= mid) {
        return findSum(root->left, left, right);
    } else if (left > mid) {
        return findSum(root->right, left, right);
    } else {
        ll sum = 0;
        sum += findSum(root->left, left, mid);
        sum += findSum(root->right, mid + 1, right);
        return sum;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> input(N);
    REP(i, 0, N) {
        cin >> input[i];
    }

    TreeNode *root = buildTree(input, 0, N - 1);

    int a, b;
    ll c;
    REP(i, 0, M + K) {
        cin >> a >> b >> c;
        if (a == 1) {
            root = update(root, 0, N - 1, b - 1, c);
        } else {
            cout << findSum(root, b - 1, c - 1) << endl;
        }
    }

    return 0;
}