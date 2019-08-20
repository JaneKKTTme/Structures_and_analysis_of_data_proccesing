#include <iostream>

int main()
{
    int n, m;
    std::cout << "Enter the size of matrix: " << std::ends;
    std::cin >> n;
    std:: cin >> m;
    int matrix[n][m];
    std::cout << "Enter the matrix:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int element;
            std::cin >> element;
            matrix[i][j] = element;
        }
    std::cout << "Your array:\n" << std::ends;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << std::ends;
        }
        std::cout << "\n" << std::ends;
    }
    int maxElement = matrix[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] > maxElement)
            {
                maxElement = matrix[i][j];
            }
        }
    std::cout << "Max element: " << maxElement << std::endl;
    int el = 0;
    int *maxLine = new int[n];
    for (int i = 0; i < n; i++)
    {
        int p = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == maxElement && p < 1)
            {
                maxLine[el] = i + 1;
                el++;
                p++;
            }
        }
    }
    std::cout << "The array of line of maximum: " << std::ends;
    for (int i = 0; i < el; i++)
        std::cout << maxLine[i] << std::ends;
    return 0;
}
