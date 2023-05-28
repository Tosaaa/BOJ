// N과 M (8)
// https://www.acmicpc.net/problem/15657

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int N, M;
vector<int> arr(8);
vector<int> input;

void printNM(int s, int depth) {
    if (depth == M) {
        REP(i, 0, M) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    REP(i, s, N) {
        arr[depth] = input[i];
        printNM(i, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    REP(i, 0, N) {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    sort(input.begin(), input.end());
    printNM(0, 0);
    return 0;
}