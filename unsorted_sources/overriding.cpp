#include <iostream>

class Vector
{
private:
	int x, y;

public:
	Vector(int x = 0, int y = 0) :
			x(x),
			y(y) {}

	Vector operator+(Vector const &v) {
		return Vector(x + v.x, y + v.y);
	}

	Vector operator-() const { return Vector(-x, -y); }

	Vector &operator-(Vector const &v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector &operator*(double const d) {
		x *= d;
		y *= d;
		return *this;
	}

	Vector &operator*=(double const d) {
		x *= d;
		y *= d;
		return *this;
	}

	Vector &operator++() { // prefix
		++x;
		++y;
		return *this;
	}

	Vector operator++(int) { // postfix
		Vector tmp(*this);
		++(*this);
		return tmp;
	}

	void set_x(int const &n) { x = n; }

	void set_y(int const &n) { y = n; }

	int get_x() const { return x; }

	int get_y() const { return y; }

	friend std::istream &operator>>(std::istream &is, Vector &v) {
		std::cout << "[x,y]: ";
		is >> v.x >> v.y;
		return is;
	}

	friend std::ostream &operator<<(std::ostream &os, Vector const &v) {
		os << "[" << v.x << "," << v.y << "]";
		return os;
	}
};

int main(void) {
	Vector v1;
	Vector v2;
	Vector v3;

	std::cout << "V1";
	std::cin >> v1;
	std::cout << "V2";
	std::cin >> v2;

	v3 = v1 + v2;

	std::cout << "V3" << v3 << std::endl;

	return 0;
}
