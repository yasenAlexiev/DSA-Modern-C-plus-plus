#include <iostream>

		/* Въпроси за преговор */

// Има ли проблеми и какво ще изведе следната функция?
void func1()
{
	char*	text	= "FMI";
	char*	buffer	= new char[60];
	while ( *text )
	{
		*buffer = *text;
		++buffer;
		++text;
	}
	
	std::cout << buffer;
}


int main()
{
	func1();
	
	return 0;
}
