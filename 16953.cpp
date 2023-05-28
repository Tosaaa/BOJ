// A -> B
// https://www.acmicpc.net/problem/16953

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

    int A, B;
    cin >> A >> B;

    int cnt = 1;
    while (A < B) {
        if (B % 2 == 0) {
            B /= 2;
            cnt++;
        } else if (B % 10 == 1) {
            B -= 1;
            B /= 10;
            cnt++;
        } else {
            cnt = -1;
            break;
        }
    }
    if (A != B) cnt = -1;
    cout << cnt << endl;

    return 0;
}