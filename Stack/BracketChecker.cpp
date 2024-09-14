#Bracket Checker Using Stack

// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s ;
    cin >> s;
    int n = s.size() - 1;
    stack <char> st;
    bool found = true , fnd = false;
    for(int i = 0 ; i < s.size() ; ++i){
      if(s[i] =='{' or s[i] == '(' or s[i] == '[' or s[i] == '<' or (s[i] == '"' and !fnd)){
                st.push(s[i]);
                if(s[i] == '"'){
                    fnd = true;
                }
            }
     else if(s[i] == '/' and i + 1 != n and s[i + 1] == '*'){
                st.push(s[i]);
                i++;
            }
    else{
          if (!st.empty() and s[i] == '}' and st.top() == '{'){
                st.pop();
            }
         else if (!st.empty() and s[i] == ')' and st.top() == '('){
                st.pop();
            }
         else if (!st.empty() and s[i] == ']' and st.top() == '['){
                st.pop();
            }
        else if (!st.empty() and s[i] == '>' and st.top() == '<'){
                st.pop();
            }
        else if (!st.empty() and s[i] == '"' and st.top() == '"'){
                st.pop();
                fnd = false;
            }
        else if(!st.empty() and s[i] == '*' and i + 1 != n and s[i + 1] == '/' and st.top() == '/'){
                st.pop();
                i++;
            }
        else  {
            found = false;
            break;
        }
        }
    }
 if(st.empty() and found)cout << "YES\n";
 else cout << "NO\n";
    return 0;
}
