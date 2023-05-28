// 가장 가까운 공통 조상
// https://www.acmicpc.net/problem/3584

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

struct TreeNode {
    int idx;
    int val;
    //vector<TreeNode *> child;
    TreeNode *parent;
};

int getLCA(vector<TreeNode *> nodes, int a, int b) {
    TreeNode *aNode = nodes[a];
    TreeNode *bNode = nodes[b];
    vi visited(nodes.size(), 0);

    while (1) {
        if (aNode != nullptr) {
            visited[aNode->idx]++;
            if (visited[aNode->idx] > 1) {
                return aNode->idx + 1;
            }
            aNode = aNode->parent;
        }

        if (bNode != nullptr) {
            visited[bNode->idx]++;
            if (visited[bNode->idx] > 1) {
                return bNode->idx + 1;
            }
            bNode = bNode->parent;
        }
        if (aNode == nullptr && bNode == nullptr)
            return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    REP(tc, 0, T) {
        int N;
        cin >> N;
        vector<TreeNode *> nodes;
        REP(i, 0, N) {
            TreeNode *node = new TreeNode;
            node->idx = i;
            node->val = 0;
            //node->child.clear();
            node->parent = nullptr;
            nodes.push_back(node);
        }
        int a, b;
        REP(i, 0, N-1) {
            cin >> a >> b;
            //nodes[a - 1]->child.push_back(nodes[b - 1]);
            nodes[b - 1]->parent = nodes[a - 1];
        }
        cin >> a >> b;
        cout << getLCA(nodes, a - 1, b - 1) << endl;
    }

    return 0;
}