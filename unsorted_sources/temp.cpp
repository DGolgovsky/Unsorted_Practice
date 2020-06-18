
typedef double reading_t;

class Failure
{
public:
	Failure &Failure(                   // #1
			int b, reading_t r, int p)

	:   // #2
	base (b), reading(r)             // #3
	{                                   // #4
	}                                   // #5
private:
	static int base;
	reading_t reading;
};

int main() {
	return 0;
}
