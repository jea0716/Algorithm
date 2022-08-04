#include <iostream>

using namespace std;

//1->b , 2->ba 3->bab, 4->babba 5->babbabab
//01, 11, 12, 23, 35

int main(){
    int n; cin >> n;
    int a=1, b=0, temp;
    for(int i=0; i<n; i++){
        temp = b;
        b += a;
        a = temp;
    }
    cout << a << " " << b << '\n';
}