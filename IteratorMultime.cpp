#include "IteratorMultime.h"
#include "Multime.h"

//Complexitate: O(cp)
void IteratorMultime::deplasare() {
	curent++;
	while (curent < multime.cp && multime.e[curent] == NULL_TELEM) {
		curent++;
	}
}

//Complexitate: O(cp)
IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	curent = -1;
	deplasare();
}

//Complexitate: O(cp)
void IteratorMultime::prim() {
	curent = -1;
	deplasare();
}

//Complexitate: O(cp)
void IteratorMultime::urmator() {
	deplasare();
}

//Complexitate: 0(1)
TElem IteratorMultime::element() const {
	return multime.e[curent];
}

//Complexitate: 0(1)
bool IteratorMultime::valid() const {
	return curent < multime.cp;
}
