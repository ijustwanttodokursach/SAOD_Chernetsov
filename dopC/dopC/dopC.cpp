#include <iostream>

using namespace std;

bool check(char* argv[], int count) {
	if (count < 3) {
		return false;
	}
	for (int i = 2; i < count; i++) {
		for (int j = 0; j < strlen(argv[i]); j++) {
			if (j == 0 && strlen(argv[i]) > 1) {
				if (argv[i][0] == '-') {
					continue;
				}
			}
			if (!isdigit(argv[i][j])) {
				return false;
			}
		}

	}
	return true;
}

int calc(char* argv[]) {
	if (strcmp(argv[1], "sub") == 0){
		return atoi(argv[2])-atoi(argv[3]);
	}
	if (strcmp(argv[1], "add") == 0) {
		return atoi(argv[2]) + atoi(argv[3]);
	}
	if (strcmp(argv[1], "div") == 0) {
		return atoi(argv[2]) / atoi(argv[3]);
	}
	if (strcmp(argv[1], "mul") == 0) {
		return atoi(argv[2]) * atoi(argv[3]);
	}
	else cout << "no such operation" << endl;
	return 0;
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << endl;
	if (check(argv, argc)) {
		cout << calc(argv);
	}
	else {
		cout << "incorrect data";
	}

}
