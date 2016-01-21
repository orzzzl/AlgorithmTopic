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

int n, m, k;
vector<int> c;
int type[MX];
vector<pair<int, int> > adj[MX];
class DSet {
public:
  static const int SIZE = 100005;
  int sz[SIZE],p[SIZE];
  void init(int n){
    for(int i=0;i<n;i+=sz[p[i]=i]=1);
  }
  int root(int x){
    return p[x]!=x?p[x]=root(p[x]):x;
  }
  bool join(int x, int y){
    x=root(x),y=root(y);
    if(x==y) return false;
    if(sz[x]<=sz[y]) sz[p[x]=y]+=sz[x];
    else sz[p[y]=x]+=sz[y];
    return true;
  }
} ds;

int main () {
  SSS(n, m, k);
  ds.init(n);
  c = vector<int>(k, 0);
  REP(i, 0, k) S(c[i]);
  c.insert(c.begin(), 0);
  REP(i, 1, k + 1) c[i] += c[i - 1];
  REP(i, 1, k + 1) REP(j, c[i - 1] + 1, c[i] + 1) type[j] = i;
  vector<vector<int> > ans = vector<vector<int> > (k + 5, vector<int>(k + 5, INT_MAX));
  for (int i = 1; i <= k; i++) ans[i][i] = 0;
  times(m) {
    int a, b, v; SSS(a, b, v);
    adj[a].PB({b, v});
    adj[b].PB({a, v});
    if (v == 0) ds.join(a, b);
    int ta = type[a], tb = type[b];
    ans[ta][tb] = ans[tb][ta] = min(ans[ta][tb], v);
  }
  REP(i, 1, k + 1) {
    REP(j, c[i - 1] + 1, c[i] + 1) if (ds.root(j) != ds.root(c[i])) {
      return printf("No\n"), 0;
    }
  }
  REP(m, 1, k + 1) REP(i, 1, k + 1) REP(j, 1, k + 1) if (ans[i][m] != INT_MAX && ans[j][m] != INT_MAX) ans[i][j] = min(ans[i][j], ans[i][m] + ans[j][m]);
  puts("Yes");
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j<= k; j++) PP(ans[i][j] == INT_MAX ? -1 : ans[i][j]);
    printf("\n");
  }
}
