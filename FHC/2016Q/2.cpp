#include<bits/stdc++.h>
using namespace std;

void main2() {
  int N; scanf("%d", &N);
  string s1, s2;
  cin >> s1 >> s2;
  vector<pair<int, int> > rec1, rec2;
  int i = 0;
  while (i < N) {
    while (i < N && s1[i] == 'X') i++;
    if (i >= N) break;
    int start = i;
    while (i < N && s1[i] == '.') i++;
    int end = i - 1;
    rec1.push_back(make_pair(start, end));
  }
  i = 0;
  while (i < N) {
    while (i < N && s2[i] == 'X') i++;
    if (i >= N) break;
    int start = i;
    while (i < N && s2[i] == '.') i++;
    int end = i - 1;
    rec2.push_back(make_pair(start, end));
  }
  int N1 = rec1.size(), N2 = rec2.size();
  vector<bool> used1(N1, false), used2(N2, false);
  int ans = 0;
  for (int i = 0; i < N1; i++) {
    ans++;
    int start = rec1[i].first, end = rec1[i].second;
    if (end != start) continue;
    for (int j = 0; j < N2; j++) {
      if (rec2[j].first <= start && rec2[j].second >= end && used2[j] == false) {
        used2[j] = true;
        ans--;
      }
    }
  }
  for (int i = 0; i < N2; i++) {
    ans++;
    int start = rec2[i].first, end = rec2[i].second;
    if (end != start || used2[i]) continue;
    for (int j = 0; j < N1; j++) {
      if (rec1[j].first <= start && rec1[j].second >= end && used1[j] == false) {
        used1[j] = true;
        ans--;
      }
    }
  }
  printf("%d\n", ans);
}

int main () {
  int T; scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    main2();
  }
  return 0;
}
