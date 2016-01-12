#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
#define PB push_back
#define ll long long
vector<int> xs, ys;

int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void main2() {
  xs.clear(); ys.clear();
  int N; scanf("%d", &N);
  for (int nn = 0; nn < N; nn++) {
    int a, b; scanf("%d%d", &a, &b);
    xs.PB(a); ys.PB(b);
  }
  ll ans = 0;         
  for (int i = 0; i < N; i++) {
    map<int, int> rec;
    for (int j = 0; j < N; j++) {
      if (j == i) continue;
      rec[dist(xs[i], ys[i], xs[j], ys[j])]++;
    }
    for (auto ele : rec) {
      if (ele.second >= 2) ans += ele.second * (ele.second - 1) / 2;
    }
  }
  cout << ans << endl; 
}

int main(void){
  int TC,tc;
  scanf("%d", &TC);
  for (int tc = 0; tc < TC; tc++) {
    printf("Case #%d: ", tc + 1);
    main2();
  }
  return 0;
}
