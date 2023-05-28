// 부분합
// https://www.acmicpc.net/problem/1806

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;
    vi arr(N);
    REP(i, 0, N) {
        cin >> arr[i];
    }

    int s1 = 0, s2 = 1;
    int sum = arr[0];
    int minCnt = 100001;
    while (s1 < N && s2 < N+1) {
        if (sum >= S) {
            if (minCnt > s2 - s1) minCnt = s2 - s1;
            sum -= arr[s1];
            s1++;
        } else {
            sum += arr[s2];
            s2++;
        }
    }
    if (minCnt == 100001) minCnt = 0;
    cout << minCnt << endl;

    return 0;
}