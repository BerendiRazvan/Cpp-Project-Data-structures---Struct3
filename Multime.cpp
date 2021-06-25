#include "Multime.h"
#include "IteratorMultime.h"
#include <iostream>
#include <cmath>

using std::cout;
#define NMAX 10

//Complexitate: O(cp)
void Multime::act_primLiber() {
	primLiber++;
	while (primLiber < cp && e[primLiber] != NULL_TELEM) {
		primLiber++;
	}
}

//Complexitate: 0(1)
TElem Multime::hashCode(TElem e) {
	return abs(e);
}

//Complexitate: 0(1)
TElem Multime::d(TElem e) {
	return hashCode(e) % cp;
}

//Complexitate: 0(cp)
Multime::Multime(int cap) {
	cp = cap;
	n = 0;
	e = new TElem[cap];
	urm = new int[cap];
	for (int i = 0; i < cap; i++) {
		e[i] = NULL_TELEM;
		urm[i] = -1;
	}
	primLiber = 0;
}

//Complexitate: 0(NMAX)
Multime::Multime() {
	cp = NMAX;
	n = 0;
	e = new TElem[NMAX];
	urm = new int[NMAX];
	for (int i = 0; i < NMAX; i++) {
		e[i] = NULL_TELEM;
		urm[i] = -1;
	}
	primLiber = 0;
}

//Complexitate: 0(cp)
void Multime::redim() {
	Multime m2(cp*2);
	int i;
	for (i = 0; i < cp; i++) {
		if (e[i] != NULL_TELEM) {
			m2.adauga(e[i]);
		}
	}

	delete[] e, urm;

	cp = cp * 2;
	e = m2.e;
	urm = m2.urm;
	e = new TElem[cp];
	urm = new int[cp];
	for (i = 0; i < cp; i++) {
		auto v = m2.urm[i];
		e[i] = m2.e[i];
		urm[i] = v;
	}
	primLiber = -1;

	act_primLiber();
}

//Complexitate: O(n)
bool Multime::adauga(TElem elem) {
	if (primLiber >= cp) {
		redim();
	}
	int i = d(elem), j;
	if (e[i] == NULL_TELEM) {
		e[i] = elem;
		if (primLiber == i) {
			act_primLiber();
		}
	}
	else {
		while (i != -1 && e[i] != elem) {
			j = i;
			i = urm[i];
		}
		if (i != -1) {
			return false;
		}
		urm[j] = primLiber;
		e[primLiber] = elem;
		act_primLiber();
	}
	n++;
	return true;
}

//Complexitate: O(n)
bool Multime::sterge(TElem elem) {
	int i, j, prec_j, prec_i=-1;
	for (i = d(elem); i != -1; prec_i = i, i = urm[i]) {
		if (e[i] == elem) {
			break;
		}
	}
	if (i == -1) {
		return false;
	}
	while (1) {
		for (j = urm[i], prec_j = i; j != -1 && d(e[j]) != i; prec_j = j, j = urm[j]);
		if (j != -1) {
			e[i] = e[j];
			i = j;
			prec_i = prec_j;
			continue;
		}
		if (prec_i != -1) {
			urm[prec_i] = urm[i];
		}
		e[i] = NULL_TELEM;
		urm[i] = -1;
		n--;
		return true;
	}
}

//Complexitate: O(n)
bool Multime::cauta(TElem elem) const {
	int i;
	for (i = 0; i < cp; i++) {
		if (e[i] == elem) {
			return true;
		}
	}
	return false;
}

//Complexitate: 0(1)
int Multime::dim() const {
	return n;
}

//Complexitate: 0(1)
bool Multime::vida() const {
	return n == 0;
}

//Complexitate: 0(1)
Multime::~Multime() {
	delete[] e, urm;
}

//Complexitate: 0(1)
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


/*
Complexitati: 0(cp)

Pre: m-multime
Post: v-TElem, valoarea diferentei dintre cel mai mare si cel mai mic element, sau 2^31 daca lista e vida

Subalgoritm dif(m,v):
	MAX <- -9999999
	MIN <- 9999999
	Pentru i=0,cp-1 executa
		Daca e[i] != NULL_TELEM si e[i] > MAX atunci
			MAX <- e[i]
		sfDaca
		Daca e[i] != NULL_TELEM si e[i] < MIN atunci
			MIN <- e[i]
		sfDaca
	sfPentru
	diff <- MAX - MIN
sfSubalgoritm

*/
TElem Multime::dif() {
	int i, MAX = -9999999, MIN = 9999999;
	for (i = 0; i < cp; i++) {
		if (e[i] != NULL_TELEM && e[i] > MAX) {
			MAX = e[i];
		}
		if (e[i] != NULL_TELEM && e[i] < MIN) {
			MIN = e[i];
		}
	}
	if (MIN == 9999999) {
		return 9999999;
	}
	return MAX - MIN;
}

