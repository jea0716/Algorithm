#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1111;
    int count = 1;
    string str = "", tmp = "";
    
    if(s.length() == 1) return 1;
    
    for(int i=1; i<=s.length() / 2; i++) 
    {
        str = s.substr(0, i);
        for(int j=i; j<=s.length(); j=j+i) 
        {
            if(s.substr(j, i) == str)
            {
                count++;
            }
            else
            {
                if(count > 1)
                {
                    tmp += to_string(count) + str;
                }
                else 
                {
                    tmp += str;
                }
                str = s.substr(j, i);
                count = 1;
            }
        }
        tmp += str;
        if(answer > tmp.length()) answer = tmp.length();
        tmp = "";
    }
    
    return answer;
}