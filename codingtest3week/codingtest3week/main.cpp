#include <iostream>
#include <string>
#include <vector>

using namespace std;

//09 문자열 압축
int solution9(string s)
{
	int ana = 1000;
	int min;

	if (s.size() == 1) {
		return 1;
	}

	for (int i = 1; i <= s.size() / 2; i++) {
		string sub = "";                 //처음 문자열에서 일정 길이로 압출할 문자열 -> 숫자로 줄여질 문자열
		string compressStr = "";        //sub로 압축된 전체 문자열
		int com_count = 1;             //같은 문자열이 존재하면 증가시킬 카운트

		for (int j = 0; j <= s.size() * 2; j += i) {
			if (j >= s.size()) {
				if (com_count > 1) {
					compressStr += to_string(com_count) + sub;
				}
				else
					compressStr += sub;
				break;
			}

			if (sub != s.substr(j, i)) {
				if (com_count > 1) {
					compressStr += to_string(com_count) + sub;
					com_count = 1;
				}
				else
					compressStr += sub;

				sub = s.substr(j, i);
			}
			else
				++com_count;
		}

		min = compressStr.size();

		if (min < ana)
			ana = min;
	}

	return ana;
}


int main()
{
	int s = solution9("aabbaccc");
	printf("result = %d", s);

	return 0;
}