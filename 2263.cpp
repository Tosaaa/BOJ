// 트리의 순회
// https://www.acmicpc.net/problem/2263

#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int N;
vector<int> in;
vector<int> post;
vector<int> pre;

void findPreorder(int s, int e, int idx) {
    if (s > e) return;
    //cout << s << " " << e << " " << idx << endl;
    pre.push_back(post[idx]);
    //cout << "push back: " << post[idx] << endl;
    int root = s;
    int cnt = 0;
    REP(i, s, e + 1) {
        cnt++;
        if (in[i] == post[idx]) {
            root = i;
            break;
        }
    }
    findPreorder(s, root - 1, idx - (e - s) + cnt - 2);
    findPreorder(root + 1, e, idx - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int a;
    REP(i, 0, N) {
        cin >> a;
        in.push_back(a);
    }
    REP(i, 0, N) {
        cin >> a;
        post.push_back(a);
    }

    findPreorder(0, N - 1, N - 1);

    REP(i, 0, N) {
        cout << pre[i] << " ";
    }
    cout << endl;

    return 0;
}