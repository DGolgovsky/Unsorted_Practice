#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

struct Foo
{
    Foo() {
        cout << "Foo" << endl;
    }

    void show() {
        cout << "Hi" << endl;
    }

    ~Foo () {
        cout << "~Foo" << endl;
    }
};

class DeleteFoo
{
public:
    void operator() (Foo* p) const {
        cout << "Call delete for Foo object" << endl;
        delete p;
    }
};

// C++11

int main()
{
// UNIQUE_PTR
    {
        //p1 is Foo
        unique_ptr<Foo> p1(new Foo);
        if (p1)
            p1->show();
        {
            //p2 is p1 (Foo), p1 - empty
            std::unique_ptr<Foo> p2(move(p1));
            if (!p1)
                cout << "p1 is empty" << endl;

            //Revert
            p1 = move(p2);
            if (!p2)
                cout << "p2 is empty" << endl;

            // No copy constructor
            // p1(p2);
        }

        if (p1)
            p1->show();
    }

// SHARED_PTR
    cout << endl << "shared_ptr: " << endl << endl;
    {
        // Constructor with no managed object
        shared_ptr<Foo> sh1;

        // Constructor with object
        // auto sh2 = std::make_shared<Foo>();
        shared_ptr<Foo> sh2(new Foo);

        // Copy pointer
        shared_ptr<Foo> sh3(sh2);

        // Count link on one object
        cout << sh2.use_count() << endl;
        cout << sh3.use_count() << endl;

        // Call methods from one object
        sh2->show();
        sh3->show();

        // Constructor with object and deleter
        shared_ptr<Foo> sh4(new Foo, DeleteFoo());
        //shared_ptr<Foo> sh4(new Foo, default_delete<Foo>());
    }

// DEFAULT_DELETE - functional object
    {
        // ...
    }

    return 0;
}
