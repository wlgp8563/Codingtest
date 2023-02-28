#include <iostream>
#include <string>
#include <vector>

using namespace std;

//09 ���ڿ� ����
int solution9(string s)
{
	int ana = 1000;
	int min;

	if (s.size() == 1) {
		return 1;
	}

	for (int i = 1; i <= s.size() / 2; i++) {
		string sub = "";                 //ó�� ���ڿ����� ���� ���̷� ������ ���ڿ� -> ���ڷ� �ٿ��� ���ڿ�
		string compressStr = "";        //sub�� ����� ��ü ���ڿ�
		int com_count = 1;             //���� ���ڿ��� �����ϸ� ������ų ī��Ʈ

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