
// 백준 1393 음하철도 구구팔

#include <iostream>
#include <cmath>
using namespace std;

int xs, ys, xe, ye;
double x, y, dx, dy;


int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {

	cin >> xs >> ys >> xe >> ye >> dx >> dy;

	int k = gcd(dx, dy);


	if (dx < 0)dx = -1 * abs(dx / k); else dx = abs(dx / k);
	if (dy < 0)dy = -1 * abs(dy / k); else dy = abs(dy / k);


	double mi = 10000;


	for (; (xe > -300 && xe < 300)&&(ye > -300 && ye <300); xe += dx, ye += dy) {

		if (mi > sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye))) {
			mi = sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye));
			x = xe; y = ye;
		}

	}

	cout << x << " " << y;
}
