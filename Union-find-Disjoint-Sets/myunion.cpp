#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector <int> parent, size, score;
    int setNum;
public:
    UnionFind (int n) {
	setNum = n;
	parent.assign (n, 0);
	size.assign (n, 1);
	score.assign (n, 0);
	for (int i = 0; i < n; i ++) 
	    parent [i] = i;
    }

    int findParent (int i) {
	if (parent [i] == i)
	    return i;
	else 
	    return findParent (parent [i]);
    }

    bool isSameSet (int i, int j) {
	return findParent (i) == findParent (j);
    }

    int numOfSets () {
	return setNum;
    }

    int sizeOfSet (int i) {
	if (i < 0 || i >= setNum) return -1;
	return size [findParent (i)];
    }

    int unionSet (int i, int j) {
	if (isSameSet (i, j))    return -1;
	int x = findParent (i);
	int y = findParent (j);
	setNum --;
	if (score [x] == score [y])
	    score [y] ++;
	if (score [x] > score [y]) {
	    parent [y] = x;
	    size [x] += size [y];
	} else {
	    parent [x] = y;
	    size [y] += size [x];
	}
	return 0;	    
    }
};


int main() {
  printf("Assume that there are 5 disjoint sets initially\n");
  UnionFind UF(5); // create 5 disjoint sets
  printf("%d\n", UF.numOfSets()); // 5
  UF.unionSet(0, 1);
  printf("%d\n", UF.numOfSets()); // 4
  UF.unionSet(2, 3);
  printf("%d\n", UF.numOfSets()); // 3
  UF.unionSet(4, 3);
  printf("%d\n", UF.numOfSets()); // 2
  printf("isSameSet(0, 3) = %d\n", UF.isSameSet(0, 3)); // will return 0 (false)
  printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3)); // will return 1 (true)
  for (int i = 0; i < 5; i++) // findParent will return 1 for {0, 1} and 3 for {2, 3, 4}
    printf("findParent(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findParent(i), i, UF.sizeOfSet(i));
  UF.unionSet(0, 3);
  printf("%d\n", UF.numOfSets()); // 1
  for (int i = 0; i < 5; i++) // findParent will return 3 for {0, 1, 2, 3, 4}
    printf("findParent(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findParent(i), i, UF.sizeOfSet(i));
  return 0;
}
