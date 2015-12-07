#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define MM 1000000007
#define MT make_tuple
 
int x[105][105];
int N, M;
int sx, sy, ex, ey;
int ans;
bool vis[105][105][4];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void main2() {
    ans = INT_MAX;
    memset(x, -1, sizeof x);
    memset(vis, 0, sizeof vis);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j - 1] == '.') x[i][j] = 0;
            if (s[j - 1] == 'S') {
                x[i][j] = 0;
                sx = i; sy = j;                
            }
            if (s[j - 1] == 'G') {
                x[i][j] = 0;
                ex = i; ey = j;
            }
            if (s[j - 1] == '^') x[i][j] = -2;
            if (s[j - 1] == '>') x[i][j] = -3;
            if (s[j - 1] == 'v') x[i][j] = -4;
            if (s[j - 1] == '<') x[i][j] = -5;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (x[i][j] == -2) {
                for (int k = i - 1; k >= 1 && x[k][j] >= 0; k--) {
                    x[k][j] *= 10;
                    x[k][j] += 1;
                }
                for (int k = j + 1; k <= M && x[i][k] >= 0; k++) {
                    x[i][k] *= 10;
                    x[i][k] += 2;
                }
                for (int k = i + 1; k <= N && x[k][j] >= 0; k++) {
                    x[k][j] *= 10;
                    x[k][j] += 3;
                }
                for (int k = j - 1; k >= 1 && x[i][k] >= 0; k--) {
                    x[i][k] *= 10;
                    x[i][k] += 4;
                }
            }
            if (x[i][j] == -3) {
                for (int k = i - 1; k >= 1 && x[k][j] >= 0; k--) {
                    x[k][j] *= 10;
                    x[k][j] += 4;
                }
                for (int k = j + 1; k <= M && x[i][k] >= 0; k++) {
                    x[i][k] *= 10;
                    x[i][k] += 1;
                }
                for (int k = i + 1; k <= M && x[k][j] >= 0; k++) {
                    x[k][j] *= 10;
                    x[k][j] += 2;
                }
                for (int k = j - 1; k >= 1 && x[i][k] >= 0; k--) {
                    x[i][k] *= 10;
                    x[i][k] += 3;
                }
            }
            if (x[i][j] == -4) {
                for (int k = i - 1; k >= 1 && x[k][j] >= 0; k--) {
                    x[k][j] *= 10;
                    x[k][j] += 3;
                }
                for (int k = j + 1; k <= M && x[i][k] >= 0; k++) {
                    x[i][k] *= 10;
                    x[i][k] += 4;
                }
                for (int k = i + 1; k <= M && x[k][j] >= 0; k++) {
                    x[k][j] *= 10;
                    x[k][j] += 1;
                }
                for (int k = j - 1; k >= 1 && x[i][k] >= 0; k--) {
                    x[i][k] *= 10;
                    x[i][k] += 2;
                }
            }
            if (x[i][j] == -5) {
                for (int k = i - 1; k >= 1 && x[k][j] >= 0; k--) {
                    x[k][j] *= 10;
                    x[k][j] += 2;
                }
                for (int k = j + 1; k <= M && x[i][k] >= 0; k++) {
                    x[i][k] *= 10;
                    x[i][k] += 3;
                }
                for (int k = i + 1; k <= M && x[k][j] >= 0; k++) {
                    x[k][j] *= 10;
                    x[k][j] += 4;
                }
                for (int k = j - 1; k >= 1 && x[i][k] >= 0; k--) {
                    x[i][k] *= 10;
                    x[i][k] += 1;
                }
            }
        }
    }
    queue<tuple<int, int, int> > Q;
    Q.push(MT(sx, sy, 0));
    while (!Q.empty()) {
        int cx = get<0>(Q.front()), cy = get<1>(Q.front()), cs = get<2>(Q.front()); Q.pop();
        for (int t = 0; t < 4; t++) {
            int nx = cx + dx[t], ny = cy + dy[t], ns = cs + 1;
            if (nx < 1 || nx > N || ny < 1 || ny > M || vis[nx][ny][ns % 4]) continue;
            if (x[nx][ny] < 0) continue;
            int cur = x[nx][ny];
            bool flag = false;
            while (cur > 0) {
                int tmp = cur % 10;
                if (ns % 4 == tmp - 1) {
                    flag = true;
                    break;
                }
                cur /= 10;
            }
            if (flag) continue;
           // cout << nx << " " << ny << " " << ns << " " << x[nx][ny] << endl;;
            vis[nx][ny][ns % 4] = true;
            Q.push(MT(nx, ny, ns));
            if (nx == ex && ny == ey) ans = min(ans, ns);
        }
    }
    if (ans == INT_MAX) cout << "impossible";
    else cout << ans;
}

int main () {
//    if (fopen("/home/ubuntu/workspace/inzzz", "r")) freopen("/home/ubuntu/workspace/inzzz", "r", stdin);
   // if (fopen("/home/ubuntu/workspace/outzzz", "w")) freopen("/home/ubuntu/workspace/outzzz2", "w", stdout);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cerr << i << endl;
        printf("Case #%d: ", i);
        main2();
        if (i < T) printf("\n");
    }
}
