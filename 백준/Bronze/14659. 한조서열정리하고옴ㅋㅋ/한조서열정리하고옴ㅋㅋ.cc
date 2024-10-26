#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer;
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    v.resize(N + 1);
    
    for(int i=0; i<N; i++) cin >> v[i];

    int tmp = 0, height = v[0];
    for(int i=1; i<N; i++) {
        if(v[i] < height) {
            tmp++;
        } else {
            answer = answer > tmp ? answer : tmp;
            height = v[i];
            tmp = 0;
        }
    }
    answer = answer > tmp ? answer : tmp;

    cout << answer << '\n';

    return 0;
}   