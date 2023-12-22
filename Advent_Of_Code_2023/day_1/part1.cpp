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
         }
      }
      first_digit = tmp[0] - '0';
      last_digit = tmp[tmp.length()-1] - '0';
      answer += first_digit * 10 + last_digit;
      cout << answer << "\n";
   }

   return 0;
}
