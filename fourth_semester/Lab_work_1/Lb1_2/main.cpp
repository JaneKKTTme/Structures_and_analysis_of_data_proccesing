#include <iostream>
#include <stdio.h>
#include <fstream>

int MAX_LENGTH(256);

struct Node {
    int x;
    Node *Next, *Prev;
};

class List {
    Node *Head, *Tail;
public:
    List(): Head(NULL), Tail(NULL) {};
    ~List();
    void Print();
    void Add(int x);
};

List::~List() {
    while (Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

void List::Add(int x) {
    Node *temp = new Node;
    temp->Next = NULL;
    temp->x = x;
    if (Head != NULL) {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else {
        temp->Prev = NULL;
        Head = Tail = temp;
    }
}

void List::Print() {
    Node *temp = Head;
    while (temp != NULL) {
        std::cout << temp->x << " " << std::ends;
        temp = temp->Next;
    }
    std::cout << std::endl;
}

int main()
{
    List output;
    std::ifstream input("test.txt");
    if (!input.is_open()) {
        perror("[Error]");
    }
    char buffer[MAX_LENGTH];
    while (input.getline(buffer, MAX_LENGTH)) {
        int lenght = 0;
        int i = 0;
        while(buffer[i] != '\0') {
            lenght++;
            i++;
        }
        output.Add(lenght);
        buffer[0] = '\0';
    }
    input.close();
    output.Print();
    return 0;
}
