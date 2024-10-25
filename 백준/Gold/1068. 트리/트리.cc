#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, K, tmp, root, leaf;
vector<int> v[51];
bool visited[51];

void DFS(int n) {
    if(visited[n]) return ;
    visited[n] = true;

    if(v[n].size() == 0 || (v[n].size() == 1 && v[n][0] == K)) leaf++;

    for(int i=0; i<v[n].size(); i++) {
        if(v[n][i] != K) DFS(v[n][i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;

    for(int i=0; i<N; i++) 
    {
        cin >> tmp;
        if(tmp == -1) root = i;
        else v[tmp].push_back(i);
    }

    cin >> K;
    if(K == root) cout << "0\n";
    else {
        DFS(root);
        cout << leaf << '\n';
    }

    return 0;
}