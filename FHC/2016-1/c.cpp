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


vector<ll> x;
void main2() {
  ll N, A, B; cin >> N >> A >> B;
  x.clear();
  x.PB(0);
  ll sum(0);
  times(N) {
    ll tmp; cin >> tmp; x.PB(tmp + x.back());
    sum += tmp;
  }
  ll tot = B - A;
  ll aa = A / sum, bb = B / sum - 1;
  A -= aa * sum;
  B -= (bb + 1) * sum;
  double onetime = 0;
  for (int i = 1; i < x.size(); i++) {
    onetime += (x[i] - x[i - 1]) * 1.0 / 2 * (x[i] - x[i - 1]) / tot;
  }
  double rg = 0;
  double lf = 0;
  for (int i = 1; i < x.size(); i++) {
    if (x[i] < A) continue;
    double delta = 0;
    if (A > x[i - 1]) delta += A - x[i - 1];
    lf += ((x[i] - max(A, x[i - 1])) * 1.0 / 2 + delta) * (x[i] - max(A, x[i - 1])) / tot;
  }
  for (int i = 1; i < x.size(); i++) {
    if (x[i - 1] > B) break;
    rg += (min(x[i], B) - x[i - 1]) * 1.0 / 2 * (min(x[i], B) - x[i - 1]) / tot;
  }
  double ans = lf + rg + (bb - aa) * onetime;
  cout.precision(9);
  cout << setiosflags(ios::fixed) << ans << endl;
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
