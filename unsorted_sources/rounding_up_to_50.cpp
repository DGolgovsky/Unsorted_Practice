/*
 * Задачка на округление. Предположим, вы разрабатываете систему для
 * компании, которая работает с розничной торговлей. Их девиз: «никаких
 * копеек». Но наша задача округлять не просто до копеек или до десятков
 * рублей, а округлять до 50 рублей. То есть, 130 рублей округляются в 150
 * рублей, а 115 рублей — в 100 рублей. Как сделать округление по такому
 * принципу?
 */

#include <iostream>
#include <cmath>

int main() {
    double number = 0.0;

    std::cout << "Enter some decimal number: ";
    std::cin >> number;
/* first idea
    int rem = fmod(number, 100);

    number -= rem;
    if (rem > 74)
        number = (int)number + 100;
    else if (rem > 24)
        number = (int)number + 50;
*/
    double rem = round(number / 50.0);
    number = 50 * rem;

    std::cout << "Number after rounding: " << number << std::endl;

    return 0;
}
