#include <iostream>
#include <string>
using namespace std;

bool IsSpaceBeforeSybols(const string str, const string pattern)
{
	size_t offset = 0;
	for (size_t i = 0; i < pattern.length(); i++)
	{
		size_t pos;
		if ((pos = str.find(pattern.at(i), offset)) == string::npos)
			continue;
		else
			if (pos != 0 && str.at(pos - 1) == ' ') {
				offset = 0;
				return true;
			}
			else
			{
				i--;
				offset = pos + 1;
			}
	}

	return false;
}

void RemoveSpaces(string& str, const string pattern)
{
	size_t offset = 0;
	while (IsSpaceBeforeSybols(str, pattern))
	{
		for (size_t i = 0; i < pattern.length(); i++)
		{
			size_t pos;
			if ((pos = str.find(pattern.at(i), offset)) == string::npos)
				continue;
			else
				if (pos != 0 && str.at(pos - 1) == ' ') {
					str = str.erase(pos - 1, 1);
					offset = 0;

					if (IsSpaceBeforeSybols(str, { pattern.at(i) }))
					{
						i--;
						continue;
					}
				}
				else {
					offset = pos + 1;
					i--;
				}
		}
	}
}

int main()
{
	cout << "wrire text = ";
	string str;
	getline(cin, str);

	string signs = "!\"\'#%()[]{}.,-:;?";

	RemoveSpaces(str, signs);
	cout << str << endl;

	return 0;
}