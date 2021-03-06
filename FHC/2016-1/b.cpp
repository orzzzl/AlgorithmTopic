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

ll L, N, M, D;
set<pair<ll, ll> > wash;
vector<ll> dp;

void main2() {
  wash.clear();
  dp.clear();
  cin >> L >> N >> M >> D;
  for (ll i = 0; i < N; i++) {
    ll tmp; cin >> tmp; wash.insert(MP(tmp, tmp));
  }
  dp = vector<ll>(L + 5, 0);
  for (ll i = 1; i <= L; i++) {
    auto it = wash.begin();
    ll val = (*it).first, tt = (*it).second;
    wash.erase(it);
    wash.insert(MP(val + tt, tt));
    dp[i] = val;
    if (i > M) dp[i] = max(dp[i], dp[i - M]);
    dp[i] += D;
  }
  cout << dp[L] << endl;
}

int main () {
  std::ios::sync_with_stdio(false);
  int TC,tc;
  cin >> TC;
  for (int tc = 0; tc < TC; tc++) {
    cout << "Case #" << (tc + 1) << ": "; 
    main2();
  }
  return 0;
}
