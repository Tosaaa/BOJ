// 단어 정렬
// https://www.acmicpc.net/problem/1181

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

bool cmp(string s1, string s2) {
    if (s1.size() == s2.size())
        return s1 < s2;
    return s1.size() < s2.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<string> s(N);
    REP(i, 0, N) {
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);
    s.erase(unique(s.begin(), s.end()), s.end());
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << (*it) << endl;
    }

    return 0;
}