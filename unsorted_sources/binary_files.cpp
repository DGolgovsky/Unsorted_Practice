#include <iostream>
#include <fstream>
using namespace std;
#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main()
{
    Person someone = {"Frodo", 220, 0.8};
    string filename = "test.bin";
    // Write binary file
    ofstream output_file;
    output_file.open(filename, ios::binary);
    if (output_file.is_open()) {
        output_file.write(reinterpret_cast<char*>(&someone),
                          sizeof(Person));
        output_file.close();
    } else {
        cout << "Could not create file " + filename << endl;
    }
    // Read binary file
    Person someoneElse = {};
    ifstream input_file;
    input_file.open(filename, ios::binary);
    if (input_file.is_open()) {
        input_file.read(reinterpret_cast<char*>(&someoneElse),
                          sizeof(Person));
        input_file.close();
    } else {
        cout << "Could not read file " + filename << endl;
    }

    cout << someoneElse.name << ", "
         << someoneElse.age << ", "
         << someoneElse.height << endl;

    return 0;
}
