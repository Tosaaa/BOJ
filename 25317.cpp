// functionx
// https://www.acmicpc.net/problem/25317

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ordered_set p;
    set<ll> s;
    int Q;
    cin >> Q;
    int qType;
    ll a, b, c;
    int sign = 1;
    int isEven = 1;
    int startSign;
    
    REP(i, 0, Q) {
        cin >> qType;
        if (qType == 1) {  // add
            cin >> a >> b;
            if (a == 0) {
                if (b < 0) // 음수 상수항 곱하면 다항식 전체 sign * -1
                    sign *= -1;
                else if (b == 0) // 0 곱하면 다항식 전체 sign 앞으로 계속 0
                    sign = 0;
                continue;
            } else if (a < 0) {
                sign *= -1;
            }
            isEven *= -1;

            // ordered set p에 굳이 소수점까지 있는 값을 넣을 필요가 없음 (내림한 정수값을 넣음)
            if (a < 0 && b > 0 || a > 0 && b < 0) {
                p.insert(-b / a);
            } else { // (음수 나누기의 경우 round to zero 라 0 에 가깝게 올려버림. 그래서 나머지가 0인지 확인해서 0이 아니면 (소수점이 있으면) 단순 나누기 - 1로 내림)
                if (b % a != 0) {
                    p.insert(-b / a - 1);
                } else {
                    p.insert(-b / a);
                }
            }

            if (b % a == 0) s.insert(-b / a); // s: 절편 값인지 체크하기 위한 용도의 set (이 용도 밖에 없음)
        } else {  // query
            startSign = sign * isEven; // query 시작하는 당시에 제일 첫번째 부호임
            cin >> c;
            // REP(i, 0, p.size()) {
            //     cout << *(p.find_by_order(i)) << " ";
            // }
            // cout << endl;
            if (startSign == 0) {
                cout << "0" << endl;
            } else if (s.find(c) != s.end()) {
                cout << "0" << endl;
            } else if (p.order_of_key(c) % 2 == 1) {
                if (startSign == -1) {
                    cout << "+" << endl;
                } else {
                    cout << "-" << endl;
                }
            } else {
                if (startSign == 1) {
                    cout << "+" << endl;
                } else {
                    cout << "-" << endl;
                }
            }
        }
        // REP(i, 0, p.size()) {
        //     cout << *(p.find_by_order(i)) << " ";
        // }
        // cout << endl;
    }

    return 0;
}