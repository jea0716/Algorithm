#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    string tmp = "";
    int x = 0, num = 0;
    for(int i=0; i<polynomial.length(); i++) {
        if(polynomial[i] == ' ') {
            if(tmp[tmp.length()-1] == 'x') {
                if(tmp.length() == 1) x++;
                else {
                    string s = "";
                    for(int i=0; i<tmp.length()-1; i++) s += tmp[i];
                    x += stoi(s);
                }
            }
            else if(tmp == "+") tmp = "";
            else {
                string s = "";
                for(int i=0; i<tmp.length(); i++) s += tmp[i];
                num += stoi(s);
            }
            tmp = "";
        }
        else tmp += polynomial[i];
    }
    if(tmp != "") {
        if(tmp[tmp.length()-1] == 'x') {
            if(tmp.length() == 1) x++;
            else {
                string s = "";
                for(int i=0; i<tmp.length()-1; i++) s += tmp[i];
                x += stoi(s);
            }
        }
        else if(tmp == "+") tmp = "";
        else {
            string s = "";
            for(int i=0; i<tmp.length(); i++) s += tmp[i];
            num += stoi(s);
        }
    }
    if(x != 0 && num == 0) {
        if(x == 1) answer += "x";
        else answer += to_string(x), answer += "x";
    }
    else if (x == 0 && num != 0) answer += to_string(num);
    else if (x == 1 && num != 0) {
        answer += "x + ";
        answer += to_string(num);
    }
    else {
        answer += to_string(x);
        answer += "x + ";
        answer += to_string(num);
    }
    return answer;
}