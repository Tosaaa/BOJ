// N과 M (1)
// https://www.acmicpc.net/problem/15649

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int N, M;
vector<int> arr(8);
void printNM(vector<int> visited, int depth) {
    if (depth == M) {
        REP(i, 0, M) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    REP(i, 0, N) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[depth] = i + 1;
            printNM(visited, depth + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<int> visited(N, 0);
    printNM(visited, 0);
    return 0;
}