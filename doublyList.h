#include <iostream>

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
    node<T> *head = nullptr;
    node<T> *tail = nullptr;

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
    while (cur != nullptr && count != position + 1)
    {
        pre = cur;
        if (count == position)
            return pre->data;

        cur = cur->next;
        count++;
    }

    return -1;
};

template <typename T>
bool doublyList<T>::empty()
{
    return head ? false : true;
};

template <typename T>
int doublyList<T>::size()
{
    node<T> *cur = head;

    int count = 0;
    while (cur != nullptr)
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

    while (current != nullptr)
    {
        prevprev = previos;
        previos = current;
        current = current->next;

        if (previos->data == value)
        {
            if (current == nullptr)
            {
                tail = prevprev;
                prevprev->next = nullptr;
            }
            else
            {
                if (head == previos)
                {
                    head = current;
                    current->prev = nullptr;
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
        if (head == nullptr)
        {
            temp->next = nullptr;
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
        temp->prev = nullptr;
    }
    else
    {
        node<T> *cur = head;
        node<T> *pre = head;
        int count = 0;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
            count++;
        }

        cur = head;
        pre = head;
        int i = 0;
        while (cur != nullptr && i != position)
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

            while (cur != nullptr)
            {
                pre = cur;
                cur = cur->next;
            }

            temp->next = nullptr;
            pre->next = temp;
            tail = temp;
        }
        else
        {
            cur = head;
            pre = head;

            int i = 0;
            while (cur != nullptr && i != position)
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
    temp->prev = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        temp->next = nullptr;
    }
    else
    {
        node<T> *cur = head;
        node<T> *pre = head;

        while (cur != nullptr)
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

    while (cur != nullptr)
    {
        std::cout << cur->data << std::endl;
        cur = cur->next;
    }
};

template <typename T>
void doublyList<T>::pushBack(T value)
{
    node<T> *temp = new node<T>;
    temp->data = value;

    temp->next = nullptr;

    if (head == nullptr)
    {
        temp->prev = nullptr;
        head = temp;
    }
    else
    {
        node<T> *cur = head;
        node<T> *pre = head;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->prev = pre;
        pre->next = temp;
    }

    tail = temp;
};
