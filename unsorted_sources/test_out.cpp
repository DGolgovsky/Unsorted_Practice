/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <stdio.h>
#include <iostream>
#include <ctime>

class TimedSection
{
private:
	char const *d_name;
    struct timespec d_start;

public:
	TimedSection(char const *name)
		: d_name(name)
	{
		clock_gettime(CLOCK_REALTIME, &d_start);
	}

	~TimedSection()
	{
		timespec end;
		clock_gettime(CLOCK_REALTIME, &end);
		double duration = 1e3 * (end.tv_sec - d_start.tv_sec) +
                          1e-6 * (end.tv_nsec - d_start.tv_nsec);
		std::cerr << d_name << '\t' << std::fixed << duration << " ms\n";
	}
};

int main()
{
	const int iters = 100;
	char const *text = "01234567890123456789";
	{
		TimedSection s("cout with only endl");
        for (int i = 0; i < iters; ++i)
            std::cout << std::endl;
    }
    {
        TimedSection s("cout with only '\\n'");
        for (int i = 0; i < iters; ++i)
            std::cout << '\n';
    }
    {
        TimedSection s("printf with only '\\n'");
        for (int i = 0; i < iters; ++i)
            printf("\n");
    }
    {
        TimedSection s("cout with string constant and endl");
        for (int i = 0; i < iters; ++i)
            std::cout << "01234567890123456789" << std::endl;
    }
    {
        TimedSection s("cout with string constant and '\\n'");
        for (int i = 0; i < iters; ++i)
            std::cout << "01234567890123456789\n";
    }
    {
        TimedSection s("printf with string constant and '\\n'");
        for (int i = 0; i < iters; ++i)
            printf("01234567890123456789\n");
    }
    {
        TimedSection s("cout with some stuff and endl");
        for (int i = 0; i < iters; ++i)
            std::cout << text << "01234567890123456789" << i << std::endl;
    }
    {
        TimedSection s("cout with some stuff and '\\n'");
        for (int i = 0; i < iters; ++i)
            std::cout << text << "01234567890123456789" << i << '\n';
    }
    {
        TimedSection s("printf with some stuff and '\\n'");
        for (int i = 0; i < iters; ++i)
            printf("%s01234567890123456789%i\n", text, i);
    }
	return 0;
}
