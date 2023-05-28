// 주식
// https://www.acmicpc.net/problem/11501

#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

// arr를 끝에서부터 앞으로 오면서 최대 값들을 마킹해놓으면 됨. (max_arr 필요 없음;;)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    REP(t, 0, T) {
        int N;
        cin >> N;

        vector<short> arr(N);
        REP(i, 0, N) {
            cin >> arr[i];
        }

        vector<pair<int, short>> max_arr;
        REP(i, 0, N-1) {
            if (arr[i] > arr[i+1]) {
                max_arr.push_back({i,arr[i]});
            }
        }
        max_arr.push_back({N-1, arr[N-1]});

        // REP(i, 0, max_arr.size()) {
        //     cout << max_arr[i].first << " " << max_arr[i].second << endl;
        // }

        vector<pair<int, short>> max_arr2;
        short M = max_arr[max_arr.size()-1].second;
        max_arr2.push_back({max_arr[max_arr.size()-1].first, M});
        for (int i = max_arr.size()-2; i >= 0; i--) {
            if (M <= max_arr[i].second) {
                M = max_arr[i].second;
                max_arr2.push_back({max_arr[i].first, M});
            }
        }

        // cout << endl;

        reverse(max_arr2.begin(), max_arr2.end());
        
        // REP(i, 0, max_arr2.size()) {
        //     cout << max_arr2[i].first << " " << max_arr2[i].second << endl;
        // }

        long long sum = 0;
        short peak = max_arr2[0].second;
        int idx = 0;
        REP(i, 0, N) {
            if (arr[i] < peak) {
                sum += peak - arr[i];
                // cout << "peak, arr[i]: " << peak << " " << arr[i] << endl;
                // cout << "now sum: " << sum << endl;
            } else if (arr[i] == peak) {
                // cout << i << endl;
                if (idx + 1 != max_arr2.size())
                    peak = max_arr2[++idx].second;
            }
        }

        cout << sum << endl;
    }


    return 0;
}