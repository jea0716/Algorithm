#include <iostream>

using namespace std;

int arr[51][51];

void remove(int n, int m, int w, int h){
    arr[n][m] = 0;
    if(n == 0){
        if(m == 0){
            if(arr[n+1][m] == 1) remove(n+1, m, w, h);
            else if(arr[n][m+1] == 1) remove(n, m+1, w, h);
        }
        else if(m == h-1){
            if(arr[n+1][m] == 1) remove(n+1, m, w, h);
            else if(arr[n][m-1] == 1) remove(n, m-1, w, h);
        }
    }
    else if(n == w-1){
        if(m == 0){
            if(arr[n-1][m] == 1) remove(n-1, m, w, h);
            else if(arr[n][m+1] == 1) remove(n, m+1, w, h);
        }
        else if(m == h-1){
            if(arr[n-1][m] == 1) remove(n-1, m, w, h);
            else if(arr[n][m-1] == 1) remove(n, m-1, w, h);
        }
    }
    
    if(arr[n+1][m] == 1) remove(n+1, m, w, h);
    if(arr[n-1][m] == 1) remove(n-1, m, w, h);
    if(arr[n][m+1] == 1) remove(n, m+1, w, h);
    if(arr[n][m-1] == 1) remove(n, m-1, w, h);
}

int T(){
    int n, m, bug; cin >> n >> m >> bug;
    for(int i=0; i<51; i++){
        for(int j=0; j<51; j++){
            arr[i][j] = 0;
        }
    }
    int answer = 0;
    int x, y;
    for(int i=0; i<bug; i++){
        cin >> x >> y;
        arr[x][y] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                //배열 확인
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        cout << arr[i][j] << " ";
                    }
                    cout << '\n';
                }
                cout << '\n';
                answer++;
                remove(i, j, n, m);
            }
        }
    }
    return answer;
}

int main(){
    int N; cin >> N;
    for(int i=0; i<N; i++) cout << T() << '\n';
    return 0;
}