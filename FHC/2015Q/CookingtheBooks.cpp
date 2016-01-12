#include <bits/stdc++.h>
using namespace std;
#define MM 1000000007

bool flag;

string solve1(string s) {
    if (s.size() <= 1) return s;
    char maxval = '0';
    int ind = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= maxval) {
            ind = i;
            maxval = s[i];
        }
    }
    if (maxval == s[0]) return s[0] + solve1(s.substr(1));
    else {
        swap(s[0], s[ind]);
        return s;
    }
}

string solve2(string s) {
    if (s.size() <= 1) return s;
    if (s[0] == '0') return s[0] + solve2(s.substr(1));
    char minval = '9';
    int ind = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0' && flag) continue;
        if (s[i] <= minval) {
            ind = i;
            minval = s[i];
        }
    }
    flag = false;
    if (ind == -1) return s;
    if (minval == s[0]) {
        return s[0] + solve2(s.substr(1));
    }
    else {
        swap(s[0], s[ind]);
        return s;
    }
}

void main2() {
    string s;
    cin >> s;
    cout << solve2(s) << " " << solve1(s);
}

int main () {
    if (fopen("/home/ubuntu/workspace/inzzz", "r")) freopen("/home/ubuntu/workspace/inzzz", "r", stdin);
    if (fopen("/home/ubuntu/workspace/outzzz", "w")) freopen("/home/ubuntu/workspace/outzzz", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        flag = 1;
        printf("Case #%d: ", i);
        main2();
        if (i < T) printf("\n");
    }
}
