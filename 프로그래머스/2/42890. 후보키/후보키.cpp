#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> ans;

bool isUnique(int n) {
    for(int i=0; i<ans.size(); i++) {
        if((ans[i] & n) == ans[i]) {
            return false;
        }
    }
    
    return true;
}

int solution(vector<vector<string>> relation) {
    int rowLen = relation.size();
    int colLen = relation[0].size();
    
    for(int i=1; i<(1 << colLen); i++) {
        set<string> store;
        for(int j=0; j<rowLen; j++) {
            string tmp;
            for(int k=0; k<colLen; k++) {
                if((i & (1 << k))) {
                    tmp += relation[j][k];
                }
            }
            store.insert(tmp);
        }
        
        if(store.size() == rowLen) {
            if(isUnique(i)) {
                ans.push_back(i);
            }
        }
    }
    
    return ans.size();
}