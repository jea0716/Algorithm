#include <string>
#include <vector>

using namespace std;

int N;
vector<int> apeach;
vector<int> ryan;
vector<int> maxRes;
int maxDiff = 0;

void dfs(int cnt, int n, int AP, int RP){
    if (cnt == 11) {
        if(AP >= RP) return ;
        ryan[10] += N - n;
        
        if(RP - AP > maxDiff) {
            maxRes = ryan;
            maxDiff = RP - AP;
        } else if (RP - AP == maxDiff) {
            for(int i=10; i>=0; i--){
            if(ryan[i]==maxRes[i]) continue;
                else {
                    if(ryan[i] > maxRes[i]) {
                        maxRes = ryan;
                    }
                    break;
                }
            }
        }
        return;
    }
    
    int next = apeach[cnt] + 1;
    if(next + n <= N) { 
        int NAP = AP; 
        int NRP = RP + 10 - cnt; 
        if(next!=1) NAP -= (10-cnt);
        ryan.push_back(next);
        dfs(cnt+1, next+n, NAP, NRP);
        ryan.pop_back(); 
    }
    
    ryan.push_back(0);
    dfs(cnt+1, n, AP, RP);
    ryan.pop_back(); 
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    apeach = info;
    
    int total = 0;
    for(int i=0; i<info.size(); i++){
        if(info[i]) {
            total += (10-i);
        }
    }
    
    dfs(0, 0, total, 0);
    
    if(maxDiff==0) maxRes.push_back(-1);
    return maxRes;
}