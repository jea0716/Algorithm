#include <iostream>
#include <math.h>
// N! / (M! * (N-M)!)

using namespace std;

int five(int n){
    int temp = 0;
    for(int i=1; i<=13; i++){
        temp += n/pow(5,i);
    }
    return temp;
}

int two(int n){
    int temp = 0;
    for(int i=1; i<31; i++){
        temp += n/pow(2,i);
    }
    return temp;
}

int main(){
    int n, m, answer = 0; cin >> n >> m;

    int a, b;
    a = five(n) - (five(m) + five(n-m));
    b = two(n) - (two(m) + two(n-m));

    cout << min(a, b) << '\n';
}