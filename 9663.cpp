// N-Queen
// https://www.acmicpc.net/problem/9663

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int N;
int ans = 0;
vector<int> pos(15, 0);  // use from idx 1

void find(int depth) {
    if (depth == N) {
        ans++;
        return;
    }
    REP(i, 1, N + 1) {
        int valid = 1;
        REP(j, 1, depth + 1) {
            if (pos[j] == i || pos[j] - j == i - (depth + 1) || pos[j] + j == i + depth + 1) {
                valid = 0;
                break;
            }
        }
        if (!valid) continue;
        pos[depth + 1] = i;
        find(depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    find(0);

    cout << ans << endl;
    return 0;
}