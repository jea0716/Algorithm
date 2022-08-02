#include <iostream>

using namespace std;

int arr[101][101];
int arr2[101];

void dfs(int a,int n){
    for(int i=0; i<n; i++){
        if(arr[a][i] == 1 && arr2[i] == 0){
            arr2[i] = 1;
            dfs(i, n);
        }
    }
}

int main(){
    int n; cin >> n;
    int m; cin >> m;

    int answer = 0;

    int temp1, temp2;

    for(int i=0; i<m; i++){
        cin >> temp1 >> temp2;
        arr[temp1-1][temp2-1] = 1;
        arr[temp2-1][temp1-1] = 1;
    }

    dfs(0,n);

    for(int i=1; i<n; i++){
        if(arr2[i] == 1) answer += 1;
    }

    cout << answer << "\n";

    return 0;
}