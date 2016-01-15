#include<bits/stdc++.h>
using namespace std;
#define ALL(XQXQ) (XQXQ).begin(), (XQXQ).end()
#define RALL(PNPN) (PNPN).rbegin(), (PNPN).rend()
#define ll long long
#define MO 1000000007
#define PB push_back
#define MP make_pair
#define MX 100005
#define times(ZZtimes) for(int XYZtimes=0;XYZtimes<ZZtimes;XYZtimes++)
#define MS(ZZtarget,ZZvalue) memset(ZZtarget,ZZvalue,sizeof(ZZtarget))
#define S(SCQW) scanf("%d",&SCQW)
#define SS(SCQW,ZSCQW) scanf("%d%d",&SCQW,&ZSCQW);
#define SSS(SCQW,ZSCQW,ZZSCQW) scanf("%d%d%d",&SCQW,&ZSCQW,&ZZSCQW)
#define SSSS(SCQW,ZSCQW,ZZSCQW,ZZZSCQW) scanf("%d%d%d%d",&SCQW,&ZSCQW,&ZZSCQW,&ZZZSCQW)
#define P(PRQW) printf("%d\n",PRQW)
#define eps 1e-8
#define PP(PRQW) printf("%d ",PRQW)
#define HAS(QPEU) !QPEU.empty()
#define REP(iW,JEJU,nW) for(int (iW)=JEJU;(iW)<(int)(nW);(iW)++)
#define FD(qeVECTORXMO,qeVALXMO) find(qeVECTORXMO.begin(),qeVECTORXMO.end(),qeVALXMO)!=qeVECTORXMO.end()
#define ST(qeVECTORXMO) sort(qeVECTORXMO.begin(),qeVECTORXMO.end())

int N;
vector<int> adj[200005];
int dp[200005][20];
int go(int pos, int select) {
  if (dp[pos][select] != -1) return dp[pos][select];
  int ans = select;
  for (auto i : adj[pos]) {
    int min_val = INT_MAX;
    for (int k = 1; k < 20; k++) {
      if (k == select) continue;
      min_val = min(min_val, go(i, k));
    }
    ans += min_val;  
  }
  return dp[pos][select] = ans;
}

void main2 () {
  S(N);
  MS(dp, -1);
  REP(i, 0, N + 1) adj[i].clear();
  for (int i = 1; i <= N; i++) {
    int tmp; S(tmp);
    adj[tmp].PB(i);
  }
  int ans = INT_MAX;
  for (int i = 1; i < 20; i++) {
    ans = min(ans, go(1, i));
  }
  P(ans);
}

int main () {
  int TC,tc;
  scanf("%d", &TC);
  for (int tc = 0; tc < TC; tc++) {
    printf("Case #%d: ", tc + 1);
    main2();  
  }
  return 0;
}
