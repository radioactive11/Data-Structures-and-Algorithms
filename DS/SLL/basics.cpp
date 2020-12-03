#include <iostream>
#include "SLL.h"

using namespace std;


int main(int argc, char const *argv[])
{
    Node* head = nullptr;
    head = insert_at_start(head, 1);
    head = insert_at_start(head, 2);
    head = insert_at_start(head, 3);
    head = insert_at_start(head, 4);
    head = insert_at_start(head, 5);
    insert_at_n(head, 10, 2);
    print(head);
    Node* ptr = search(head, 3);
    return 0;
}
