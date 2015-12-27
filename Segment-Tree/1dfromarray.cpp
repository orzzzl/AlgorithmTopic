struct node {
    int start, end, sum;
    node *left, *right;

    node(int s, int e, int c):start(s), end(e), sum(c),
                              left(NULL), right(NULL) {}
};

node *helper(const vector<int> &A, int start, int end) {
        if (end < start) {
            return NULL;
        }
        node *root = new node(start, end, 0);
        if (start != end) {
            int mid = (start + end) / 2;
            root->left = helper(A, start, mid);
            root->right = helper(A, mid + 1, end);
            root->sum = root->left->sum + root->right->sum;
        } else {
            root->sum = A[start];   
        }
        return root;
}

node* build(vector<int>& A) {
        return helper(A, 0, A.size() - 1);
}

int query (node *root, int start, int end) {
    if (end < start || root == NULL) {
        return 0; 
    }
    if (start == root->start && end == root->end) {
        return root->sum; 
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (mid >= end) {
        return query(root->left, start, end);
    } 
    if (mid < start) {
        return query(root->right, start, end);
    }
    if (mid >= start && end > mid) {
        return query(root->left, start, mid) +
               query(root->right, mid + 1, end);
    }
    return 0;
}
