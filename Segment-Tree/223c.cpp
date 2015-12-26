#include<bits/stdc++.h>
using namespace std;

struct S {
	int t;
	int a;
	int b;
	S() {	}
	S(int t, int a, int b) : t(t), a(a), b(b) { }
};

S merge(S a, S b) {
	int len = min(a.a, b.b);
	S res;
	res.t = a.t + b.t + 2 * len;
//  cerr << a.a << " " << b.b << " sss" << endl;
	res.a = a.a + b.a - len;
	res.b = a.b + b.b - len;
	return res;
}

struct node {
    int start, end;
    S val;
    node *left, *right;

    node(int s, int e, S c):start(s), end(e), val(c),
                              left(NULL), right(NULL) {}
};

node* build_tree(int start, int end) {
    if (end < start) {
        return NULL;
    }
    node *root = new node(start, end, S(0,0,0));
    if (start != end) {
        int mid = start + (end - start) / 2;
        root->left = build_tree(start, mid);
        root->right = build_tree(mid + 1, end);
    }
    return root;
}

S query (node *root, int start, int end) {
    if (end < start || root == NULL) {
        return S(0, 0, 0);
    }
    if (start == root->start && end == root->end) {
        return root->val;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (mid >= end) {
        return query(root->left, start, end);
    }
    if (mid < start) {
        return query(root->right, start, end);
    }
    if (mid >= start && end > mid) {
        return merge(query(root->left, start, mid),
               query(root->right, mid + 1, end));
    }
    return S(0, 0, 0);
}

void init(node *root, string &x) {
  if (root == NULL) return;
  if (root->start == root->end) {
    if(x[root->start - 1] == '(') {
      root->val = S(0, 1, 0);
    } else {
      root->val = S(0, 0, 1);
    }
    return;
  }
  init(root->left, x);
  init(root->right, x);
  root->val = merge(root->left->val, root->right->val);
}

int main () {
  string s; cin >> s; int N = s.size();
  node *root = build_tree(1, N);
  init(root, s);
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int a, b; cin >> a >> b;
    cout << query(root, a, b).t << endl;
  }
}
