// 멀티탭 스케줄링
// https://www.acmicpc.net/problem/1700
// 어렵다!
// 그리디 문제 특징을 잘 알 수 있음. 현재 내가 무엇을 기준으로 최선의 선택을 해야할지 생각해야함.
// 선택할 때 가장 우선순위로 둘 것이 무엇인지 생각하는 게 어려운 부분.
#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> seq(K);
    REP(i, 0, K) {
        cin >> seq[i];
    }

    vector<vector<int>> arr(K, vector<int>(K, 0));

    int pre = seq[K - 1];
    for (int i = K - 2; i >= 0; i--) {
        REP(j, 0, K) {
            arr[i][j] = arr[i + 1][j];
        }
        arr[i][pre - 1] = i + 1;
        pre = seq[i];
    }

    // REP(j, 0, K) {
    //     REP(i, 0, K) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int freeSpace = N;
    int max, idx, ans = 0;
    vector<int> inUse;
    REP(i, 0, K) {
        if (find(inUse.begin(), inUse.end(), seq[i]) != inUse.end())  // already exist
            continue;
        if (freeSpace) {
            freeSpace--;
            inUse.push_back(seq[i]);
            //cout << "plug in: " << seq[i] << endl;
        } else {
            max = 0;
            idx = 0;
            REP(j, 0, inUse.size()) {
                if (max < arr[i][inUse[j] - 1]) {
                    max = arr[i][inUse[j] - 1];
                    idx = j;
                } else if (arr[i][inUse[j] - 1] == 0) {
                    idx = j;
                    break;
                }
            }
            //cout << "plug out: " << inUse[idx] << endl;
            inUse.erase(inUse.begin() + idx);

            //cout << "plug in: " << seq[i] << endl;
            inUse.push_back(seq[i]);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}