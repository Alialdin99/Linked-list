#include "linked_lists.cpp"

int main() {
    linked_list<int>lst;
    lst.insertFirst(12);
    lst.insertFirst(14);
    lst.insertFirst(29);
    lst.deleteLast();
    lst.display();
    lst.insertLast(78);
    lst.display();
    lst.insertAfter(14,15);
    lst.display();
    return 0;
}
