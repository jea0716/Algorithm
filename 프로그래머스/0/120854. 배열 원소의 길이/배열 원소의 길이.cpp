#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for(int i=0; i<strlist.size(); i++) {
        int tmp = 0;
        for(int j=0; j<strlist[i].length(); j++) tmp++;
        answer.push_back(tmp);
    }
    return answer;
}