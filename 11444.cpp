// 피보나치 수 6
// https://www.acmicpc.net/problem/11444

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define REP(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define endl '\n'
#define DIV 1000000007

using namespace std;

vector<vector<long long>> fib_mat(2, vector<long long>(2));

vector<vector<long long>> mult(vector<vector<long long>> A, vector<vector<long long>> B) {
    long long a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
    long long x = B[0][0], y = B[0][1], z = B[1][0], w = B[1][1];
    vector<vector<long long>> ret(2, vector<long long>(2));
    ret[0][0] = ((a * x) % DIV + (b * z) % DIV) % DIV;
    ret[0][1] = ((a * y) % DIV + (b * w) % DIV) % DIV;
    ret[1][0] = ((c * x) % DIV + (d * z) % DIV) % DIV;
    ret[1][1] = ((c * y) % DIV + (d * w) % DIV) % DIV;
    return ret;
}

pair<string, int> divideStrBy2(string n) {
    int len = n.length();
    string buf = "";
    bool remained = false;
    REP(i, 0, len) {
        int dividend;
        if (remained) {
            dividend = 10;
            dividend += (n[i] - '0');
        } else {
            dividend = (n[i] - '0');
        }
        int Q = dividend / 2;
        int R = dividend % 2;
        if (R) {
            n[i] = '1';
            buf += Q + '0';
            remained = true;
        } else {
            buf += Q + '0';
            if (remained) {
                n[i - 1] = '0';
            }
            n[i] = '0';
            remained = false;
        }
    }
    string ret = "0";
    REP(i, 0, len) {
        if (buf[i] != '0') {
            ret = buf.substr(i);
            break;
        }
    }
    if (remained) {
        return make_pair(ret, 1);
    } else {
        return make_pair(ret, 0);
    }
}

vector<vector<long long>> getFib(string n) {
    vector<vector<long long>> ret;
    if (n == "1") {
        return fib_mat;
    } else {
        pair<string, int> div = divideStrBy2(n);
        if (div.second) {
            ret = getFib(div.first);
            ret = mult(ret, ret);
            ret = mult(ret, fib_mat);
        } else {
            ret = getFib(div.first);
            ret = mult(ret, ret);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string N;
    cin >> N;
    // reverse(N.begin(), N.end());

    fib_mat[0][0] = 1;
    fib_mat[0][1] = 1;
    fib_mat[1][0] = 1;
    fib_mat[1][1] = 0;

    vector<vector<long long>> ret = getFib(N);
    int ans = ret[1][0];

    cout << ans << endl;

    return 0;
}