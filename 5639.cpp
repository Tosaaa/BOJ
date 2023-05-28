// 이진 검색 트리
// https://www.acmicpc.net/problem/5639

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

class BinaryTree {
   private:
    TreeNode *root;

    int getN(TreeNode *root) {
        if (root == NULL) return 0;
        return root->n;
    }

    TreeNode *addNodeUtil(TreeNode *root, int _val) {
        if (root == NULL) {
            TreeNode *node = new TreeNode(_val);
            return node;
        } else if (root->val > _val) {
            root->left = addNodeUtil(root->left, _val);
        } else if (root->val < _val) {
            root->right = addNodeUtil(root->right, _val);
        }
        root->n = getN(root->left) + getN(root->right) + 1;
        return root;
    }

    TreeNode *getNodeUtil(TreeNode *root, int _val) {
        if (root == NULL) {
            return NULL;
        } else if (root->val > _val) {
            return getNodeUtil(root->left, _val);
        } else if (root->val < _val) {
            return getNodeUtil(root->right, _val);
        } else if (root->val == _val) {
            return root;
        }
        return root;  // 사실 필요 X
    }

    void printInorderUtil(TreeNode *root) {
        if (root == NULL) return;
        printInorderUtil(root->left);
        cout << root->val << endl;
        printInorderUtil(root->right);
    }

    void printPostorderUtil(TreeNode *root) {
        if (root == NULL) return;
        printPostorderUtil(root->left);
        printPostorderUtil(root->right);
        cout << root->val << endl;
    }

    void delTree(TreeNode *root) {
        if (root == NULL) return;
        delTree(root->left);
        delTree(root->right);
        delete root;
    }

   public:
    BinaryTree(int _val) {
        root = new TreeNode(_val);
    }

    BinaryTree() {
        root = NULL;
    }

    ~BinaryTree() {
        delTree(root);
    }

    TreeNode *getRoot() {
        return root;
    }

    int getSize() {
        return root->n;
    }

    void addNode(int _val) {
        root = addNodeUtil(root, _val);
    }

    TreeNode *getNode(int _val) {
        return getNodeUtil(root, _val);
    }

    bool isExist(int _val) {
        if (getNodeUtil(root, _val) == NULL) {
            return false;
        }
        return true;
    }

    void printInorder() {
        printInorderUtil(root);
    }

    void printPostorder() {
        printPostorderUtil(root);
    }
    // void delNode();
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    BinaryTree *bst = new BinaryTree();

    int val;
    while (!cin.eof()) {
        cin >> val;
        bst->addNode(val);
    }

    bst->printPostorder();

    delete bst;

    return 0;
}