#include <iostream>

using namespace std;


//2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
//1->1, 2->3, 3->5, 4->11, 5->16

int arr[1001];

int main(){
    int n; cin >> n;
    arr[1] = 1; arr[2] = 3;
    for(int i=3; i<=n; i++){
        arr[i] = arr[i-2] * 2 + arr[i-1];
    }
    cout << arr[n] << endl;

    return 0;
}