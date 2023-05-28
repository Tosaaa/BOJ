// 평범한 배낭
// https://www.acmicpc.net/problem/12865

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)

using namespace std;

int main() {
    // S(x, k) = max(S(x-1, k) , S(x-1, k-w(x)) + v(x));
    // x: x번째 물건까지 살펴봄
    // k: 전체 가방 용량이 k
    /* 
    Standard 냅색 문제.

    무게 오름차순으로 sort하고, 가방 용량이 k일 때 앞 x개로 만들 수 있는 최대 가치 = S(x, k)
    이 때, k가 w(x)보다 크다면, k가 포함되는 경우가 있을 수 있음.
    k가 포함되는 경우는, 가방 용량이 k - w(x)일 때 앞 x-1개로 만들 수 있는 최대 가치(S(x-1, k - w(x)) + v(x))
    k가 포함되지 않는 경우는 가방 용량이 k일 때 앞 x-1로 만들 수 있는 최대 가치(S(x-1, k))임.
    따라서 이 둘 중 더 큰 값을 취하면 됨.
    */
   
    int N, K;
    cin >> N >> K;

    pair<int, int> arr[100];
    REP(i, 1, N + 1) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + N + 1);

    // REP(i, 1, N+1) {
    //     cout << arr[i].first << " " << arr[i].second << endl;
    // }

    vector<vector<int>> S(N + 1, vector<int>(K + 1, 0));

    REP(x, 1, N + 1) {
        REP(k, 1, K + 1) {
            if (k - arr[x].first >= 0) {
                S[x][k] = max(S[x - 1][k], S[x - 1][k - arr[x].first] + arr[x].second);
            } else {
                S[x][k] = S[x - 1][k];
            }
        }
    }

    cout << S[N][K] << endl;

    return 0;
}