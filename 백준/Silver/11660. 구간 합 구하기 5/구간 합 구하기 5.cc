#include <iostream>

using namespace std;

int map[1026][1026];
int sum[1026][1026];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M; cin >> N >> M; 

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[j][i];
            sum[j][i] = sum[j-1][i] + sum[j][i-1] + map[j][i] - sum[j-1][i-1];
        }
    }

    int x1, y1, x2, y2;
    for(int t=0; t<M; t++) {
        cin >> x1 >> y1 >> x2 >> y2;

        cout << sum[y2][x2] - sum[y1-1][x2] - sum[y2][x1-1] + sum[y1-1][x1-1] << "\n";
    }
}