#include <iostream>

using namespace std;

// 1-s 2-sc 3-scs 4-scsc 5-scscs 6-sc 7-scs 8-scsc 9-scs

int main(){
    int n; cin >> n;
    if(n%2 == 1) cout << "SK\n";
    else cout << "CY\n";
    return 0;
}