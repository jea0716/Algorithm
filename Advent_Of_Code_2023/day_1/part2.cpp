#include <iostream>
#include <string>

using namespace std;

int main() {
   int answer = 0;

   int first_digit, last_digit;

   while (true) {
      string s; cin >> s;
      string tmp = "";
      for(int i=0; i<s.length(); i++) {
         if (s[i] >= '0' && s[i] <= '9'){
            tmp += s[i];
         } else if(s.substr(i, 3) == "one") {
            tmp += "1";
         } else if(s.substr(i, 3) == "two") {
            tmp += "2";
         } else if(s.substr(i, 5) == "three") {
            tmp += "3";
         } else if(s.substr(i, 4) == "four") {
            tmp += "4";
         } else if(s.substr(i, 4) == "five") {
            tmp += "5";
         } else if(s.substr(i, 3) == "six") {
            tmp += "6";
         } else if(s.substr(i, 5) == "seven") {
            tmp += "7";
         } else if(s.substr(i, 5) == "eight") {
            tmp += "8";
         } else if(s.substr(i, 4) == "nine") {
            tmp += "9";
         }
      }
      first_digit = tmp[0] - '0';
      last_digit = tmp[tmp.length()-1] - '0';
      answer += first_digit * 10 + last_digit;
      cout << answer << "\n";
   }

   return 0;
}
