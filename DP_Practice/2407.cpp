// 조합
// https://www.acmicpc.net/problem/2407

#include <climits>
#include <iostream>
#include <vector>
#include <cstring>

#define INF INT_MAX

using namespace std;

string bigSum(string s1, string s2) {
    int s1_len = s1.length();
    int s2_len = s2.length();
    int s1_idx = s1_len - 1;
    int s2_idx = s2_len - 1;
    string ret = "";

    int olim = 0;
    int sum = 0;
    if (s1_len >= s2_len) {
        int result[s1_len + 1];
        int result_idx = s1_len;
        while (s2_idx != -1) {
            sum = (int)s1[s1_idx--] + (int)s2[s2_idx--] + olim - 2 * '0';
            olim = sum / 10;
            result[result_idx--] = sum % 10;
        }
        while (s1_idx != -1) {
            sum = (int)s1[s1_idx--] + olim - '0';
            olim = sum / 10;
            result[result_idx--] = sum % 10;
        }
        if (olim != 0) {
            result[result_idx--] = olim; 
        }
        for (int i = result_idx + 1; i < s1_len + 1; i++) {
            //cout << to_string(result[i]) << " ";
            ret.append(to_string(result[i]));
        }
    } else {
        int result[s2_len + 1];
        int result_idx = s2_len;
        while (s1_idx != -1) {
            sum = (int)s1[s1_idx--] + (int)s2[s2_idx--] + olim - 2 * '0';
            olim = sum / 10;
            result[result_idx--] = sum % 10;
        }
        while (s2_idx != -1) {
            sum = (int)s2[s2_idx--] + olim - '0';
            olim = sum / 10;
            result[result_idx--] = sum % 10;
        }
        if (olim != 0) {
            result[result_idx--] = olim; 
        }
        for (int i = result_idx + 1; i < s2_len + 1; i++) {
            //cout << to_string(result[i]) << " ";
            ret.append(to_string(result[i]));
        }
    }
    return ret;
}

int main() {
    // nCm = n-1Cm-1 + n-1Cm

    int n, m;
    cin >> n >> m;
    
    string c[101][101];
    c[0][0] = "1";
    c[1][0] = "1";

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i-1 >= 0 && j >= 0) {
                if (i == j || j == 0)
                    c[i][j] = "1";
                else
                    c[i][j] = bigSum(c[i-1][j-1], c[i-1][j]);
            }
        }
    }

    cout << c[n][m] << endl;
    return 0;
}