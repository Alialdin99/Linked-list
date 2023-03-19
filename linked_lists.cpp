#include "linked_lists.h"
#include <iostream>

class emptyListError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot delete from an empty list";
    }
};

class itemNotFound : public std::exception {
public:
    const char* what() const noexcept override {
        return "The item doesn't exist";
    }
};

template<typename t>
linked_list<t>::linked_list()
{
    head = nullptr;
    size = 0;
}

template<typename T>
bool linked_list<T>::isEmpty()
{
    return(head== nullptr);
}

template<typename T>
void linked_list<T>::display()
{
    node* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }

    cout<<endl;
}

template<typename T>
int linked_list<T>::getSize()
{
    return size;
}

template<typename T>
bool linked_list<T>::isFound(T key)
{
    node* temp = head;

    while(temp != nullptr)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

template <typename T>
void linked_list<T>::insertFirst(T newValue)
{
    node* newNode = new node();
    newNode->data = newValue;

    if (isEmpty())
    {
        newNode->next = nullptr;
    }
    else
    {
        newNode->next = head;
    }

    head = newNode;
    size++;
}

template<typename T>
void linked_list<T>::insertBefore(T item, T newValue)
{
    if (isEmpty())
    {
        throw emptyListError();
    }
    if(!isFound(item))
    {
       throw itemNotFound();
    }


    node* newNode = new node();
    node* temp = head;

    while(temp->next->data != item && temp!= nullptr)
    {
        temp = temp->next;
    }

    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
    size++;

}

template<typename T>
void linked_list<T>::insertAfter(T item, T newValue)
{
    if (isEmpty())
    {
        throw emptyListError();
    }
    if(!isFound(item))
    {
        throw itemNotFound();
    }


    node* newNode = new node();
    node* temp = head;

    while(temp->next->data == item && temp!= nullptr)
    {
        temp = temp->next;
    }

    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
    size++;

}

template<typename T>
void linked_list<T>::insertLast(T newValue)
{
    if(isEmpty())
    {
        insertFirst(newValue);
        return;
    }

    node* newNode = new node();
    node* temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    newNode->data = newValue;
    newNode->next = nullptr;
    temp->next = newNode;
    size++;

}

template<typename T>
void linked_list<T>::deleteFirst()
{
    if(isEmpty()){throw emptyListError();}

    node* delPtr = head;

    head = head->next;
    delete delPtr;
    size--;
}

template<typename T>
void linked_list<T>::deleteItem(T value)
{
    if (isEmpty())
    {
        throw emptyListError();
    }
    if(!isFound(value))
    {
        throw itemNotFound();
    }

    node* delPtr = head;

    if(head->data == value)
    {
        deleteFirst();
        return;
    }
    else
    {
        node* prev;

        while(delPtr->data != value)
        {
            prev = delPtr;
            delPtr = delPtr->next;
        }

        prev->next = delPtr->next;
        delete delPtr;
        size--;

    }
}

template<typename T>
void linked_list<T>::deleteLast()
{
    if(isEmpty()){throw emptyListError();}

    node* delPtr = head;
    node* prev;

    while(delPtr->next != nullptr)
    {
        prev = delPtr;
        delPtr = delPtr->next;
    }
    prev->next = nullptr;
    delete delPtr;
    size--;

}

template<typename T>
T linked_list<T>::getFirst()
{
    if(isEmpty()){throw emptyListError();}
    return (head->data);
}

template<typename T>
T linked_list<T>::getLast()
{
    if(isEmpty()){throw emptyListError();}

    node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    return (temp->data);

}


