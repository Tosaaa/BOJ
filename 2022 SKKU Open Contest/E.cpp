// E
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

int S, T;
vi dp(T);
vi visited(T);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> S >> T;
    int sum = 0;
    REP(i, 1, T+1) {
        int a = T / i;
        if (i % 2 == 1) sum -=a;
        else sum += a;
    }

    REP(i, 1, S) {
        int a = (S-1) / i;
        if (i % 2 == 1) sum +=a;
        else sum -= a;
    }
    
    cout << sum << endl;
    return 0;
}