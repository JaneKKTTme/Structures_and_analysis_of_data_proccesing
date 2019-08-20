#include <iostream>
#include <vector>
#include <windows.h>

//Second variant
void multiplyNegativeNumber(std::vector<int> &arr)
{
    if (arr.empty())
        std::cout << "The array is empty." << std::endl;
    else
    {
        int multiply = 1;
        int num = 0;
        for (unsigned int i = 0; i < arr.size(); i++)
            if (arr[i] < 0)
            {
                multiply *= arr[i];
                num++;
            }
        if (num == 0)
            std::cout << "Any negative number." << std::endl;
        else
            std::cout << "Multiplication of negative numbers: " << multiply << std::endl;
    }
}

void deleteMaximum(std::vector<int> &arr)
{
    if (arr.empty())
        std::cout << "The array is empty." << std::endl;
    else
    {
        int maximum = arr[0];
        int pos;
        for (unsigned int i = 0; i < arr.size(); i++)
            if (arr[i] > maximum)
                maximum = arr[i];
        for (unsigned int i = 0; i < arr.size(); i++)
            if (arr[i] == maximum)
            {
                pos = i;
                std::vector<int>::iterator it = arr.begin() + pos;
                arr.erase(it);
            }
    }
}

void createArray(std::vector<int> &arr)
{
    arr.clear();
    int n;
    std::cout << "Enter the size of array: " << std::ends;
    std::cin >> n;
    std::cout << "Enter the array: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }
}

void printArray(std::vector<int> &arr)
{
    if (arr.empty())
        std::cout << "The array is empty." << std::endl;
    else
    {
        std::cout << "Array: " << std::endl;
        for (unsigned int i = 0; i < arr.size(); i++)
        	std::cout << arr[i] << " " << std::ends;;
    }
}

int main()
{
    std::vector<int> arr;
    arr.reserve(100);
    boolean start = true;
    while(start)
    {
        char choice;
        std::cout << "Menu:\n1. Create array.\n2. Print array on screen.\n3. Find multiplication of negative numbers.\n4. Delete all maximums.\nYour choice: " << std::ends;
        std::cin >> choice;
        switch(choice)
        {
            case '1':
                createArray(arr);
                std::cout << "[Done.]" << std::endl;
                break;
            case '2':
                printArray(arr);
                std::cout << "[Done.]" << std::endl;
                break;
            case '3':
                multiplyNegativeNumber(arr);
                std::cout << "[Done.]" << std::endl;
                break;
            case '4':
                deleteMaximum(arr);
                std::cout << "[Done.]" << std::endl;
                break;
            case '0':
                start = false;
                std::cout << "[End.]" << std::endl;
                break;
            default:
                start = false;
                std::cout << "[Error of input data. Program has finished.]" << std::endl;
                break;
        }
    }
    return 0;
}
