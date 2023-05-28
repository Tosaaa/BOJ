// 큰 수 A+B
// https://www.acmicpc.net/problem/10757

#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int s1_len = s1.length();
    int s2_len = s2.length();
    int s1_idx = s1_len - 1;
    int s2_idx = s2_len - 1;

    int olim = 0;
    int sum = 0;
    if (s1_len >= s2_len) {
        int result[s1_len + 1];
        int result_idx = s1_len;
        // cout << s1_idx << s2_idx << result_idx << endl;
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
            cout << result[i];
        }
        cout << endl;
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
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}