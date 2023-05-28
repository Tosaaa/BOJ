// 거짓말
// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <set>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int n;
    cin >> n;
    set<int> know;
    int tmp;
    REP(i, 0, n) {
        cin >> tmp;
        know.insert(tmp);
    }

    vector<vector<int>> party(M);
    int m;
    REP(i, 0, M) {
        cin >> m;
        REP(j, 0, m) {
            int tmp;
            cin >> tmp;
            party[i].push_back(tmp);
        }
    }

    // REP(i, 0, party.size()) {
    //     REP(j, 0, party[i].size()) {
    //         cout << party[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (auto it = know.begin(); it != know.end(); it++) {
    //     cout << (*it) << " ";
    // }
    // cout << endl;

    int valid = 0;
    int preKnowSize = -1;
    int usoCnt = 0;
    while (preKnowSize != know.size()) {
        preKnowSize = know.size();
        usoCnt = 0;
        REP(i, 0, M) {
            valid = 0;
            REP(j, 0, party[i].size()) {
                if (know.find(party[i][j]) != know.end()) {
                    valid = 1;
                    break;
                }
            }
            if (valid) {
                REP(j, 0, party[i].size()) {
                    know.insert(party[i][j]);
                }
            } else {
                usoCnt++;
            }
        }
    }

    // for (auto it = know.begin(); it != know.end(); it++) {
    //     cout << (*it) << " ";
    // }
    // cout << endl;

    cout << usoCnt << endl;

    return 0;
}