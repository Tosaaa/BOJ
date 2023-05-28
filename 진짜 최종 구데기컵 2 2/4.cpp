// 4
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

    int n, q;
    scanf("%d %d", &n, &q);
    int cc = n;
    REP(i, 0, q) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            printf("%d\n", 0);
            fflush(stdout);
        }
        else {
            printf("%d\n", 0);
            fflush(stdout);
        }
    }

    return 0;
}