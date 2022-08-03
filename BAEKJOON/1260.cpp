#include <iostream>
#include <vector>

using namespace std;

int arr[1001][1001];
int dfs_arr[1001];
int bfs_arr[1001];
vector <int> queue;
int count = 0;

void dfs(int s, int n){
    for(int i=1; i<=n; i++){
        if(arr[s][i] == 1 && dfs_arr[i] == 0){
            dfs_arr[i] = 1;
            cout << i << " ";
            dfs(i,n);
        }
    }
}

void bfs(int s, int n){
    queue.erase(queue.begin());
    for(int i=1; i<=n; i++){
        if(arr[s][i] == 1 && bfs_arr[i] == 0){
            bfs_arr[i] = 1;
            queue.push_back(i);
            cout << i << " ";
        }
    }
    if(queue.size() > 0) bfs(queue[0], n);
}

int main(){
    int n, m, s; cin >> n >> m >> s;
    for(int i=0; i<m; i++){
        int temp1, temp2; cin >> temp1 >> temp2;
        arr[temp1][temp2] = 1;
        arr[temp1][temp2] = 1;
        arr[temp2][temp1] = 1;
        arr[temp2][temp1] = 1;
    }

    dfs_arr[s] = 1;
    bfs_arr[s] = 1;

    cout << s << " ";
    dfs(s, n);
    cout << endl;

    cout << s << " ";
    bfs_arr[s] = 1;
    queue.push_back(s);
    bfs(s, n);
    cout << endl;

    return 0;
}