#include <iostream>

struct A {
    A() = default;
    A(const A&) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    A& operator=(const A&) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
    A(A&&) { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    A& operator=(A&&) { std::cout << __PRETTY_FUNCTION__ << std::endl; return *this; }
};

A & fun1(A & s)
{
    return s;
}

A && fun2(A & s)
{
    return std::move(s);
}

A fun3(A & s)
{
    return std::move(s);
}

A fun4(A s)
{
    return std::move(s);
}

A fun5(A s)
{
    return std::forward<A>(s);
}

A && fun6(A && s)
{
    return std::move(s);
}

A fun7(A && s)
{
    return s;
}

int main() {
    std::cout << "fun1:\n";
    A a,b;    
    b = fun1(a);

    std::cout << "\nfun2:\n";
    A c,d;    
    d = fun2(c);
    std::cout << "\nfun3:\n";    
    A e,f;    
    f = fun3(e);
    std::cout << "\nfun4:\n";    
    A g,h;    
    h = fun4(g);
    std::cout << "\nfun5:\n";    
    A i,j;    
    j = fun5(i);
    std::cout << "\nfun6:\n";    
    A k,l;    
    //l = fun6(k);
    std::cout << "\nfun7:\n";    
    A m,n;    
    //n = fun7(m);
    
    return 0;
}
