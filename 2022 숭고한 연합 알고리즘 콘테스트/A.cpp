// A번: 자동완성
// https://www.acmicpc.net/problem/786/1

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
    
    char c;
    cin >> c;
    if (c == 'N' || c == 'n') cout << "Naver D2" << endl;
    else cout << "Naver Whale" << endl;
    return 0;
}