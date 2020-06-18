/*
 * Example of using '\n' instead std::endl
 */

#include <iostream>
#include <fstream>

void write_file_output(std::ostream &os) {
	// 100's of lines
	os << "do something\n";
	os << "do something else\n";
}

void writeln(std::ostream &os, const std::string &str) {
	os << str << '\n';
}

int main() {
	std::ofstream outfile("output.txt", std::ios_base::trunc);

	for (i = 0; i < 1000000; ++i) {
		writeln(outfile, "Hello World");
	}

	outfile << std::flush;

	// 10x slower
	write_file_output(outfile);

	// 10x faster
	std::stringstream ss;
	write_file_output(ss);
	outfile << ss.str();

	return 0;
}
