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
        return "The item doesn't exixt";
    }
};

template<typename t>
linked_list<t>::linked_list()
{
    head = nullptr;
}

template<typename T>
bool linked_list<T>::isEmpty()
{
    return(head== nullptr);
}

template<typename T>
void linked_list<T>::display()
{
    node<T>* temp = head;

    while(temp != nullptr)
    {
        cout<<temp->data<<' ';
        temp = temp->next;
    }

    cout<<endl;
}

template<typename T>
int linked_list<T>::size()
{
    int count = 0;
    node<T>* temp = head;

    while(temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

template<typename T>
bool linked_list<T>::isFound(T key)
{
    node<T>* temp = head;

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
    node<T>* newNode = new node<T>();
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


    node<T>* newNode = new node<T>();
    node<T>* temp = head;

    while(temp->next->data != item && temp!= nullptr)
    {
        temp = temp->next;
    }

    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;

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


    node<T>* newNode = new node<T>();
    node<T>* temp = head;

    while(temp->next->data == item && temp!= nullptr)
    {
        temp = temp->next;
    }

    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;

}

template<typename T>
void linked_list<T>::insertLast(T newValue)
{
    if(isEmpty())
    {
        insertFirst(newValue);
        return;
    }

    node<T>* newNode = new node<T>();
    node<T>* temp = head;

    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    newNode->data = newValue;
    newNode->next = nullptr;
    temp->next = newNode;

}

template<typename T>
void linked_list<T>::deleteFirst()
{
    if(isEmpty()){throw emptyListError();}

    node<T>* delPtr = head;

    head = head->next;
    delete delPtr;
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

    node<T>* delPtr = head;

    if(head->data == value)
    {
        deleteFirst();
        return;
    }
    else
    {
        node<T>* prev;

        while(delPtr->data != value)
        {
            prev = delPtr;
            delPtr = delPtr->next;
        }

        prev->next = delPtr->next;
        delete delPtr;

    }
}

template<typename T>
void linked_list<T>::deleteLast()
{
    if(isEmpty()){throw emptyListError();}

    node<T>* delPtr = head;
    node<T>* prev;

    while(delPtr->next != nullptr)
    {
        prev = delPtr;
        delPtr = delPtr->next;
    }

   prev->next = nullptr;
    delete delPtr;

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

    node<T>* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    return (temp->data);

}


