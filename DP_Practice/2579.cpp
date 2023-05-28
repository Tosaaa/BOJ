// 계단 오르기
// https://www.acmicpc.net/problem/2579

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // s1[x] = s[x-3] + p[x-1] + p[x]
    // s2[x] = s[x-2] + p[x]
    // s[x] = max(s1[x], s2[x])

    int N;
    cin >> N;

    int p[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    vector<int> s(N + 1);
    s[0] = 0;
    s[1] = p[1];
    s[2] = p[1] + p[2];
    for (int x = 3; x <= N; x++) {
        s[x] = max(s[x - 3] + p[x - 1] + p[x], s[x - 2] + p[x]);
        // cout << "s[" << x << "]: " << s[x] << endl;
    }

    cout << s[N] << endl;

    return 0;
}