#pragma once
#include "ListaLigada.h"
template<class datatype>
class Pila :
	public ListaLigada<datatype>
{
public:

	Pila()
	{	
	}

	~Pila()
	{
	}

	void push(datatype * data)
	{
		Insert(data);
	}

	datatype * pop()
	{
		return RemoveLast();
	}
};

