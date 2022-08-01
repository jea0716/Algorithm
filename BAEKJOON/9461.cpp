#include <iostream>

using namespace std;

// 1 1 1 2 2 3 4 5 7 9 12 16 21 28 37 49 65

int main(){
    int n; cin >> n;
    long long int arr[101];
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        for(int j=0; j<temp; j++){
            if(j<3) arr[j] = 1;
            else if(j<5 && j>=3) arr[j] = 2;
            else{
                arr[j] = arr[j-1] + arr[j-5];
            }
        }
        cout << arr[temp-1] << endl;
    }
    return 0;
}