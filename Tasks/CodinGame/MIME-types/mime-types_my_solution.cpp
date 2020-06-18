#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int N; // Number of elements which make up the association table.
	cin >> N;
	cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q;
	cin.ignore();
	map <string, string> list; // = new vector<string>(N * 2);
	for (int i = 0; i < N; i++) {
		string EXT; // file extension
		string MT; // MIME type.
		cin >> EXT >> MT;
		cin.ignore();
		std::transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
		list[EXT] = MT;
	}
	vector <string> f_names;
	for (int i = 0; i < Q; i++) {
		string FNAME; // One file name per line.
		getline(cin, FNAME);
		std::transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
		f_names.push_back(FNAME);
	}

	for (const auto &f_it : f_names) {
		std::string::size_type n;
		n = f_it.rfind('.');
		if (n != std::string::npos) {
			auto it = list.find(f_it.substr(n + 1));
			if (it != list.end()) {
				cout << it->second << endl;
			} else {
				cout << "UNKNOWN" << endl;
			}
		} else {
			cout << "UNKNOWN" << endl;
		}
	}

	return 0;
}
