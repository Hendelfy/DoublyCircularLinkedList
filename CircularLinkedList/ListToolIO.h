#pragma once
#include "DoublyCircularLinkedList.h"
#include "Number.h"
#include <fstream>

void ReadList(DoublyCircularLinkedList *list, char* file){
	if (list == nullptr)
		return;
	std::ifstream Input(file);
	if (!Input.is_open()) {
		std::cout << "File isn't opened!" << std::endl;
		return;
	}
	Input.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	int i = 0;
	int type;
	Number* number = nullptr;;
	while (Input)
	{
		try
		{
			number = nullptr;
			i++;
			Input >> type;
			Input.ignore(2, ' ');
			Input.ignore(12, ' ');
			switch (type)
			{
			case FRACTIONAL:
				number = new Fractional(new int(1), new int(1));
				break;
			case COMPLEX:
				number = new Complex(new int(1), new int(1));
				break;
			case COMPLEXINTFRACTIONAL:
				number = new Complex(new int(1), new Fractional(new int(1), new int(1)));
				break;
			case COMPLEXFRACTIONALINT:
				number = new Complex(new Fractional(new int(1), new int(1)), new int(1));
				break;
			case COMPLEXFRACTIONALFRACTIONAL:
				number = new Complex(new Fractional(new int(1), new int(1)), new Fractional(new int(1), new int(1)));
				break;
			case FRACTIONALINTCOMPLEX:
				number = new Fractional(new int(1), new Complex(new int(1), new int(1)));
				break;
			case FRACTIONALCOMPLEXINT:
				number = new Fractional(new Complex(new int(1), new int(1)), new int(1));
				break;
			case FRACTIONALCOMPLEXCOMPLEX:
				number = new Fractional(new Complex(new int(1), new int(1)), new Complex(new int(1), new int(1)));
				break;
			}
			if (number != nullptr) {
				Input >> *number;
				list->Insert(new Node(number));
			}
		}
		catch (const std::exception& ex)
		{
			if (!Input.eof()) {
				std::cout << "Error at line " << i << " " << ex.what() << std::endl;
				if (number)
					delete number;
				Input.clear();
				Input.ignore(64, '\n');
			}

		}
	}
	Input.close();

}
void WriteList(DoublyCircularLinkedList* list, char* file){
	if (list == nullptr)
		return;

	auto current = list->GetStart();
	if (current == nullptr)
		return;
	std::ofstream Output(file);
	
	do
	{
		Output << current->data->type << ": ";
		switch (current->data->type)
		{
		case COMPLEX:
			Output << "COMPLEX ";
			break;
		case FRACTIONAL:
			Output << "FRACTIONAL ";
			break;
		default:
			Output << "MIXED ";
			break;
		}
		Output << *current->data<<std::endl;
		current = current->next;
	} while (current!=list->GetStart());

}