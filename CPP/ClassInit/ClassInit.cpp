// ClassInit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ChildClass {
public:
    ChildClass() {
        m_mem = 0;
        std::cout << "ChildClass()" << std::endl;
    }

    ChildClass(int mem) {
        m_mem = mem;
        std::cout << "ChildClass(int)" << std::endl;
    }
public:
    int m_mem;
};

class Containner {
public:
    Containner() : m_child(11) {

    }
public:
    ChildClass m_child;
};

int main()
{
    Containner parent;
    std::cout << parent.m_child.m_mem << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
