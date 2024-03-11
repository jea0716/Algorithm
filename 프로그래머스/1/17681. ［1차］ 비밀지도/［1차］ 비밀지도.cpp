#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer, first, second;
    for(int i=0; i<arr1.size(); i++) {
        int mul = 1;
        string tmp = "";
        for(int j=1; j<arr1.size(); j++) mul *= 2;
        int num = arr1[i];
        while(mul > 0) {
            if(num >= mul) tmp += "#", num -= mul, mul /= 2;
            else tmp += "0", mul /= 2;
        }
        first.push_back(tmp);
    }
    for(int i=0; i<arr2.size(); i++) {
        int mul = 1;
        string tmp = "";
        for(int j=1; j<arr2.size(); j++) mul *= 2;
        int num = arr2[i];
        while(mul > 0) {
            if(num >= mul) tmp += "#", num -= mul, mul /= 2;
            else tmp += "0", mul /= 2;
        }
        second.push_back(tmp);
    }
    for(int i=0; i<first.size(); i++) {
        string tmp = "";
        for(int j=0; j<first[i].length(); j++) {
            if(first[i][j] == '#' || second[i][j] == '#') tmp += "#";
            else tmp += "0";
        }
        for(int j=0; j<tmp.length(); j++) {
            if(tmp[j] == '0') tmp[j] = ' ';
        }
        answer.push_back(tmp);
    }
    return answer;
}