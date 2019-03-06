#include <iostream>
#include <string>
#include <vector>

using namespace std;

class solution {
	public:
		string simplify_path(string p)
		{
			string ret;
			vector <string> words;

			int idx = 0;
			while(p[idx] != '\0') {
				if (p[idx] == '/') {
					if (p[idx + 1] == '/')
						idx++;
					words.push_back("/");
					idx++;
				}
				else if (p[idx] == '.') {
					if (p[idx + 1] == '/') {
						idx += 2;
					}
					else if (p[idx + 1] == '.') {
						words.pop_back();
						words.pop_back();
						idx += 2;
						if (p[idx] == '/')
							idx++;
					}
				}
				else {
					int i = idx;
					while(isalpha(p[i]))
						i++;
					words.push_back(p.substr(idx, i - idx));
					idx = i;
				}
			}

			if (words.back() == "/")
				words.pop_back();

			for (auto &s : words)
				ret += s;
			return ret;
		}
};

int main(int argc, char **argv)
{
	solution s;
	vector <string> test_vectors = {
		"/home/",
		"/a/b/c/../../d/",
		"/a//b/code/.././d/"
	};
	for (auto t : test_vectors)
		cout << "simplify path " << t << " to: " << s.simplify_path(t) << endl;
}
