#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    long long int answer = 1;
    for(int i=1; i<=n; i++){
        int temp = i;
        answer *= temp;
        while(answer % 10 == 0) answer /= 10;
        answer = answer % 1000000000000;
    }
    answer %= 100000;
    cout.width(5);
    cout.fill('0');
    cout << answer << '\n';
    return 0;
}