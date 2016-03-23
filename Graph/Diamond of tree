#include<bits/stdc++.h>
using namespace std;
#define MX 123459
int N, M;
vector<int> adj[MX];
bool bad[MX];
int f[MX];

void dfs(int root, int prev, int dist) {
  f[root] = dist;
  for (auto i : adj[root]) {
    if (i == prev) continue;
    dfs(i, root, dist + 1);
  }
}
int dfs2(int &res, int root, int prev) {
  int shouldvis = bad[root];
  for (auto i : adj[root]) {
    if (i == prev) continue;
    if (dfs2(res, i, root)) {
      res += 2;
      shouldvis = 1;
    }
  }
  return shouldvis;
}

int main () {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N - 1; i++) {
    int a, b; scanf("%d%d", &a, &b);
    a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1 ; i <= M; i++) {
    int tmp; scanf("%d", &tmp);
    tmp--;
    bad[tmp] = 1;
  }
  memset(f, 0, sizeof f);
  int root = 0;
  while (bad[root] != 1) root++;
  dfs(root, -1, 0);
  int u = root;
  for (int i = 0; i < N; i++) {
    if (bad[i] == 0) continue;
    if (f[i] > f[u]) u = i;
  }
  memset(f, 0, sizeof f);
  root = u;
  dfs(root, -1, 0);
  u = root;
  for (int i = 0; i < N; i++) {
    if (bad[i] == 0) continue;
    if (f[i] > f[u]) u = i;
  }
  int ans = min(u, root);
  cout << ans + 1 << endl;
  int ret = 0;
  dfs2(ret, root, -1);
  cout << ret - f[u] << endl;
}
