#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
bool toggle = false;
int x, y;

int solution(int n, int w, int num) {
    int answer = 0;
    int cur = 1;
    while(cur <= n) {
        vector<int> tmp(w, 0);
        if(toggle) {
            for(int i=0; i<w; i++) {
                if(cur <= n) tmp[i] = cur++;
            }
        } else {
            for(int i=w-1; i>=0; i--) {
                if(cur <= n) tmp[i] = cur++;
            }
        }
        
        for(int i=0; i<w; i++) {
            if(tmp[i] == num) {
                x = v.size();
                y = i;
            }
        }
        
        toggle = toggle ? false : true;
        v.push_back(tmp);
    }
    
    while(x < v.size()) {
        if(v[x][y] != 0) answer++;
        x++;
    }
    
    return answer;
}