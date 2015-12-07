#include <bits/stdc++.h>
using namespace std;
#define MM 1000000007

int A, B, C;
int N;
vector<int> va, vb, vc;

bool flag;
void solve(int pos, int a, int b, int c) {
    if (flag) return;
    if (a > A || b > B || c > C) return;
    if (a == A && b == B && c == C) {
        flag = true;
        return;
    }
    if (pos >= N) return;    
    solve(pos + 1, a, b, c);
    solve(pos + 1, a + va[pos], b + vb[pos], c + vc[pos]);
}

void main2() {
    flag = false;
    cin >> A >> B >> C >> N;
    va.clear(); vb.clear(); vc.clear();
    for (int i = 1; i <= N; i++) {
        int ta, tb, tc;
        cin >> ta >> tb >> tc;
        va.push_back(ta); vb.push_back(tb); vc.push_back(tc);
    }
    solve(0, 0, 0, 0);
    if (flag) cout << "yes"; else cout << "no";
}

int main () {
    if (fopen("/home/ubuntu/workspace/inzzz", "r")) freopen("/home/ubuntu/workspace/inzzz", "r", stdin);
    if (fopen("/home/ubuntu/workspace/outzzz", "w")) freopen("/home/ubuntu/workspace/outzzz", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cerr << i << endl;
        printf("Case #%d: ", i);
        main2();
        if (i < T) printf("\n");
    }
}
