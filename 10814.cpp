// 나이순 정렬
// https://www.acmicpc.net/problem/10814

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    
    vector<pair<int, string>> input(N);
    REP(i, 0, N) {
        cin >> input[i].first >> input[i].second;
    }
    stable_sort(input.begin(), input.end(), cmp);
    REP(i, 0, N) {
        cout << input[i].first << " " << input[i].second << endl;
    }


    return 0;
}