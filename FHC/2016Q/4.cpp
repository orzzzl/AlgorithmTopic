#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
int K, N;
string buf;
vector<string> x;

struct TrieNode {
    unordered_map<char, TrieNode*> rec;
    TrieNode() { 
    }
};

struct Trie {
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        auto cur = root;
        for (auto i : word) {
            if (cur->rec.find(i) == cur->rec.end()) {
                cur->rec[i] = new TrieNode();
            }
            cur = cur->rec[i];
        }
    }
    int get_ind(string prefix) {
        auto cur = root;
        int cnt = 0;
        for (auto i : prefix) {
            if (cur->rec.find(i) == cur->rec.end()) {
                return cnt;
            }
            cur = cur->rec[i];
            cnt++;
        }
        return cnt;
    }
};

void main2() {
    scanf("%d%d", &N, &K);
    x.clear();
    for (int i = 0; i < N; i++) {
        cin >> buf;
        x.push_back(buf);
    }
    int ans = INT_MAX;
    for (int start = 0; start < N; start++) {
        Trie task;
        task.insert(x[start]);
        int cnt = 1;
        int cost = x[start].size();
        vector<bool> vis(N, false);
        vis[start] = true;
        while (cnt < K) {
            int min_val = INT_MAX, ind = -1;
            for (int k = 0; k < N; k++) {
                if (vis[k]) continue;
                int match = task.get_ind(x[k]);
                int val = x[k].size() - match;
                if (val < min_val) {
                    min_val = val;
                    ind = k;
                }
            }
            vis[ind] = true;
            task.insert(x[ind]);
            cost += min_val;
            cnt++;
        }
        ans = min(ans, cost);
    }
    printf("%d\n", 2 * ans + K);
}

int main () {
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        main2();
    }
    return 0;
}
