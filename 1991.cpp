// 트리 순회
// https://www.acmicpc.net/problem/1991

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

class TreeNode {
   public:
    int val;
    int n;  // # of nodes (including node itself)
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val = 0, TreeNode *_left = NULL, TreeNode *_right = NULL) {
        this->val = _val;
        this->n = 1;
        this->left = _left;
        this->right = _right;
    }
};

void preorder(TreeNode *root) {
    if (root == NULL) return;
    cout << (char)root->val;
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << (char)root->val;
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << (char)root->val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<TreeNode *> nodes;
    TreeNode *A = new TreeNode('A');
    nodes.push_back(A);
    char a, b, c;
    REP(i, 0, N) {
        cin >> a >> b >> c;
        int n = nodes.size();
        REP(j, 0, n) {
            if (nodes[j]->val == (int)a) {
                if (b != '.') {
                    TreeNode *tmp = new TreeNode((int)b);
                    nodes[j]->left = tmp;
                    nodes.push_back(tmp);
                }
                if (c != '.') {
                    TreeNode *tmp = new TreeNode((int)c);
                    nodes[j]->right = tmp;
                    nodes.push_back(tmp);
                }
                break;
            }
        }
    }

    preorder(nodes[0]);
    cout << endl;
    inorder(nodes[0]);
    cout << endl;
    postorder(nodes[0]);
    cout << endl;

    return 0;
}