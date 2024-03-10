#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i=0; i<babbling.size(); i++) {
        string tmp = "";
        for(int j=0; j<babbling[i].length(); j++) {
            tmp += babbling[i][j];
            if(
                tmp == "aya" ||
                tmp == "ye" ||
                tmp == "woo" ||
                tmp == "ma"
            ) tmp = "";   
        }
        if(tmp == "") answer++;
    }
    return answer;
}