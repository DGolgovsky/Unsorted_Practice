#include <iostream>

inline void my_elevator(size_t room)
{
    int pos = 1;
    int floor = 1;
    int seq = 1;
    while (seq < room) {
        pos++;
        seq = pos*pos;
        //floor += seq;
    }
    pos--;
    int place = seq - 1 - room;
    for (int i = 1; i < pos; ++i){
        floor += i*i;
    }
    std::cout << "\t<My> Floor: " << floor << ", Place: " << place << '\n';
}

inline void second_elevator(unsigned int room)
{
    unsigned int a = 0;
    unsigned int c = 0;

    for (unsigned int i = 1; c < room; ++i) {
        c += i * i;
        a += i;
    }

    unsigned int t = a;

    if (c != room) {
        for (t = a; c > room; --t) {
            c -= t;
        }
    }

    std::cout << "\t<2n> Floor: " << c << ", Place: " << t << '\n';
}

inline void elevator(unsigned int room)
{
    unsigned int box = 1;
    unsigned int floor = 1;
    unsigned int pos = 0;
    while((pos + (box * box)) < room) {
        pos += (box * box);
        floor += box;
        box++;
    }
    unsigned int onfloor = 1;
    while((pos + (onfloor * box)) <= room) {
        pos += onfloor * box;
        onfloor++;
    }
    floor += onfloor - 1;
    unsigned int place = 1;
    while((pos + place) <= room) place++;
    pos += place - 1;
    std::cout << "\t<GB> Floor: " << floor << ", Place: " << place << std::endl;
    //std::cout << "Position in the sequence: " << pos << std::endl;
}

int main()
{
	unsigned int room = 1;
	//std::cin >> room;
        for (;room < 31; ++room) {
            std::cout << "Room: " << room << "\n";
	elevator(room);
	second_elevator(room);
        my_elevator(room);
        }
	return 0;
}
