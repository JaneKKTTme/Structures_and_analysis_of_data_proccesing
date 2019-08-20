#include <iostream>

#define N 5

void numberOfLoops(int g[N][N])
{
    int number = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i == j && g[i][j] == 1)
                number++;
    std::cout << "This graph has " << number << " loop(s)." << std::endl;
}

void searchOfIsolatedVertex(int g[N][N])
{
    int number = 0;
    int sum = 0;
    int *vertex = new int[number];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (g[i][j] == 0)
                sum++;
        if(sum == N)
        {
            number++;
            vertex = new int[number];
            vertex[number-1] = i+1;
        }
        sum = 0;
    }
    std::cout << "This graph has " << number << " isolated vertex(es)." << std::endl;
    if (number != 0)
    {
        std::cout << "Isolated vertex: ";
        for (int i = 0; i < number; i++)
            std::cout << vertex[i];
    }
    std::cout << std::endl;
}

void degreeOfVertices(int g[N][N])
{
    int sum = 0;
    int *deg = new int[N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (g[i][j] == 1)
                sum++;
        deg[i] = sum;
        sum = 0;
    }
    std::cout << "Degrees of vertices:" << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << "deg(" << i << ") = " << deg[i] << std::endl;
}

void edgeSequence(int g[N][N])
{
    std:: cout << "Edge sequences: ";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (i != j && g[i][j] == 1)
            {
                std::cout << "(" << i+1 << " ," << j+1 << ")";
                if (i != N && j != N)
                    std::cout << "; ";
            }
    }
}

int main()
{
    //Вариант 1
    int graph[5][5] = {
    {1, 0, 0, 1, 1},
    {0, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0},
    };
    std::cout << "Graph:\n/" << std::ends;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << graph[i][j] << " " << std::ends;
        if (i == 0)
            std::cout << "\\\n| ";
        else if (i == N-2)
            std::cout << " |\n\\ ";
        else if (i == N-1)
            std::cout << " /\n";
        else
            std::cout << " |\n| ";
    }
    numberOfLoops(graph);
    searchOfIsolatedVertex(graph);
    degreeOfVertices(graph);
    edgeSequence(graph);
    return 0;
}
