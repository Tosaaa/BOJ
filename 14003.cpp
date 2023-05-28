// 가장 긴 증가하는 부분 수열 5
// https://www.acmicpc.net/problem/14003

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

class Node {
   public:
    ll num;
    Node *prev;
    Node(ll _num) {
        num = _num;
        prev = NULL;
    }
};

bool cmp(Node *a, Node *b) {
    return a->num < b->num;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<Node *> v;
    int ans = 0;
    int a;
    REP(i, 0, N) {
        cin >> a;
        Node *node = new Node(a);
        if (v.empty()) {
            v.push_back(node);
            ans++;
        }
        else if (v.back()->num < a) {
            node->prev = v.back();
            v.push_back(node);
            ans++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), node, cmp);
            if (it != v.begin()) {
                node->prev = (*(it-1));
            }
            (*it) = node;
        }
    }
    vi arr;
    Node *walk = v.back();
    while (walk != NULL) {
        arr.push_back(walk->num);
        walk = walk->prev;
    }
    reverse(arr.begin(), arr.end());

    cout << ans << endl;
    REP(i, 0, ans) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}