#include <stdio.h>

class Vertex
		{
				private:
				float x, y, z;

				public:
				void setToZero() {
					x = 0;
					y = 0;
					z = 0;
				}

				void set(float vx, float vy, float vz) {
					x = vx;
					y = vy;
					z = vz;
				}

				float getY() {
					return y;
				}
		};

int main() {
	Vertex v, v2;

	v.setToZero();
	v.set(1, 2, 3);

	printf("%g\n", v.getY());

	return 0;
}
