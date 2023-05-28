// N수매화검법
// https://www.acmicpc.net/problem/25315

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

typedef struct slash_struct {
    ll x1, y1, x2, y2, w;
} slash;

bool cmp(slash a, slash b) {
    return a.w < b.w;
}

bool isCross(slash a, slash b) {
    ll sign1 = (a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1);
    ll sign2 = (a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1);
    ll sign3 = (b.x2 - b.x1) * (a.y1 - b.y1) - (a.x1 - b.x1) * (b.y2 - b.y1);
    ll sign4 = (b.x2 - b.x1) * (a.y2 - b.y1) - (a.x2 - b.x1) * (b.y2 - b.y1);
    if ((sign1 > 0 && sign2 < 0 || sign1 < 0 && sign2 > 0) && (sign3 > 0 && sign4 < 0 || sign3 < 0 && sign4 > 0)) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<slash> s(N);
    REP(i, 0, N) {
        cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2 >> s[i].w;
    }

    sort(s.begin(), s.end(), cmp);
    ll ans = 0;
    REP(i, 0, N) {
        int m = 0;
        REP(j, i + 1, N) {
            if (isCross(s[i], s[j])) m++;
        }
        ans += (m + 1) * s[i].w;
    }
    
    cout << ans << endl;

    return 0;
}