#include <iostream>
#include <string>

using namespace std;

class solution {
	public:
		string strstr(string heystack, string needle)
		{
			return strstr(heystack, 0, needle, 0);
		}

		bool strstr_1(string heystack, string needle)
		{
			if (needle.size() == 0)
				return true;
			if (heystack.size() == 0)
				return false;

			if (heystack[0] == needle[0])
				return strstr_1(heystack.substr(1), needle.substr(1));
			else
				return strstr_1(heystack.substr(1), needle);
		}

	private:
		string strstr(string h, int h_idx, string n, int n_idx)
		{
			if (n_idx == n.size())
				return h.substr(h_idx - n_idx);

			if (h_idx == h.size())
				return string();
				//return nullptr; //WRONG! string can not be assigned as nullptr;

			if (h[h_idx] == n[n_idx])
				return strstr(h, h_idx + 1, n, n_idx + 1);

			return strstr(h, h_idx + 1, n, n_idx);
		}
};

int main(int argc, char **argv)
{
	solution a;

	cout << a.strstr("this is the source string", "source") << endl;
	cout << a.strstr("this is the source string", "not exist") << endl;

	cout << a.strstr_1("this is the source string", "source") << endl;
	cout << a.strstr_1("this is the source string", "not exist") << endl;
}
