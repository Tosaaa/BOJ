// 수 정렬하기, 근데 이제 제곱수를 곁들인
// https://www.acmicpc.net/problem/25323

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

ll gcd(ll a, ll b) {  // assume a >= b
    ll R = a % b;
    if (R == 0) {
        return b;
    }
    return gcd(b, R);
}

bool isSquare(ll N) {
    ll sqrtN = (ll)sqrt(N);
    return sqrtN * sqrtN == N;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<ll> arr(N);
    vector<ll> arr2(N);  // sorted
    REP(i, 0, N) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    sort(arr2.begin(), arr2.end());

    bool isSorted = true;
    REP(i, 0, N) {
        ll g = arr[i] >= arr2[i] ? gcd(arr[i], arr2[i]) : gcd(arr2[i], arr[i]);
        if (!(isSquare(arr[i]/g) && isSquare(arr2[i]/g))) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}