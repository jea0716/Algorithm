#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int set[101];

int getParent(int n) {
    if(set[n] == n) return n;
    return set[n] = getParent(set[n]);
}

bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i=0; i<n; i++) set[i] = i;
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++) {
        int s = getParent(costs[i][0]);
        int e = getParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(s != e) {
            answer += cost;
            set[e] = s;
        }
    }
    
    return answer;
}