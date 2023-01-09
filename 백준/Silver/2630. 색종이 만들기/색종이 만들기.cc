#include <iostream>

using namespace std;

int arr[129][129];
int bw[2];

int chk(int n, int a, int b){
    int c = arr[a][b];
    for(int i=a; i<a+n; i++){
        for(int j=b; j<b+n; j++){
            if(c != arr[i][j]) return 0;
        }
    }
    return 1;
}

void sol(int n, int a, int b){
    if(chk(n, a, b) == 1){
        bw[arr[a][b]]++;
        return ;
    }

    sol(n/2, a, b);
    sol(n/2, a, b+n/2);
    sol(n/2, a+n/2, b);
    sol(n/2, a+n/2, b+n/2);
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin >> arr[i][j];
    }
    sol(n, 0, 0);
    cout << bw[0] << endl;
    cout << bw[1] << endl;
    return 0;
}