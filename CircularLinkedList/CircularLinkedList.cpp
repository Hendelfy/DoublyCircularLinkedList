#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Fractional.h"
#include "Complex.h"
#include "ListToolIO.h"
int main(int argc, char* argv[])
{
	if (argc < 3)
		return -1;
	auto list = new DoublyCircularLinkedList();
	ReadList(list, argv[1]);
	WriteList(list, argv[2]);
	list->Display();
	list->InsertionSort();
	list->Display();
	delete list;
	_CrtDumpMemoryLeaks();
}
