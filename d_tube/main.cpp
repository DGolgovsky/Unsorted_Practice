/*
 * Developed by Dmitry Golgovsky <d.westcoast@aol.com>
 *
 * Description of the program
 *
 */

#include <iostream>

#include <vector>
#include <map>
#include <list>
#include <set>

#include <string>
#include <cmath>

#include <functional>
#include <algorithm>

#include <experimental/filesystem>
//#include <filesystem>

#include <thread>

namespace fs = std::experimental::filesystem;
//namespace fs = std::filesystem;

class link
{
private:
	std::string name;
	std::string path;
	std::string url;
public:
	link(std::string name_ = "",
		 std::string path_ = "",
		 std::string url_ = "")
			: name(name_), path(path_), url(url_) {
		std::cerr << "[LOG] Added:\n\t" << *this << std::endl;
	}

	auto get_name() const { return name; }

	auto get_path() const { return path; }

	auto get_url() const { return url; }

	friend std::ostream &operator<<(std::ostream &os, link const &obj) {
		os << obj.get_name() << " <" << obj.get_url() << "> [" << obj.get_path() << "]";
		return os;
	}
};

using pool_t = std::vector<link>;

link split(std::string const &str, char d) {
	std::vector <std::string> read;
	std::string::size_type start = 0;
	std::string::size_type stop = str.find_first_of(d);
	while (stop != std::string::npos) {
		read.push_back(str.substr(start, stop - start));
		start = stop + 1;
		stop = str.find_first_of(d, start);
	}
	read.push_back(str.substr(start));

	link obj(read.at(0), read.at(1), read.at(2));
	return obj;
}

pool_t parse_tsv(std::istream &is) {
	pool_t links;
	try {
		std::string line;
		while (std::getline(is, line))
			links.push_back(split(line, '\t'));
	} catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}

	return links;
}

void execute(pool_t const &video_pool) {
	//std::string const m_path = "/media/extra/Videos/Code/youtube.com/";
	std::string const m_path = "./";
	std::string const youtube = "youtube-dl --autonumber-size 2 -o \"%(autonumber)s. %(title)s.%(ext)s\" ";

	for (auto it : video_pool) {
		std::string path = m_path + it.get_path() + it.get_name();
		fs::create_directory(path);

		std::string cmd = "cd '" + path + "' && " + youtube + it.get_url();
		std::cout << cmd.c_str() << std::endl;
		std::system(cmd.c_str());
		//std::cout << it.get_name() << std::endl;
		// TODO execute youtube-dl for every playlist
	}
}

int main(int, char const **) {
	pool_t video_pool = parse_tsv(std::cin);

	execute(video_pool);

	return 0;
}
