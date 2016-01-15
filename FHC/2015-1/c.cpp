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


int dp1[2005][2005], dp2[2005][2005];
void main2 () {
  string s; cin >> s;
  int i = 0;
  for (; s[i] != '-'; i++);
  int a = stoi(s.substr(0, i)), b = stoi(s.substr(i + 1));
  dp1[1][0] = 1;
  for (int i = 2; i <= a; i++) for (int j = 0; j < i; j++) {
    dp1[i][j] = 0;
    if (j > 0) dp1[i][j] += dp1[i][j - 1];
    dp1[i][j] %= MO;
    if (i - 1 > j) dp1[i][j] += dp1[i - 1][j];
    dp1[i][j] %= MO;
  }
  PP(dp1[a][b]);
  a = b;
  dp2[0][0] = 1;
  for (int i = 0; i <= a; i++) for (int j = i; j <= b; j++) {
    if (i == 0 and j == 0) continue;
    dp2[i][j] = 0;
    if (i > 0) dp2[i][j] += dp2[i - 1][j];
    dp2[i][j] %= MO;
    if (j - 1 >= i) dp2[i][j] += dp2[i][j - 1];
    dp2[i][j] %= MO;
  }
  P(dp2[a][b]);
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
