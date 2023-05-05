#pragma once

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

		if (temp->next != nullptr) {	//next record exists
			temp->next->prev = rec;
			rec->next = temp->next;
		}
		else {
			rec->next = nullptr;
			tail = rec;
		}
		if (iterator != nullptr) {		//prev record exists
			temp->next = rec;
			rec->prev = temp;
		}
		else {
			rec->prev = nullptr;
			head = rec;
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

		iterator = rec;
	}
	void first() { // erster Record wird zum aktuellen Record
		iterator = head;
	}
	void last() { // letzter Record wird zum aktuellen Record
		iterator = tail;
	}
	void next() { // der dem aktuellen Record folgende Record wird zum neuen aktuellen Record
		iterator = iterator->next;
	}
	void previous() { // der dem aktuellen Record vorausgehende Record wird zum neuen aktuellen Record
		iterator = iterator->prev;
	}
	void delete_record() { // löscht aktuellen Record
		
	}
	item_type get_record(item_type* r) { // liefert aktuellen Record in der Recordvariablen r
		r = iterator->item;
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
