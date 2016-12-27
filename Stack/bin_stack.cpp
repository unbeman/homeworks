//
// Created by devernua on 27.12.16.
//

#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> s(12);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();
    s.pop();



    s.print();

    std::cout << s.size() << std::endl;
    std::cout << s.length() << std::endl;
    return 0;
}

