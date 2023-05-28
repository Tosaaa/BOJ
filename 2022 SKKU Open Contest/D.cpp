// D
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

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int N;
    //cin >> N;
    scanf("%d", &N);
    bool found = false;
    int right = N;
    int left = 1;
    int idx = N/2;
    int sheep_cnt = 0;
    REP(i, 0, 20) {
        //cout << "? " << idx << flush;
        printf("? %d\n", idx);
        fflush(stdout);
        //cin >> sheep_cnt;
        scanf("%d", &sheep_cnt);
        if (sheep_cnt > idx/2) {
            //cout << "right" << flush;
            int tmp = (idx + right)/2;
            left = idx;
            idx = tmp;
        } else if (sheep_cnt < (idx+1)/2) {
            //cout << "left" << flush;
            int tmp = (idx + left)/2;
            right = idx;
            idx = tmp;
        } else {
            found = true;
            break;
        }
    }
    if (!found) {
        //cout << "! 0" << flush;
        printf("! 0\n");
        fflush(stdout);
    } else {
        //cout << "! " << idx << flush;
        printf("! %d\n", idx);
        fflush(stdout);
    }

    return 0;
}