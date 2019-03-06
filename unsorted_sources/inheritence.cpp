#include <iostream>

struct IEye {
    virtual void open() = 0;

    virtual void look() = 0;

    virtual void close() = 0;
};

struct IMouth {
    virtual void open() = 0;

    virtual void eat() = 0;

    virtual void say() = 0;

    virtual void close() = 0;
};

class Cyclop
        : public IEye, virtual public IMouth {
    // Eye
    void IEye::open() { std::cout << "Eye open\n"; }

    void look() { std::cout << "Eye look\n"; }

    void IEye::close() { std::cout << "Eye close\n"; }

    // Mouth
    void IMouth::open() { std::cout << "Mouth open\n"; }

    void eat() { std::cout << "Mouth eat\n"; }

    void say() { std::cout << "Mouth say\n"; }

    void IMouth::close() { std::cout << "Mouth close\n"; }

};

void look_for(IEye *eye) {
    eye->open();
    eye->look();
    eye->close();
}

void eat(IMouth *mouth) {
    mouth->open();
    mouth->eat();
    mouth->say();
    mouth->close();
}

int main() {
    Cyclop *cyclop = new Cyclop;

    look_for(cyclop);
    eat(cyclop);

    delete cyclop;

    return 0;
}
