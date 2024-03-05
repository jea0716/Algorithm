#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector <int> v1 = tangerine;
    vector <int> v2;
    sort(v1.begin(), v1.end());
    int tmp = v1[0];
    int count = 0;
    for(int i=0; i<v1.size(); i++) {
        if(v1[i] != tmp) tmp = v1[i], v2.push_back(count), count = 1;
        else count++;
    }
    if(count != 0) v2.push_back(count);
    sort(v2.rbegin(), v2.rend());
    int nk = k;
    int n = 0;
    while(nk > 0) {
        nk -= v2[n++];
        answer++;
    }
    return answer;
}