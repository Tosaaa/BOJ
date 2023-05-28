// 부분수열의 합 2
// https://www.acmicpc.net/problem/1208

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

void comb(vi &visited, vector<ll> &arr, vector<ll> &sum, int depth, int e, int s) {
    if (depth == e) {
        ll tmp = 0;
        REP(i, 0, arr.size()) {
            if (visited[i]) {
                tmp += arr[i];
            }
        }
        sum.push_back(tmp);
        return;
    }
    REP(i, s, arr.size()) {
        if (!visited[i]) {
            visited[i] = 1;
            comb(visited, arr, sum, depth + 1, e, i + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;
    vector<ll> arr1;
    vector<ll> arr2;
    REP(i, 0, N) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            arr1.push_back(a);
        } else {
            arr2.push_back(a);
        }
    }

    vector<ll> sum1;
    vector<ll> sum2;

    vi visited1(arr1.size(), 0);
    vi visited2(arr2.size(), 0);
    REP(i, 1, arr1.size() + 1) {
        comb(visited1, arr1, sum1, 0, i, 0);
    }
    REP(i, 1, arr2.size() + 1) {
        comb(visited2, arr2, sum2, 0, i, 0);
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());

    ll ans = 0;
    REP(i, 0, sum1.size())
        if (sum1[i] == S) ans++;

    REP(i, 0, sum2.size())
        if (sum2[i] == S) ans++;

    REP(i, 0, sum1.size()) {
        ll s1 = sum1[i];

        ll l = lower_bound(sum2.begin(), sum2.end(), S - s1) - sum2.begin();
        ll u = upper_bound(sum2.begin(), sum2.end(), S - s1) - sum2.begin();
        if (l != u) {
            ans += u-l;
        }
    }

    cout << ans << endl;

    return 0;
}