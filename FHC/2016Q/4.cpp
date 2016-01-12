#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;
const int inf = (int)1e9;
vector<string> x;
vector<vector<int> > dp;
vector<int> lcp;

int N, K;
void main2() {
  x.clear();
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    string tp; cin >> tp; x.push_back(tp);
  }
  dp = vector<vector<int> >(N + 5, vector<int>(K + 5, inf));
  lcp = vector<int>(N + 5, 0);
  sort(x.begin(), x.end());
  for (int i = 0; i < N - 1; i++) {
    int cnt = 0;
    for (int k = 0; k < x[i].size() and k < x[i + 1].size() and x[i][k] == x[i + 1][k]; k++, cnt++);
    lcp[i] = cnt;
  }
  int lcpsum[N + 5][N + 5];
  for (int i = 0; i < N - 1; i++) {
    lcpsum[i][i] = lcp[i];
    for (int j = i + 1; j < N - 1; j++) lcpsum[i][j] = min(lcp[j], lcpsum[i][j - 1]);
  }
  for (int i = 0; i < N; i++) dp[i][1] = x[i].size();
  for (int k = 2; k <= K; k++) {
    for (int i = 0; i < N; i++) for (int j = i + 1; j < N; j++) 
      dp[j][k] = min(dp[j][k], (int)x[j].size() + (int)x[i].size() - 2 * (lcpsum[i][j - 1]) + dp[i][k - 1]);
  }
  int ans = inf;
  for (int i = 0; i < N; i++) ans = min(ans, dp[i][K] + (int)x[i].size());
  cout << ans + K << endl;
}

int main () {
  int T; scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
      main2();
    }
  return 0;
}
