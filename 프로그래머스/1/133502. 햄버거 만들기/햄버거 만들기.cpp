#include <string>
#include <vector>

using namespace std;

vector<int> h;

int recipe[] = { 1, 2, 3, 1 };
int answer = 0;

bool check() {
    bool check = true;
    for(int i=0; i<4; i++) {
        if(recipe[i] != h[h.size()-4+i]) return false;
    }
    return true;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    for(int i=0; i<ingredient.size(); i++) {
        h.push_back(ingredient[i]);
        if(h.size() >= 4 && check()) {
            for(int j=0; j<4; j++) h.pop_back();
            answer++;
        }
    }
    return answer;
}