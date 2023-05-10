#include "Table.h"
#include <iostream>

using namespace std;

int main() {
	
	Table<int> t1;
	
	try {
		t1.insert(4);
		t1.append(5);
		t1.append(6);
		cout << "Current record: " << t1.get_record() << endl;
		t1.delete_record();
		cout << "Current record: " << t1.get_record() << endl;
		t1.next();
	}
	catch (out_of_range& e) {
		cerr << "Exception thrown: " << e.what() << endl;
	}
	return 0;
}