#include <iostream>
#include <conio.h>

using namespace std;

void main() {
	while (1) {	if (_kbhit()) { break; } }
	cout << "Kept you waiting, huh?";
}