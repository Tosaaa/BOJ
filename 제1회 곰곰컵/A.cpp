// A번 - 치킨댄스를 추는 곰곰이를 본 임스
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, A, B;
    cin >> N >> A >> B;

    A += 2*B;

    int ans = 0;
    while (N) {
        if (A >= 2) {
            ans++;
            N--;
            A -= 2;
        } else break;
    } 

    cout << ans << endl;

    return 0;
}