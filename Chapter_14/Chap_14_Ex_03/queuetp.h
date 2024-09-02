// queuetp.h
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename T>
class QueueTp
{
private:
	// definice s platnosti uvnitr tridy
	// Node definice vnorene struktury existujici pouze uvnitr tridy
	struct Node { T item; struct Node* next; };
	enum { Q_SIZE = 10 };

	// privatni clenove tridy
	Node* front;		// ukazatel na zacatek fronty
	Node* rear;		// ukazatel na konce fronty
	int items;		// aktualni pocet polozek fronty

	const int qsize;		// maximalni pocet polozek fronty

	// preventivni definice nutne pro zamezeni verejneho kopirovani
	QueueTp(const QueueTp<T>& q) : qsize(0) {}
	QueueTp<T>& operator=(const QueueTp<T>& q) { return *this; }

public:
	QueueTp(int qs = Q_SIZE);		// vytvori frontu 
	~QueueTp();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const T& item);		// prida polozku na konec
	bool dequeue(T& item);		// odebere polozku ze zacatku
};


template <typename T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

template <typename T>
QueueTp<T>::~QueueTp()
{
	Node* temp;
	while (front != NULL)	// dokud fronta neni prazdna
	{
		temp = front;		// ulozi adresu prvni polozky
		front = front->next;	// nastavi ukazatel na dalsi polozku 
		delete temp;		// zrusi puvodni prvni polozku
	}
}

template <typename T>
bool QueueTp<T>::isempty() const
{
	return items == 0;
}

template <typename T>
bool QueueTp<T>::isfull() const
{
	return items == qsize;
}

template <typename T>
int QueueTp<T>::queuecount() const
{
	return items;
}

// Add item to queue
template <typename T>
bool QueueTp<T>::enqueue(const T& item)
{
	if (isfull())
		return false;
	Node* add = new Node;	// vytvori polozku
	if (add == NULL)
		return false;		// navrat pri chybe
	add->item = item;		// nastavi ukazatele polozky
	add->next = NULL;
	items++;
	if (front == NULL) 		// pokud je fronta prazdna
		front = add;		// umisti polozku na zacatek
	else
		rear->next = add;	// jinak na konec
	rear = add;
	return true;
}

// Umisti prvni polozku do promenne item a odebere z fronty
template <typename T>
bool QueueTp<T>::dequeue(T& item)
{
	if (front == NULL)
		return false;
	item = front->item;	// nastavi ukazatel na prvni polozku fronty
	items--;
	Node* temp = front;	// ulozi adresu prvni polozky
	front = front->next;	// nastavi ukazatel front na dalsi polozku 
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}

#endif
