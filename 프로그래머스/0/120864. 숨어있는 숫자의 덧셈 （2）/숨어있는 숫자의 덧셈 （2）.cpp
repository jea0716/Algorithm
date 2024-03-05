#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string tmp = "";
    for(int i=0; i<my_string.length(); i++) {
        if(my_string[i] >= '0' && my_string[i] <= '9') tmp += my_string[i];
        else {
            if(tmp != "") answer += stoi(tmp), tmp = "";
        }
    }
    if(tmp != "") answer += stoi(tmp);
    return answer;
}