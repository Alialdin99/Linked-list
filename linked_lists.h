//
// Created by lenovo on 3/18/2023.
//

#ifndef LINKED_LISTS_LINKED_LISTS_H
#define LINKED_LISTS_LINKED_LISTS_H
using namespace std;

template <typename T>
class linked_list
{
private:

    class node
    {
    public:
        T data;
        node* next;

    };
    int size;
    node* head;
public:
    linked_list();
    bool isEmpty();
    void display();
    int  getSize();
    bool isFound(T key);
    void insertFirst(T newValue);
    void insertBefore(T item, T newValue);
    void insertAfter(T item, T newValue);
    void insertLast(T newValue);
    void deleteFirst();
    void deleteItem(T value);
    void deleteLast();
    T  getFirst();
    T  getLast();


};
#endif //LINKED_LISTS_LINKED_LISTS_H

