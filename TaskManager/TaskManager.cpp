// TaskManager.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "pch.h"
#include <iostream>
#include "DateTime.h"

int main()
{
	DateTime dt(100);
	DateTime dt2(10);

	std::cout << (dt == dt2);
}
