#include <iostream>
#include <algorithm>

using namespace std;

int N, B, C;
int A[1000001];
unsigned long long int answer;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N ;
    for(int i=0; i<N; i++) cin >> A[i];
    cin >> B >> C;

    for(int i=0; i<N; i++) {
        answer++;
        A[i] -= B;
        if(A[i] <= 0) continue;
        if(A[i] % C != 0) answer++;
        answer += A[i] / C;
    }

    cout << answer << "\n";

    return 0;
}