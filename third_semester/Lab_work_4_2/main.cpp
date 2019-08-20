#include <iostream>
#include <vector>
#include <windows.h>

//Fourteenth variant
void sumOfEvenNumber(std::vector<int> &arr)
{
    if (arr.empty())
        std::cout << "The array is empty." << std::endl;
    else
    {
        int sum = 0;
        for (unsigned int i = 0; i < arr.size(); i = i + 2)
            sum += arr[i];
        std::cout << "The sum of even numbers: " << sum << std::endl;
    }
}

void insertNumberAfterMax(std::vector<int> &arr)
{
    if (arr.empty())
        std::cout << "The array is empty." << std::endl;
    else
    {
        int x;
        std::cout << "Enter random number: " << std::ends;
        std::cin >> x;
        int maximum = arr[0];
        for (unsigned int i = 0; i < arr.size(); i++)
            if (arr[i] > maximum)
                maximum = arr[i];
        int pos = 0;
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == maximum)
            {
                pos = i;
                std::vector<int>::iterator it = arr.begin() + pos + 1;
                arr.insert(it, x);
            }
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
        std::cout << "Menu:\n1. Create array.\n2. Print array on screen.\n3. Find sum of even numbers.\n4. Insert numbers X after each maximum.\nYour choice: " << std::ends;
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
                sumOfEvenNumber(arr);
                std::cout << "[Done.]" << std::endl;
                break;
            case '4':
                insertNumberAfterMax(arr);
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
