#include <iostream>

using namespace std;

//Bước 1: Tạo cấu trúc node

struct Node
{
    int data;
    Node* pNext;
};

//Bước 2: Khởi tạo node => viết hàm: value => *node
Node* initNode(int value)
{
    Node* p = new Node;
    p->data = value;
    p->pNext = NULL;

    return p;
}

//Bước 3: Tạo cấu trúc stack
struct Stack
{
    Node* pTop;
};

//Bước 4: Khởi tạo Stack
void initStack(Stack &s)
{
    s.pTop = NULL;
}

void push(Stack &s, Node* p)
{
    if (s.pTop == NULL)
    {
        s.pTop = p;
    }
    else
    {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void printfStack(Stack s)
{
    cout << "Stack = Top <     ";
    for (Node* p = s.pTop; p != NULL; p=p->pNext)
    {
        cout << p->data << "    ";
    }
    cout << ">" << endl;
}

int pop(Stack& s)
{
    if (s.pTop == NULL)
        return NULL;

    Node* p = s.pTop;
    s.pTop = s.pTop->pNext;
    int value = p->data;
    delete p;
    return value;
}

bool isEmpty(Stack s)
{
    return s.pTop == NULL;
}

int main()
{
    Stack s;
    initStack(s);

    cout << "Kiem tra Stack rong: " << isEmpty(s);

    Node* p1 = initNode(10);
    Node* p2 = initNode(39);
    Node* p3 = initNode(79);

    push(s, p1);
    push(s, p2);
    push(s, p3);

    printfStack(s);
    int value = pop(s);
    pop(s);

    printfStack(s);

    return 0;
}
