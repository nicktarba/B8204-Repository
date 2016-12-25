#ifndef __CCLASS_H__
#define __CCLASS_H__

class queue
{
private:
	struct queue_object
	{
		int value;
		queue_object *address;
	};

	queue_object *head; //голова
	queue_object *tail; //хвост
	int size;

public:
	queue(int x) //создание единичной очереди
	{
		head=new(queue_object);
		tail=head;
		head->value=x;
		head->address=0; //следующего элемента пока нет
		//Так как head - указатель, на некий объект
		//то использую -> для указания на поле объекта.
		size=1;
	}

	int queue_size()
	{
		return size;
	}

	void push(int elem) //добавление
	{
		size++;
		queue_object *newElem=new(queue_object); //новый элемент очереди
		newElem->address=NULL; //новый элемент ни на что не ссылается
		newElem->value=elem;
		tail->address=newElem; //хвост ссылаю на адрес нового элемента
		tail=newElem; //теперь хвост -новый элемент
	}

	void pop(int *delAdress)
	{
		if(size == 0)
		{
			cout<<"Epmty queue! I can't delete!"<<endl;
		}
		else 
		{
			queue_object *newElem=head;
			*delAdress=head->value;
			head=head->address;
			delete newElem;
			size--;	
		}

	}

	void print() //печать очереди на экран
	{
		queue_object *newElem=new(queue_object);
		newElem=head;
		int i=0;
		do {
			cout<<newElem->value<<"  ";
			newElem=newElem->address;
			i++;
		} while (i<size);
		cout<<"\n"<<endl;
	}

};

#endif // __CCLASS_H__