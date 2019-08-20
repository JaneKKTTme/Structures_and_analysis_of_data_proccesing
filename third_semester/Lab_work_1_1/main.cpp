#include <iostream>

int main()
{
    //Seventh variant
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
    int k;
    std::cout << "Enter random number less than size of array: " << std::ends;
    std::cin >> k;
    while ( k >= n )
    {
        std::cout << "Try again, Loser! Less! The size of massive: " << n << std::endl;
        std::cout << "Enter random number: " << std::ends;
        std::cin >> k;
    }
    int *timeable = new int[k];
    for (int i = 0; i < k; i++)
    {
        timeable[i] = arr[i];
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i+k];
    }
    element = 0;
    for (int i = n - k; i < n; i++)
    {
        arr[i] = timeable[element];
        element++;
    }
    delete [] timeable;
    std::cout << "The array: " << std::ends;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << std::ends;
    }
    return 0;
}
