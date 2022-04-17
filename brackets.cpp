#include <iostream>
#include <stack>
#include <string>

using namespace std;

class CBrackets{
    string openBrackets="{[<";
    string closeBrackets="}]>";
    bool isOpen(const char c){ return  openBrackets.find(c)  != string::npos;}
    bool isClose(const char c){ return closeBrackets.find(c) != string::npos;}
    bool isPair(const char ob, const char cb){
        return openBrackets.find(ob) == closeBrackets.find(cb); }
public:
    bool verify(std::string sequence);

};

bool CBrackets::verify(std::string sequence){
    bool retcode = true;
    stack<char> st;
    for(char& c : sequence) {
        if(isOpen(c)){ st.push(c); continue; }
        if(isClose(c)){
            if(!st.empty() && isPair(st.top(),c)){
                st.pop();
            }else{
                retcode=false;
                break;
            }
        }
    }
    if(!st.empty()) retcode = false;
    return retcode;
}

int main(int argc, char **argv) {
    std::cout << "Enter string" << std::endl;
    CBrackets bs;
    bs.verify("{<--->}}-------") && cout << "Ok";
    return 0;
}
