#include <iostream>
#include "doublyList.h"
using namespace std;

int main()
{
    doublyList<int> list;
    list.pushFront(5);
    list.pushBack(15);
    list.insert(10, 1);

    cout << "Displaying List: \n";
    list.display();

    cout << endl
         << "Properties " << endl
         << "Size: " << list.size() << endl
         << "Empty: " << (list.empty() ? "true" : "false") << endl;
}