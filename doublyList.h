#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    node *next;
    node *prev;
};

template <typename T>
class doublyList
{
private:
    node<T> *head = NULL;
    node<T> *tail = NULL;

public:
    void pushBack(T value);
    void pushFront(T value);
    void insert(T value, int position);
    void remove(T value);
    int size();
    T get(int position);
    bool empty();
    void display();
};

template <typename T>
T doublyList<T>::get(int position)
{
    node<T> *cur = head;
    node<T> *pre = head;

    int count = 0;
    while (cur != NULL && count != position + 1)
    {
        pre = cur;
        if (count == position)
            return pre->data;

        cur = cur->next;
        count++;
    }

    return 0;
};

template <typename T>
bool doublyList<T>::empty()
{
    node<T> *cur = head;

    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count ? false : true;
};

template <typename T>
int doublyList<T>::size()
{
    node<T> *cur = head;

    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count;
}

template <typename T>
void doublyList<T>::remove(T value)
{
    node<T> *previos = head;
    node<T> *current = head;
    node<T> *prevprev = head;

    while (current != NULL)
    {
        prevprev = previos;
        previos = current;
        current = current->next;

        if (previos->data == value)
        {
            if (current == NULL)
            {
                tail = prevprev;
                prevprev->next = NULL;
            }
            else
            {
                if (head == previos)
                {
                    head = current;
                    current->prev = NULL;
                }
                else
                {
                    prevprev->next = current;
                    current->prev = prevprev;
                }
            }
        }
    }
}

template <typename T>
void doublyList<T>::insert(T value, int position)
{
    node<T> *temp = new node<T>;
    temp->data = value;

    if (position == 0)
    {
        if (head == NULL)
        {
            temp->next = NULL;
            tail = temp;
            head = temp;
        }
        else
        {
            node<T> *cur = head;
            cur->prev = temp;

            temp->next = head;
            head = temp;
        }
        temp->prev = NULL;
    }
    else
    {
        node<T> *cur = head;
        node<T> *pre = head;
        int count = 0;
        while (cur != NULL)
        {
            pre = cur;
            cur = cur->next;
            count++;
        }

        cur = head;
        pre = head;
        int i = 0;
        while (cur != NULL && i != position)
        {
            pre = cur;
            cur = cur->next;
            i++;
        }

        if (position > count)
        {
            return;
            throw "Wrong position";
        }

        if (pre == tail)
        {
            cur = head;
            pre = head;

            while (cur != NULL)
            {
                pre = cur;
                cur = cur->next;
            }

            temp->next = NULL;
            pre->next = temp;
            tail = temp;
        }
        else
        {
            cur = head;
            pre = head;

            int i = 0;
            while (cur != NULL && i != position)
            {
                pre = cur;
                cur = cur->next;

                i++;
            }
            pre->next = temp;
            cur->prev = temp;
            temp->next = cur;
            temp->prev = pre;
        }
    }
};

template <typename T>
void doublyList<T>::pushFront(T value)
{
    node<T> *temp = new node<T>;
    temp->data = value;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp->next = NULL;
    }
    else
    {
        node<T> *cur = head;
        node<T> *pre = head;

        while (cur != NULL)
        {
            pre = cur;
            cur = cur->next;
        }

        temp->next = head;
        head = temp;
        pre->prev = temp;
    }
};

template <typename T>
void doublyList<T>::display()
{
    node<T> *cur = head;

    while (cur != NULL)
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
};

template <typename T>
void doublyList<T>::pushBack(T value)
{
    node<T> *temp = new node<T>;
    temp->data = value;

    temp->next = NULL;

    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        node<T> *cur = head;
        node<T> *pre = head;
        while (cur != NULL)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->prev = pre;
        pre->next = temp;
    }

    tail = temp;
};