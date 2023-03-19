#include "linked_lists.cpp"

int main() {
    linked_list<int>lst;
    lst.insertFirst(12);
    lst.insertFirst(14);
    lst.insertFirst(29);
    lst.display();
    cout << lst.size() << endl;

    lst.insertBefore(14,10);
    lst.display();
    cout << lst.size() << endl;
    lst.insertLast(2020);
    lst.display();
    cout << lst.size() << endl;
    lst.deleteItem(2020);
    lst.display();
    cout << lst.size() << endl;
    lst.deleteItem(10);
    lst.display();
    cout << lst.size() << endl;
    lst.deleteItem(29);
    lst.display();
    cout << lst.size() << endl;
    return 0;
}
