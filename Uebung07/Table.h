#pragma once

#include <stdexcept>

using namespace std;

template <class item_type>
class Table {
	struct record {
		item_type item;
		record* next;
		record* prev;
	};

public:
	Table() { // kreiert leere Tabelle
		tail = nullptr;
		head = nullptr;
		iterator = nullptr;
	}
	~Table() { // gibt von der Tabelle belegten Speicherbereich frei
		while (iterator != nullptr) {
			delete_record();
		}
	}
	
	void insert(item_type r) { // fügt neuen Record vor dem aktuellen Record ein
		record* temp = iterator;
		record* rec = new record;
		
		if (iterator == nullptr) {			//no record exists
			rec->next = nullptr;
			tail = rec;
			rec->prev = nullptr;
			head = rec;
		}
		else if (temp->next != nullptr) {	//next record exists
			temp->next->prev = rec;
			rec->next = temp->next;
		}
		else if (temp->next = nullptr) {	//next record doesn't exist
			temp->next = rec;
			rec->prev = temp;
		}
		
		rec->item = r;
		iterator = rec;
	}
	void append(item_type r) { // fügt neuen Record am Ende der Liste ein
		record* temp = tail;
		record* rec = new record;

		temp->next = rec;
		rec->prev = temp;
		rec->next = nullptr;
		tail = rec;

		rec->item = r;
		iterator = rec;
	}
	void first() { // erster Record wird zum aktuellen Record
		if (iterator == nullptr) {
			throw out_of_range("empty stack");
		}
		iterator = head;
	}
	void last() { // letzter Record wird zum aktuellen Record
		if (iterator == nullptr) {
			throw out_of_range("empty stack");
		}
		iterator = tail;
	}
	void next() { // der dem aktuellen Record folgende Record wird zum neuen aktuellen Record
		if (iterator->next == nullptr) {
			throw out_of_range("no next item available");
		}
		iterator = iterator->next;
	}
	void previous() { // der dem aktuellen Record vorausgehende Record wird zum neuen aktuellen Record
		if (iterator->prev == nullptr) {
			throw out_of_range("no previous item available");
		}
		iterator = iterator->prev;
	}
	void delete_record() { // löscht aktuellen Record
		record* rec = iterator;
		
		if (iterator == nullptr) {
			throw out_of_range("empty stack");
		}
		else if (iterator->next != nullptr && iterator->prev != nullptr) {	//both prev and next record exist
			iterator->next->prev = iterator->prev;
			iterator->prev->next = iterator->next;
			iterator = iterator->prev;
		}
		else if (iterator->next != nullptr && iterator->prev == nullptr) {	//next record exists, prev record doesn't exist
			iterator->next->prev = nullptr;
			iterator = iterator->next;
		}
		else if (iterator->next == nullptr && iterator->prev != nullptr) {	//next record doesn't exist, prev record exists
			iterator->prev->next = nullptr;
			iterator = iterator->prev;
		}
		else if (iterator->next == nullptr && iterator->prev == nullptr) {	//both prev and next record don't exist
			iterator = nullptr;
		}

		delete rec;
	}
	item_type get_record() { // liefert aktuellen Record in der Recordvariablen r
		return iterator->item;
	}
	void set_record(item_type& r) { // ersetzt aktuellen Record durch Recordvariable r	
		iterator->item = r;
	}


private:
	record* tail;
	record* head;
	record* iterator;
};
