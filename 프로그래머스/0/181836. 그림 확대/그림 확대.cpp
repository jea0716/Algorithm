#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) {
    vector<string> answer;
    for(int i=0; i<picture.size(); i++) {
        string tmp = "";
        for(int j=0; j<picture[i].length(); j++) {
            for(int l=0; l<k; l++) tmp += picture[i][j];
        }
        for(int j=0; j<k; j++) answer.push_back(tmp);
    }
    return answer;
}