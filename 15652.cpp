// N과 M (4)
// https://www.acmicpc.net/problem/15652

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int N, M;
vector<int> arr(8);
void printNM(int s, int depth) {
    if (depth == M) {
        REP(i, 0, M) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    REP(i, s, N) {
        arr[depth] = i + 1;
        printNM(i, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    printNM(0, 0);
    return 0;
}