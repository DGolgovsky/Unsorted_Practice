#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Car {
private:
    size_t mSpeed;
    std::string mName;

public:
    Car(const std::string &aName, size_t aSpeed)
            : mSpeed(aSpeed), mName(aName) {}

    const size_t getSpeed() const {
        return mSpeed;
    }

    const std::string &getName() const {
        return mName;
    }
};

void maxSpeedModels(const std::vector <Car> &cars) {
    std::cout << std::endl;
    for (size_t i = 0; i < cars.size(); ++i) {
        if (cars[i].getSpeed() > 180)
            std::cout << "\nModel " << cars[i].getName() << " has speed - " << cars[i].getSpeed();
    }
    std::cout << std::endl;
}

int main() {
    srand(time(NULL));
    std::vector <Car> cars;

    for (int i = 0; i < 20; ++i) {
        cars.push_back(Car("Model" + std::to_string(i), (200 - rand() % (200 - 100))));
        std::cout << "\n" << cars[i].getName() << " " << cars[i].getSpeed();
    }

    maxSpeedModels(cars);
}
