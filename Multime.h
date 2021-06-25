#pragma once
#include <vector>
using std::vector;

#define NULL_TELEM -9999999
typedef int TElem;

class IteratorMultime;

class Multime {
	friend class IteratorMultime;

    private:
		int cp;
		int n;
		TElem* e;
		int* urm;
		int primLiber;

		void act_primLiber();
		TElem hashCode(TElem e);
		TElem d(TElem e);
		void redim();

    public:
 		//constructorul implicit
		Multime();
		Multime(int cap);

		//adauga un element in multime
		//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
		bool adauga(TElem e);

		//sterge un element din multime
		//returneaza adevarat daca elementul a existat si a fost sters
		bool sterge(TElem e);

		//verifica daca un element se afla in multime
		bool cauta(TElem e) const;


		//intoarce numarul de elemente din multime;
		int dim() const;

		//verifica daca multimea e vida;
		bool vida() const;

		//returneaza un iterator pe multime
		IteratorMultime iterator() const;

		TElem dif();

		// destructorul multimii
		~Multime();
};




