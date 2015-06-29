#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector <int> st, x;
    int n;
    int left (int p) {
	return p << 1;
    }
    int right (int p) {
	return (p << 1) + 1;
    }
    void build (int p, int l, int r) {
	if (l == r)
	    st [p] = l;
	else {
	    build (left (p), l, (l + r) / 2);
	    build (right (p), (l + r) / 2 + 1, r);
	    int p1 = st [left (p)], p2 = st [right (p)];
	    st [p] = (x [p1] <= x [p2]) ? p1 : p2;
	}
    }

    int rmq (int p, int l, int r, int i, int j) {
	if (i > r || j < l)    return -1;
	if (l >= i && r <= j)    return st [p];

	int p1 = rmq (left (p), l, (l + r) / 2, i, j);
	int p2 = rmq (right (p), (l + r) / 2 + 1, r, i, j);

	if (p1 == -1)    return p2;
	if (p2 == -1)    return p1;
	return (x [p1] <= x [p2]) ? p1 : p2;
    }

    int update_point (int p, int l, int r, int idx, int new_val) {

	if (idx > r || idx < l)
	    return st [p];

	if (r == l && r == idx) {
	    x [idx] = new_val;
	    return st [p] = idx;
	}

	int p1 = update_point (left (p), l, (l + r) / 2, idx, new_val);
	int p2 = update_point (right (p), (l + r) / 2 + 1, r, idx, new_val);

	return st[p] = (x [p1] <= x [p2]) ? p1 : p2;
    }

public:
    SegmentTree (vector <int> a) {
	x = a;
	n = x.size ();
	st.assign (4 * n, 0);
	build(1, 0, n - 1);
    }

    int rmq (int i, int j) {
	return rmq (1, 0, n - 1, i, j);
    }

    int update_point (int idx, int new_val) {
	return update_point (1, 0, n - 1, idx, new_val);
    }
};

int main() {
  int arr[] = { 18, 17, 13, 19, 15, 11, 20 };         // the original array
  vector <int> A(arr, arr + 7);                      // copy the contents to a vector
  SegmentTree st(A);

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("              A is {18,17,13,19,15, 11,20}\n");
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));             // answer = index 2
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));             // answer = index 5
  printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));             // answer = index 4
  printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));             // answer = index 0
  printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));             // answer = index 1
  printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));             // answer = index 5

  printf("              idx    0, 1, 2, 3, 4,  5, 6\n");
  printf("Now, modify A into {18,17,13,19,15,100,20}\n");
  st.update_point(5, 100);                    // update A[5] from 11 to 100
  printf("These values do not change\n");
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));                            // 2
  printf("RMQ(3, 4) = %d\n", st.rmq(3, 4));                            // 4
  printf("RMQ(0, 0) = %d\n", st.rmq(0, 0));                            // 0
  printf("RMQ(0, 1) = %d\n", st.rmq(0, 1));                            // 1
  printf("These values change\n");
  printf("RMQ(0, 6) = %d\n", st.rmq(0, 6));                         // 5->2
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));                         // 5->4
  printf("RMQ(4, 5) = %d\n", st.rmq(4, 5));                         // 5->4

  return 0;
}
