#include <iostream>

int main()
{
    int n, m;
    std::cout << "Enter the size of matrix: " << std::ends;
    std::cin >> n;
    std:: cin >> m;
    int matrix[n][m];
    std::cout << "Enter the matrix: " << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int element;
            std::cin >> element;
            matrix[i][j] = element;
        }
    std::cout << "Your matrix:\n" << std::ends;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << std::ends;
        }
        std::cout << "\n" << std::ends;
    }
    int el = 0;
    int *b = new int[m];
    std::cout << "Enter the array: " << std::ends;
    for (int i = 0; i < m; i++)
    {
        std::cin >> el;
        b[i] = el;
    }
    el = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                el++;
            }
        }
        if (el == m)
        {
            for (int j = 0; j < m; j++)
                matrix[i][j] = b[j];
        }
        el = 0;
    }
    std::cout << "Result:\n" << std::ends;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << std::ends;
        }
        std::cout << "\n" << std::ends;
    }
    return 0;
}
