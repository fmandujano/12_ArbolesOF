#pragma once
template<class datatype>
class ListaLigada
{
public:
	template<class datatype>
	class Item
	{
	public:
		Item<datatype> * next;
		datatype *data;
		Item(datatype *d)
		{
			//printf("Item ctor: \n");
			data = d;
			next = NULL;
		}
	};

	Item<datatype> *start;
	Item<datatype> *last;
	Item<datatype> *header;

	void Insert(datatype *elem)
 	{
		if(!start)
		{
			start = new Item<datatype>(elem);
			last = start;
		}
		else
		{
			last->next = new Item<datatype>(elem);
			last = last->next;
		}
	}

	datatype * RemoveLast()
	{
		if (!last || !start) return NULL;

		Item<datatype> *tmp = last;
		Item<datatype> *iter = start;

		//remover el unico item
		if (last == start)
		{
			last = NULL;
			start = NULL;
			return tmp->data;
		}


		while (iter->next != last)
		{
			iter = iter->next;
		}
		//el penultimo es iter
		last = iter;
		last->next = NULL;
		return tmp->data;
	}

	bool IsEmpty()
	{
		return last == NULL & start == NULL;
	}

	void Begin()
	{
		header = start;
		//return header->data;
	}
	Item<datatype> * Next()
	{
		header = header->next;
		if (header)
			return header;
		else
			return NULL;
	}
	void End()
	{
		header = last;
		//return header->data;
	}

	int Count()
	{
		return 0;
	}

	ListaLigada()
	{
		start = NULL;
		header = NULL;
		last = NULL;
	}
	~ListaLigada()
	{}
};

