// 음계
// https://www.acmicpc.net/problem/2920

#include <iostream>

#define REP(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int arr[8];
    REP(i, 0, 8) {
        cin >> arr[i];
    }

    int state = 0; // 1: increasing, 2: decreasing, 3: mixed;
    if (arr[0] < arr[1]) state = 1;
    else state = 2;
    REP(i, 1, 8) {
        if (state == 1) {
            if (arr[i] < arr[i-1]) {
                state = 3;
                break;
            }
        } else  {
            if (arr[i] > arr[i-1]) {
                state = 3;
                break;
            }
        }
    }

    if (state == 1) cout << "ascending" << endl;
    else if (state == 2) cout << "descending" << endl;
    else cout << "mixed" << endl;

    return 0;
}