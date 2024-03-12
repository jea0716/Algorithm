#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector <int> tmp = score;
    sort(tmp.rbegin(), tmp.rend());
    for(int i=0; i<score.size()/m; i++) {
        int min = 10;
        for(int j=0; j<m; j++) if(min > tmp[i * m + j]) min = tmp[i * m + j];
        answer += min * m;
    }
    return answer;
}