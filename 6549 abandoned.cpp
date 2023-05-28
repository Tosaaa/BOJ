// 히스토그램에서 가장 큰 직사각형
// https://www.acmicpc.net/problem/6549

#include <algorithm>
#include <iostream>
#include <map>
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

    int N;

    while (1) {
        cin >> N;
        vi height(N);
        if (N == 0) break;
        REP(i, 0, N) {
            cin >> height[i];
        }
        vi maxS(N + 1, 0);
        map<int, int> vt;
        vt.insert({height[0], 1});
        maxS[1] = height[0];
        REP(i, 1, N) {
            for (auto it = vt.begin(); it != vt.end(); it++) {
                int h = it->first;
                int w = it->second;
                if (h < height[i]) {
                    
                }
                auto it2 = vt.find(min(h, height[i]));
                if (it2 != vt.end()) {
                    if (it2->second < w + 1)
                        it2->second = w + 1;
                }
                if (vt.insert({min(h, height[i]), w + 1}).second) {
                    vt.erase(it);
                } else {
                    it--;
                }
            }
            if (height[i - 1] < height[i])
                vt.insert({height[i], 1});
            for (auto it = vt.begin(); it != vt.end(); it++) {
                int h = it->first;
                int w = it->second;
                if (maxS[w] < h * w) {
                    maxS[w] = h * w;
                }
            }
        }
        int ans = 0;
        REP(i, 1, N + 1) {
            if (ans < maxS[i])
                ans = maxS[i];
        }
        cout << ans << endl;
    }

    return 0;
}