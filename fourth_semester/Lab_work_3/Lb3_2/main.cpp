#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define N 3

void min_way()
{
    int matrix[N][N] = {
    {0, 3, 7},
    {3, 0, 3},
    {7, 3, 0}
    };
    int distance[N];
    int visited[N];
    int tmp;
    int min_i, min_d;
    std::cout << "Distance between towns:" <<std::endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
    for (int i = 0; i < N; i++)
    {
        distance[i] = 10000;
        visited[i] = 1;
    }
    distance[0] = 0;
    do
    {
        min_i = 10000;
        min_d = 10000;
        for (int i = 0; i < N; i++)
        {
            if ((visited[i] == 1) && (distance[i] < min_d))
            {
                min_d = distance[i];
                min_i = i;
            }
        }
        if (min_i != 10000)
        {
            for (int i = 0; i < N; i++)
            {
                if (matrix[min_i][i] > 0)
                {
                    tmp = min_d + matrix[min_i][i];
                    if (tmp < distance[i])
                    {
                        distance[i] = tmp;
                    }
                }
            }
            visited[min_i] = 0;
        }
    } while (min_i < 10000);
    for (int i = 0; i < N; i++)
        visited[i] = 0;
    int point_of_arrival = N-1;
    visited[0] = point_of_arrival + 1;
    int k = 1;
    int weight = distance[point_of_arrival];
    while (point_of_arrival > 0)
    {
        for(int i=0; i < N; i++)
            if (matrix[point_of_arrival][i] != 0)
            {
                tmp = weight - matrix[point_of_arrival][i];
                if (tmp == distance[i])
                {
                    weight = tmp;
                    point_of_arrival = i;
                    visited[k] = i + 1;
                    k++;
                }
            }
    }
    std::cout << "\nShort way:" <<std::endl;
    for (int i = k-1; i >= 0; i--)
        if (i == 0)
            std::cout << visited[i];
        else
            std::cout << visited[i] << " -> ";
}

void max_way()
{
    int matrix[N][N] = {
    {0, 3, 7},
    {3, 0, 3},
    {7, 3, 0}
    };
    int distance[N];
    int visited[N];
    int tmp;
    int max_i, max_d;
    for (int i = 0; i < N; i++)
    {
        distance[i] = 0;
        visited[i] = 1;
    }
    distance[0] = 0;
    do
    {
        max_i = 1;
        max_d = 0;
        for (int i = 0; i < N; i++)
        {
            if ((visited[i] == 1) && (distance[i] >= max_d))
            {
                max_d = distance[i];
                max_i = i;
            }
        }
        if (max_i != 0)
        {
            for (int i = 0; i < N; i++)
            {
                if (matrix[max_i][i] > 0)
                {
                    tmp = max_d + matrix[max_i][i];
                    if (tmp > distance[i])
                    {
                        distance[i] = tmp;
                    }
                }
            }
            visited[max_i] = 0;
        }
    } while (max_i > 0);
    for (int i = 0; i < N/2; i++)
    {
        tmp = distance[N-i-1];
        distance[N-i-1] = distance[i];
        distance[i] = tmp;
    }
    for (int i = 0; i < N; i++)
        visited[i] = 0;
    int point_of_arrival = N-1;
    visited[0] = point_of_arrival + 1;
    int k = 1;
    int weight = distance[point_of_arrival];
    while (point_of_arrival > 0)
    {
        for(int i=0; i < N; i++)
            if (matrix[point_of_arrival][i] != 0)
            {
                tmp = weight - matrix[point_of_arrival][i];
                if (tmp == distance[i])
                {
                    weight = tmp;
                    point_of_arrival = i;
                    visited[k] = i + 1;
                    k++;
                }
            }
    }
    std::cout << "\n\nThe longest way:" <<std::endl;
    for (int i = k-1; i >= 0; i--)
        if (i == 0)
            std::cout << visited[i];
        else
            std::cout << visited[i] << " -> ";
}

int main()
{
    //Вариант 5
    min_way();
    max_way();
    return 0;
}
