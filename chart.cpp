#include <iostream>

using namespace std;

char toLowercase(char uppercase) {

	if ((uppercase <= 5A) && (uppercase >= 41)) {
			
		cout << "Not an uppercase letter" << end;

	}

	char lowercase = uppercase + 32;

}

int main() {

	cout << "Hello" << endl;

	char letter = 'a' + 1;

	letter = toLowercase('A');

	cout << letter << endl;

}
