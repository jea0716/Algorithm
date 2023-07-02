#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool first_letter = false;
    for(int i=0; i<s.length(); i++)
    {
        if(first_letter == false)
        {
            if(s[i] <= 'z' && s[i] >= 'a') s[i] = s[i] - 32;
                
            first_letter = true;
        }
        else
        {
            if(s[i] <= 'Z' && s[i] >= 'A') s[i] = s[i] + 32;
        }
        
        if(s[i] == ' ') first_letter = false;
    }
    return s;
}