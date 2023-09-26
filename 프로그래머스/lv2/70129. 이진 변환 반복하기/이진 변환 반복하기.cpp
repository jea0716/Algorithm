#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string convertS = s;
    int convertNum = 0;
    int removeZero = 0;
    int num;
    while(convertS.length() != 1) {
        num = 0;
        for(int i=0; i<convertS.size(); i++) {
            if(convertS[i] == '1') num++;
            else removeZero++;
        }
        string tmp = "";
        while(num != 0) {
            if(num % 2 == 1) tmp += "1";
            else tmp += "0";
            num /= 2;
        }
        convertNum++;
        convertS = tmp;
    }
    answer.push_back(convertNum);
    answer.push_back(removeZero);
    return answer;
}