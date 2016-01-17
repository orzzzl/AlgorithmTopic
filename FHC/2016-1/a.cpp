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

vector<int> x;
void main2() {
  x.clear();
  int N; S(N);
  int status = 1, ans = 0;
  times(N) {
    int tmp; S(tmp);
    x.PB(tmp);
  }
  REP(i, 0, N - 1) {
    int val = x[i + 1] - x[i];
    if (status == 4) status = 1;
    else if (status == 3) {
      if (val > 0 and val <= 10) {
        status = 4;
      } else {
        ans++;
        status = 1;
      }
    } else if (status == 2) {
      if (val > 0 and val <= 10) {
        status = 3;
      } else if (val > 10 and val <= 20) {
        ans++;
        status = 4;
      } else {
        ans += 2;
        status = 1;
      }
    } else if (status == 1) {
      if (val > 0 and val <= 10) {
        status = 2;
      } else if (val > 10 and val <= 20) {
        ans++;
        status = 3;
      } else if (val > 20 and val <= 30) {
        ans += 2;
        status = 4;
      } else {
        ans += 3;
        status = 1;
      }
    }
  }
  ans += 4 - status;
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
