#include <iostream>
#include <string>

using namespace std;

class solution {
	public:
		bool is_match(const char *s, const char *p)
		{
			while(*s != '\0') {
				switch (*p) {
					case '\0':
						return true;
						//break;
					case '?':
						s++;
						p++;
						break;
					case '*':
						p++;
						while (*p == '?' || *p == '*') {
							p++;
						}
						while(*s != *p && *s != '\0')
							s++;
						break;
					default:
						if (*p != *s)
							return false;
						s++;
						p++;
						break;
				}
			}

			return *p == '\0';
		}

		bool is_match_dp(string s, string p)
		{
			return is_match(s, 0, p, 0);
		}
	private:
		bool is_match(string s, int s_idx, string p, int p_idx)
		{
			if (p_idx == p.size())
				return true;
			if (s_idx == s.size()) {
				while(p[p_idx] == '*' || p[p_idx] == '?')
					p_idx++;
				if (p_idx == p.size())
					return true;
				return false;
			}

			if (p[p_idx] == '*')
				return is_match(s, s_idx + 1, p, p_idx + 1) ||
					is_match(s, s_idx + 1, p, p_idx);

			if (p[p_idx] == '?')
				return is_match(s, s_idx + 1, p, p_idx + 1);

			if (s[s_idx] != p[p_idx])
				return false;

			return is_match(s, s_idx + 1, p, p_idx + 1);
		}

};

int main(int argc, char **argv)
{
	solution a;

	cout << "is matching " << a.is_match("this is a testing question", "*") << endl;
	cout << "is matching " << a.is_match("this is a testing question", "?") << endl;
	cout << "is matching " << a.is_match("this is a testing question", "?*") << endl;
	cout << "is matching " << a.is_match("this is a testing question", "?*s") << endl;
	cout << "is matching " << a.is_match("this is a testing question", "*q?t") << endl;
	cout << "is matching " << a.is_match("this is a testing question", "*q?e") << endl;
}

