#include "Singleton.h"

int main()
{
	Singleton& s = Singleton::instance();
	int d = Singleton::instance().data();

	return 0;
}

