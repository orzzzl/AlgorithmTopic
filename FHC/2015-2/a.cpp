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
deque<int> Q1, Q2, backup;
bool ok1, ok2;
bool isgood() {
  while (HAS(Q1)) {
    if (Q1.front() == Q2.front() - 1) {
      Q2.push_front(Q1.front());
      Q1.pop_front();
    } else if (Q1.front() == Q2.back() + 1) {
      Q2.push_back(Q1.front());
      Q1.pop_front();
    } else if (Q1.back() == Q2.front() - 1) {
      Q2.push_front(Q1.back());
      Q1.pop_back();
    } else if (Q1.back() == Q2.back() + 1) {
      Q2.push_back(Q1.back());
      Q1.pop_back();
    } else {
      return false;
    }
  }
  return true;
}

void main2() {
  int N;
  S(N);
  while (HAS(Q1)) Q1.pop_back();
  while (HAS(Q2)) Q2.pop_back();
  times(N) {
    int tmp; S(tmp);
    Q1.PB(tmp);
  }
  backup = Q1;
  Q2.PB(Q1.front());
  Q1.pop_front();
  ok1 = isgood();
  ok2 = true;
  while (HAS(Q2)) Q2.pop_back();
  Q1 = backup;
  Q2.PB(Q1.back());
  Q1.pop_back();
  if (ok1 == false) ok2 = isgood();
  puts(ok1 || ok2 ? "yes" : "no");
}

int main() {
  int TC,tc;
  scanf("%d", &TC);
  for (int tc = 0; tc < TC; tc++) {
    printf("Case #%d: ", tc + 1);
    main2();
  }
  return 0;
}
