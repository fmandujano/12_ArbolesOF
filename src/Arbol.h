#pragma once
#include <iostream>
#include "ListaLigada.h"
#include "Pila.h"
#define VERBOSIDAD 1

template<class datatype>
class Arbol
{
private:
	int nextIndex;
	int count;

public:
	typedef Arbol< datatype > Nodo;
	int index;
	datatype * data;
 	//padre es un arbol
	Nodo * padre;
	//jefe de jefes
	Nodo * raiz; 
	//hijos es una lista ligada de arboles
	ListaLigada<Nodo> *hijos;

	Arbol(datatype *_data , Nodo * _padre, int nextI)
	{
		count = 1;
		//si padre es null, este es un nodo raiz
		padre = _padre;
		data = _data;
		hijos = new ListaLigada<Nodo>();
		index = nextI;
		nextIndex = index + 1;
		raiz = getRaiz();
	}
	Arbol()
	{
		count = 0;
		puts("usando constructor default de Arbol");
	}
	~Arbol()
	{}

	Nodo * getRaiz()
	{
		if (padre != NULL)
		{
			//printf("Nodo %i tiene padre %i \n", *data, *(padre->data));
			return padre->getRaiz();
		}
		else
		{
			//printf("Nodo %i NO tiene padre, es el RAIZ \n", *data);
			return this;
		}
	}

	int getNextIndex()
	{
		int res = nextIndex;
		nextIndex++;
		return res;
	}

	Nodo * insertar(datatype *dato)
	{
		Nodo *nodo = new Arbol( dato, this, raiz->getNextIndex());
		hijos->Insert( nodo);
		//si este nodo tiene una raiz, aumentar el count de la raiz
		if (raiz != NULL)
		{
			raiz->count++;
		}
		else
		{
			count++;
		}
		//printf("Nodo insertado con indice %i y dato: %i \n", nodo->index, *(nodo->data) );
		return nodo;
	}

	bool CompararDato(Nodo *nodo, datatype dato)
	{
		//printf(" :: %i \n", *(nodo->data));
		return *(nodo->data) == dato;
	}

	void DFS()
	{
		Pila<Nodo> *pila = new Pila<Nodo>();
		int iNodoAnt;
		int *visitados = (int*)calloc(count+1, sizeof(int));
		int *padres = (int*)calloc(count+1,  sizeof(int));

		//iniciar busqueda desde la raiz
		pila->push( raiz);
		if (VERBOSIDAD >= 2)
		printf("Pila:%i \n", raiz->index);
		iNodoAnt = raiz->index;
		while (!pila->IsEmpty())
		{
			Nodo * temp = pila->pop();

			//anotar el padre
			padres[temp->index] = iNodoAnt;
			//marcar como visitado
			visitados[temp->index] = 1;

			if (VERBOSIDAD >= 2)
			{
				std::string str = *(temp->data);
				printf("Iterando en el nodo %i, valor: %s \n", temp->index, str.c_str());
				printf("\tPila: ");
				pila->Begin();
				while (pila->header != NULL)
				{
					printf(" %i, ", pila->header->data->index);
					pila->Next();
				}
				puts("");
			}

			//revisar si todos han sido visitados
			bool visitadostodos = true;
			for (int i = 0; i < count; i++)
			{
				if (visitados[i] == 0)
				{
					visitadostodos = false;
					break;
				}
			}

			if (visitadostodos)
			{
				puts("La busqueda ha terminado");
				return;
			}

			if (VERBOSIDAD >= 1)
			{
				std::string str = *(temp->data);
				printf("Nodo: %i, valor: %s \n", temp->index, str.c_str());
			}

			// apilar los nodos relacionados al actual
			//primero el padre de este
			if ( temp->padre != NULL && visitados[temp->padre->index] == 0)
			{
				if (VERBOSIDAD >= 2)
				printf("\tAgregando a la pila: %i\n", temp->padre->index);
				pila->push(temp->padre);
			}
			//luego los hijos
			temp->hijos->Begin();
			while (temp->hijos->header != NULL)
			{
				if (visitados[temp->hijos->header->data->index] == 0)
				{
					if (VERBOSIDAD >= 2)
					printf("\tAgregando a la pila: %i\n", temp->hijos->header->data->index);
					pila->push(temp->hijos->header->data);
				}
				else
				{
					if (VERBOSIDAD >= 2)
					printf("No se agrega a la pila: %i (visitado)\n", temp->hijos->header->data->index);
				}
				temp->hijos->Next();
			}
			if (VERBOSIDAD >= 2)
			{
				printf("\tEstado del arreglo visitados: \n\t");
				for (int i = 0; i < count; i++) printf("%i ", i);
				printf("\n\t");
				for (int i = 0; i < count; i++) printf("%i ", visitados[i]);
				printf("\n");
			}
		}
	}

	int Count()
	{
		if (raiz != NULL)
			return raiz->count;
		else
			return count;
	}
};

