// 수학은 체육과목 입니다 3
// https://www.acmicpc.net/problem/22351
// assume 변수로 시작 숫자를 1글자, 2글자, 3글자일 때로 가정하고 풀려했으나, 정체 모를 out of range 오류로 풀이 변경함.
// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;
// typedef vector<vector<int>> vvi;

// #define REP(i, a, b) for (int i = a; i < b; i++)
// #define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
// #define endl '\n'

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     string input;
//     cin >> input;
//     int assume = 1;
//     int curlen = 1;
//     int len = input.length();
//     bool done;
//     int start, end;
//     if (len == 1) {
//         start = input[0] - '0';
//         end = input[0] - '0';
//     } else {
//         while (assume <= 3) {
//             int num = stoi(input.substr(0, assume));
//             int ptr = assume;
//             start = num;
//             if (to_string(num).length() != to_string(num + 1).length()) {
//                 curlen++;
//             }
//             end = num;
//             done = false;
//             while (1) {
//                 if (ptr + curlen > len) {
//                     break;
//                 } else if (ptr + curlen == len)
//                     done = true;
//                 int n = stoi(input.substr(ptr, curlen));
//                 if (num + 1 != n) {
//                     done = false;
//                     break;
//                 }
//                 ptr += curlen;
//                 if (to_string(n).length() != to_string(n + 1).length()) {
//                     curlen++;
//                 }

//                 num = n;
//                 end = n;
//             }
//             if (done) break;
//             assume++;
//         }
//     }

//     cout << start << " " << end << endl;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    cin >> input;
    int assume = 1;
    int start, end;
    int len = input.length();
    bool done;
    while (assume <= 3) {
        int num = stoi(input.substr(0, assume));
        if (assume == len) {
            start = num;
            end = num;
            break;
        }
        string tmp;
        done = false;
        for (int i = num;; i++) {
            tmp += to_string(i);
            if (len == tmp.length()) {
                if (input == tmp) {
                    start = num;
                    end = i;
                    done = true;
                    break;
                }
                else {
                    done = false;
                    break;
                }
            } else if (len <= tmp.length()) {
                done = false;
                break;
            }
        }
        if (done) break;
        assume++;
    }
    
    cout << start << " " << end << endl;
    return 0;
}
