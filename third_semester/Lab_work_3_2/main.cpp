#include <iostream>
#include <cstring>

int main()
{
    char str[1024];
    std::cout << "Enter the text: " << std::endl;
    std::cin.getline(str, 1024);
    int average = 0;
    int number = 1;
    for (unsigned int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            number++;
        else
            average++;
    }
    average = average / number;
    std::cout << "The average number of symbols in word: " << average << std::endl;
    return 0;
}
