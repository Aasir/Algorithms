#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void reverseString(string &s, int i, int j){
    char temp;
    while(i < j){
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
   // cout <<  "Reverse String function: " << s << endl;
}


void reverseWords(string &s){
    int start = 0;
    int end = 1;

    while (end < s.length()){
         if (s[end] == ' '){
            cout << "String: " << s << " Start: " << start << " End: " << end << endl;
            reverseString(s, start, end - 1);
            start =  end + 1;
        }
        end++;
    }
    reverseString(s, start, s.length() - 1);
    reverseString(s, 0 , s.length() - 1);
}

int main(){
    std::string in_str = "NIGGA MY IS MESSI";
    std::cout << "String: " <<  in_str << std::endl;
    reverseWords(in_str);
    std::cout << "Reverse String: " <<  in_str << std::endl;
    return 0;
}
