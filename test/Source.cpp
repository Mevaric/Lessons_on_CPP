#include <iostream>
int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if ((a + 1 == c || a - 1 == c || a == c) && (b == d || b + 1 == d || b - 1 == d) == 1)
		std::cout << "YES";
	else 
		std::cout << "NO";
	return 0;
}