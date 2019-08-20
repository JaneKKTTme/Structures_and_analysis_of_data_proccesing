#include <iostream>
#include <cstring>
#include <stack>

std::stack <int> stk;

int main()
{
    char input[256];
    std::cout << "Enter your number: " << std::ends;
    std::cin >> input;
    for (unsigned int i = 0; i < strlen(input); i++) {
        stk.push(input[i]-'0');
    }
    char output[stk.size()];
    int siz = stk.size();
    for (int i = 0; i < siz; i++) {
        output[i] = stk.top() + '0';
        stk.pop();
    }
    std::cout << "Your result number: " << std::ends;
    for (int i = 0; i < siz; i++) {
        std::cout << output[i];
    }
    return 0;
}
