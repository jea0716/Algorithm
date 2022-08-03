#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(){
    int N, M; cin >> N >> M;
    vector <int> v(N);
    vector <int> v2(N);
    int temp;
    int count = 1;

    for(int i=0; i<N; i++){
        cin >> temp;
        v[i] = temp;
        v2[i] = temp;
    }
    int num = v[M];

    sort(v2.rbegin(), v2.rend());

    while(v2[0] != num || M != 0){
        if(v2[0] == v[0]){
            v2.erase(v2.begin());
            count++;
        }
        temp = v.front();
        v.push_back(temp);
        v.erase(v.begin());
        if(M==0){
            M = N-1;
        }
        else{
            M--;
        }
    }

    return count;
}

int main(){
    int T; cin >> T;
    for(int i=0; i<T; i++) cout << solve() << "\n";

    return 0;
}