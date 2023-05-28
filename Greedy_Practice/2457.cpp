// 공주님의 정원
// https://www.acmicpc.net/problem/2457

#include <algorithm>
#include <iostream>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'

using namespace std;

bool cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    if (a.first.first == b.first.first) {
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

bool cmpDay(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second <= b.second;
    }
    return a.first < b.first;
}

pair<int, int> minusOneDay(pair<int, int> day) {
    if (day.second > 1) return make_pair(day.first, day.second - 1);

    switch (day.first) {
        case 5:
        case 7:
        case 10:
        case 12:
            return make_pair(day.first - 1, 30);
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
        case 1:
            return make_pair(day.first - 1, 31);
        case 3:
            return make_pair(day.first - 1, 28);
        default:
            cout << "????" << endl;
            return make_pair(-1, -1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<pair<pair<int, int>, pair<int, int>>> days(N);
    REP(i, 0, N) {
        cin >> days[i].first.first >> days[i].first.second >> days[i].second.first >> days[i].second.second;
    }
    sort(days.begin(), days.end(), cmp);

    // cout << endl;
    // REP(i, 0, N) {
    //     cout << days[i].first.first << " " << days[i].first.second << " " << days[i].second.first << " " << days[i].second.second << endl;
    // }

    // cout << endl;
    // cout << minusOneDay(make_pair(9, 1)).first << " " << minusOneDay(make_pair(9, 1)).second << endl;
    // cout << endl;

    pair<int, int> maxDay = {0, 0};
    pair<int, int> target = {3, 1};
    int ans = 0;
    int valid;
    int tmp;
    REP(i, 0, N) {
        tmp = 0;
        if (cmpDay(days[i].first, target)) {
            //cout << "case 1" << endl;
            if (cmpDay(maxDay, days[i].second)) {
                maxDay = days[i].second;
                valid = 1;
            }
        } else {
            if (valid) {
                ans++;
                target = maxDay;
                //cout << " target: " << target.first << " " << target.second << endl;
                valid = 0;
                i--;
                tmp = 1;
            }
        }
        if (!cmpDay(days[i+tmp].first, target)) {
            ans = 0;
            break;
        }
        if (cmpDay(make_pair(12, 1), days[i + tmp].second)) {
            //cout << "ended: " << days[i + tmp].second.first << " " << days[i + tmp].second.second << endl;
            ans++;
            cout << ans << endl;
            return 0;
        }       
    }
    if (cmpDay(maxDay, make_pair(11, 30)))
        ans = 0;

    cout << ans << endl;

    return 0;
}