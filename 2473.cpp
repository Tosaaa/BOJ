// 세 용액
// https://www.acmicpc.net/problem/2473

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
#define INF LLONG_MAX

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<ll> input(N);
    REP(i, 0, N) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());

    ll sum = INF;
    tuple<ll, ll, ll> ans;

    REP(i, 0, input.size() - 2) {
        int l = i + 1;
        int r = input.size() - 1;
        while (l < r) {
            if (abs(sum) > abs(input[i] + input[l] + input[r])) {
                sum = input[i] + input[l] + input[r];
                ans = {input[i], input[l], input[r]};
            }
            if (input[i] + input[l] + input[r] < 0) {
                l++;
            } else if (input[i] + input[l] + input[r] == 0) {
                break;
            } else {
                r--;
            }
        }
    }
    ll a, b, c;
    tie(a, b, c) = ans;
    cout << a << " " << b << " " << c << endl;

    return 0;
}