// N과 M (9)
// https://www.acmicpc.net/problem/15663

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int N, M;
vector<int> arr(8);
vector<int> input;

void printNM(vector<int> visited, int depth) {
    if (depth == M) {
        REP(i, 0, M) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    int bef = -1;
    REP(i, 0, N) {
        if (!visited[i] && bef != input[i]) {
            visited[i] = 1;
            arr[depth] = input[i];
            printNM(visited, depth + 1);
            visited[i] = 0;
            bef = input[i];
        }
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
    vector<int> visited(N, 0);
    printNM(visited, 0);
    return 0;
}