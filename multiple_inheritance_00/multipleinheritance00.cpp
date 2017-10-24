// multipleinheritance00.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct Base {
	virtual void call() {};
};
struct D1 :Base {
	void call() {
		std::cout << "This D1" << std::endl;
	}
};
struct D2 :Base {
	void call() {
		std::cout << "This D2" << std::endl;
	}
};
struct D3 : D1, D2 {

};
Base * D1BaseToD2Base(Base const * base)
{
	return const_cast<Base*>(static_cast<const Base*>(static_cast<const D2*>(static_cast<const D3*>(static_cast<const D1*>(base)))));
}
int main()
{
	D1 * d3 = new D3();
	(D1BaseToD2Base(d3))->call();
	std::cin.get();
	return 0;
}

