// 트리
// https://www.acmicpc.net/problem/10838

// LCA 먼저 배우고 해야할 느낌? (트리에서 최단 경로 찾기)
// 그래프로 구현하면 시간 초과 날 듯. (최단 경로를 다익스트라로 구하면 개오래걸림;;)


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define INF INT_MAX
#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

class TreeNode {
   public:
    int n;
    int color;
    vector<TreeNode *> childs;
    TreeNode(int _n = 0, int _color = 0) {
        this->n = _n;
        this->color = _color;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    REP(i, 0, K) {
        int r, a, b, c;
        cin >> r;
        switch (r) {
            case 1:  // paint
                cin >> a >> b >> c;
                paint(a, b, c);
                break;
            case 2:  // move
                cin >> a >> b;
                move(a, b);
                break;
            case 3:  // count
                cin >> a >> b;
                count(a, b);
                break;
            default:
                return -1;
        }
    }

    return 0;
}