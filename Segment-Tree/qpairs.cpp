// Queries with Pairs - Animesh Fatehpuria
#include <bits/stdc++.h>
#define INF (int)(2e9 + 8)
#define F first
#define S second
 
using namespace std;
 
// Ultra neat code to solve QPAIR 
const int MAX = 1e5 + 50;
 
pair < int , pair < int , int >  > P[MAX]; // Array
pair < int , pair < int , int >  > Q[MAX]; // Query
pair < int , int > DUMMY = make_pair( INF, INF ); // Dummy Node
int N , T , lim = (int)(1e9);
 
int ans[MAX];
 
struct node{ // Implementing an Implicit Segment Tree
 
	node* left;
	node* right;
	pair < int , int > val;
	
	node( node* _left = NULL , node* _right = NULL , pair < int , int > _val = DUMMY  ){
		left  = _left;
		right = _right;
		val   = _val;
	}
 	
 	// Merges the children of a segment tree node
	pair < int , int > merge( pair < int , int > p , pair < int , int > q ){
		
		pair < int , int > best = DUMMY;
		
		if( p.F < q.F ) best = p;
		
		else if( q.F < p.F ) best = q;
		
		else{
			if( p.S < q.S ) best = p;
			if( q.S < p.S ) best = q;
		}
 
		return best;
	}
 
	node* update(int l , int r , int bsum , int asum , int idx ){
		
		if( l == r ){
			// Update sum and index in the leaf node
			val = merge( val , make_pair( asum + bsum , idx ) );
			return this;
		}
		
		int mid = l + r >> 1;
 
		if( mid >= bsum){
			if( !left ) left = new node(); // Create node only when needed
			left  =  left -> update(l,mid,bsum,asum,idx);
		}
		else{
			if( !right ) right = new node();
			right = right -> update(mid+1,r,bsum,asum,idx);
		}
 
		val = merge( left ? left -> val : DUMMY , right? right -> val : DUMMY );
 
		return this;
	}
 
	pair < int , int > query( int l , int r , int qs , int qe ){
		
		if( l > qe or r < qs or !this )
			return DUMMY; // Out of range
		
		if( l >= qs and r <= qe)
			return val;
 
		int mid = l + r >> 1;
		return merge( left -> query(l,mid,qs,qe) , right -> query( mid + 1 , r , qs ,qe) );
	}
 
};
 
node* root = new node(); 
 
// Reorder Queries and Array
bool cmp( pair < int , pair < int , int >  > x , pair < int , pair < int , int >  > y ){
	if(x.S.F == y.S.F) return x.S.S > y.S.S ;
	return x.S.F > y.S.F;
}
 
int main(){
	
	cin.tie(0) , ios::sync_with_stdio(false);
	
	cin >> N >> T;
	
	for(int i = 1 ; i <= N ; i++){
		 cin >> P[i].S.F;
	}
	
	for(int i = 1 ; i <= N ; i++){
		cin  >> P[i].S.S;
		P[i].F = i;
	}
 
	sort( P + 1 , P + 1 + N , cmp);
	
	for(int i = 1 ; i <= T ; i++){
		int a , b;
		cin >> a >> b;
		Q[i].F = i , Q[i].S.F = a , Q[i].S.S = b;
	}
 
	sort( Q + 1 , Q + 1 + T , cmp);
	int cur = 1;
 
	for(int i = 1 ; i <= T ; i++){
		
		// Update all relevant indices
		while( cur <= N and P[cur].S.F >= Q[i].S.F ){
			root = root -> update(1,lim,P[cur].S.S,P[cur].S.F,P[cur].F);
			cur++;
		}
 		// We have inserted all relevant indices in our segment tree.
		ans[Q[i].F] = root -> query(1,lim,max(1,Q[i].S.S),lim).S;
		
		if( ans[Q[i].F] == INF ) ans[Q[i].F] = -1; 
	}
 
	for(int i = 1 ; i <= T ; i++)
		cout << ans[i] << endl;
}
  
