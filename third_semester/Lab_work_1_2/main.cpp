#include <iostream>
#include <cmath>

int* nullArray(int* massive, int siz)
{
    for (int i = 0; i < siz; i++)
        massive[i] = 0;
    return massive;
}

int main()
{
    //Fourteenth variant
    int n;
    std::cout << "Enter size of array(from 1 to 100): " << std::ends;
    std::cin >> n;
    int *arr = new int[n];
    std::cout << "Enter elements of array: " << std::endl;
    int element;
    for (int i = 0; i < n; i++)
    {
        std::cin >> element;
        arr[i] = element;
    }
    int x;
    std::cout << "Enter random number: " << std::ends;
    std::cin >> x;
    int *timeable = new int[n*2];
    timeable = nullArray(timeable, n*2);
    int el = 0;
    for (int i = 0; i < n; i++)
    {
        if ((int)(arr[i] / pow(10, (int)log10(arr[i]))) == 5 || (int)(arr[i] / pow(10, (int)log10(arr[i]))) == -5)
        {
            timeable[el] = x;
            timeable[el+1] = arr[i];
            el = el + 2;
        }
        else
        {
            timeable[el] = arr[i];
            el++;
        }
    }
    int m = n;
    for (int i = 0; i < n*2; i++)
        if ((int)(timeable[i] / pow(10, (int)log10(timeable[i]))) == 5 || (int)(timeable[i] / pow(10, (int)log10(timeable[i]))) == -5)
            m++;
    std::cout << "The array: " << std::ends;
    for (int i = 0; i < m; i++)
    {
        std::cout << timeable[i] << std::ends;
    }
    return 0;
}
