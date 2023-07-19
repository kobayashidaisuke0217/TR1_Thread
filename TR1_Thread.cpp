#include <stdio.h>
#include"Print.h"
int main() {
	Print* print = new Print();
	print->Initialize();
	while (true)
	{
		print->Update();
	}
	return 0;
}