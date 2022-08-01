#include <iostream>

using namespace std;

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/

int main(){
    int n, temp1, temp2, answer=0; cin >> n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j!=0 && j!=i){
                temp1 = arr[i][j] + arr[i-1][j-1];
                temp2 = arr[i][j] + arr[i-1][j];
                arr[i][j] = max(temp1, temp2);
            }
            else if(j==0){
                arr[i][j] += arr[i-1][j];
            }
            else if(j==i){
                arr[i][j] += arr[i-1][j-1];
            }
        }
    }

    for(int i=0; i<n; i++){
        if(arr[n-1][i] > answer) answer = arr[n-1][i];
    }

    cout << answer << "\n";

    return 0;
}