#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int M, N;
vector<bool> num(1000001, 1);

void solved() {
    num[1] = 0;
    for(int i=2; i*i<=N; i++) {
        if(num[i]) {
            for(int j=i*i; j<=N; j=j+i) {
                num[j] = 0;
            }
        }
    }

    for(int i=M; i<=N; i++) {
        if(num[i]) cout << i << "\n";
    }
}

int main() {
    cin >> M >> N;

    solved();

    return 0;
}