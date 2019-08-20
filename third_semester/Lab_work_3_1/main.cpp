#include <iostream>
#include <cstring>

int main()
{
    char str[1024];
    std::cout << "Enter the text: " << std::endl;
    std::cin.getline(str, 1024);
    char _tmp[1024];
    int k = 0;
    std::string result = "";
    for (unsigned int i = 0; i < strlen(str); i++)
    {
        if (i != strlen(str)-1 && isalnum(str[i]))
        {
            _tmp[k] = str[i];
            k++;
        }
        else if (str[i] == ' ' && isalnum(str[i-1]))
        {
            k--;
            unsigned int num = 0;
            for (unsigned int j = 0; j < strlen(_tmp); j++ )
                if (isdigit(_tmp[j]))
                    num++;
            if (num == strlen(_tmp))
                result += "*";
            else
                result += _tmp;
            result += ' ';
            for (int n = 0; n < k+1; n++)
                _tmp[n] = 0;
            k = 0;
        }
        else if( i == strlen(str)-1)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                k--;
                unsigned int num = 0;
                for (unsigned int j = 0; j < strlen(_tmp); j++ )
                    if (isdigit(_tmp[j]))
                        num++;
                if (num == strlen(_tmp))
                    result += "*";
                else
                {
                    k++;
                    _tmp[k] = str[i];
                    result += _tmp;
                }
            }
            else
            {
                result += _tmp;
                result += str[i];
            }
        }
    }
    for (int n = 0; n < k; n++)
        _tmp[n] = 0;
    std::cout << result << std::endl;
    return 0;
}
