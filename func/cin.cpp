#include<iostream>

int main(){
	using namespace std;

	int times;
	char ch;
	cout << "Enter a character: \n";
	cin >> ch;
	
	while (ch!='q'){
		cout << "Enter an integer:\n";
		cin >> times;
		cout << "press 'q' to exit\n";
		cin >> ch;
	}

	cout << "bye\n";
	return 0;
}
