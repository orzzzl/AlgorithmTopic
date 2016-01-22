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

const int N = 4 * (int)1e5 + 5;
int n, m;
int colors[N];
int from[N], to[N], rev[N];
int cnt;
vector<int> adj[N];
void dfs(int root, int prev) {
  from[root] = cnt;
  rev[cnt++] = root;
  for (int i = 0; i < adj[root].size(); i++) {
    if (adj[root][i] == prev) continue;
    dfs(adj[root][i], root);
  }
  to[root] = cnt - 1;
}

// start of template of lazy segment tree
ll a[4 * N];
bool put[4 * N];

void build(int x, int l, int r) {
  if (l < r) {
    int mid = (l + r) >> 1;
    build(x + x, l, mid);
    build(x + x + 1, mid + 1, r);
    a[x] = a[x + x] | a[x + x + 1];
    put[x] = false;
  } else {
    a[x] = 1LL << colors[rev[l]];
    put[x] = true;
  }
} 

void push(int x) {
  if (put[x]) {
    a[x + x] = a[x + x + 1] = a[x];
    put[x + x] = put[x + x + 1] = true;
    put[x] = false;
  }
}

void gather(int x) {
  a[x] = a[x + x] | a[x + x + 1];
}

void modify(int x, int l, int r, int _l, int _r, ll v) {
  if (_l > r or _r < l) return;
  if (_l <= l and _r >= r) {
    a[x] = v;
    put[x] = true;
    return;
  }
  push(x);
  int mid = (l + r) >> 1;
  modify(x + x, l, mid, _l, _r, v);
  modify(x + x + 1, mid + 1, r, _l, _r, v);
  gather(x);
}

ll get(int x, int l, int r, int _l, int _r) {
  if (r < _l or _r < l) return 0;
  if (_l <= l and _r >= r) {
    return a[x];
  }
  push(x);
  int mid = (l + r) >> 1;
  ll ans = get(x + x, l, mid, _l, _r);
  ans |= get(x + x + 1, mid + 1, r, _l, _r);
  gather(x);
  return ans;
}
/// template end
int main () {
  int n, m;
  SS(n, m);
  REP(i, 0, n) S(colors[i]);
  REP(i, 0, n - 1) {
    int a, b; 
    SS(a, b);
    a--;
    b--;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  dfs(0, -1);
  build(1, 0, n - 1);
  times(m) {
    int type;
    S(type);
    if (type == 1) {
      int a, b;
      SS(a, b);
      a--;
      modify(1, 0, n - 1, from[a], to[a], 1LL << b);
    } else {
      int tmp;
      S(tmp);
      tmp--;
      ll val = get(1, 0, n - 1, from[tmp], to[tmp]);
      P(__builtin_popcountll(val));
    }
  }
}
