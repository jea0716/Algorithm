#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(int i=0; i<my_string.length(); i++) {
        if(my_string[i] >= 'A' && my_string[i] <= 'Z') answer += my_string[i] + 32;
        else answer += my_string[i] - 32;
    }
    return answer;
}