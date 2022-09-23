// zhihu1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <map>

//=========
// https://www.zhihu.com/question/442382012/answer/2604422490

class A {

};

void f1(std::unique_ptr<A>&& a1) {

}

void f2(std::unique_ptr<A>&& a2) {
    //这里编译有错误，如何修改？
    //f1(a2);
    f1( std::move(a2) );
}

int main1()
{
    std::unique_ptr<A> spA(new A());
    //这里编译有错误，如何修改？
    //f2(spA);
    f2( std::move(spA) );

    return 0;
}

//=================
class A2 {
public:
    A2() {

    }

    ~A2() {

    }
};

class B {
public:
    B(A2* pA) : m_spA(pA) {

    }

    ~B() {

    }

private:
    std::unique_ptr<A2>  m_spA; 
};


int main2()
{
    {
        std::map<int, std::shared_ptr<B>> mymap;

        auto pA = std::make_unique<A2>();
        auto pB = std::make_shared<B>(pA.get());    //m_spA should be shared_ptr

        mymap.emplace(1, pB);
    }

    std::cout << "hello world." << std::endl;

    return 0;
}

int main()
{
    //main1();
    main2();
}

