#include "linked_lists.cpp"

int main() {
    linked_list<int>lst;
    lst.insertFirst(12);
    lst.insertFirst(14);
    lst.insertFirst(29);
    lst.deleteItem(18);
    return 0;
}
