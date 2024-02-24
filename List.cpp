#include <iostream>
#include <cstdlib>
#include "List.h"
#include <iomanip>
using namespace std;
int main()
  {
  	List a,b;  int endit;

	for (int i=0;i<=20;i++)
	   a.insertAfter(i*2);
	cout << "List a : " << endl;
    	cout << "  "  << a.getElement() << endl;
	cout << "Number of elements in a - " << a.size() << endl;

	for (int i=1;i<=10;i++)
	   b.insertBefore(i*3);
	cout << "List b : " << endl;
    	cout << "  "  <<  b.getElement() << endl;
	cout << "Number of elements in b - " << b.size() << endl;

	if ( a == b )
	    cout << "List a & b are equal" << endl;
	  else
	    cout << "List a & b are Not equal" << endl;

	a.first();
	b.first();
	cout << "First elmenet in list a & b: " << a.getElement() << ", "
				       << b.getElement() << endl;
	a.last();
	b.last();
	cout << "Last elemenet in list a & b: " << a.getElement() << ", "
				     << b.getElement() << endl;

	cout << endl << endl << " Start of new stuff" << endl;

	b.erase();
	cout << "Empty List b:  " << b.listEmpty() << endl;
    cout<< "0 for empty, 1 for at least one item";
	if ( a == b )
	    cout << "List a & b are equal" << endl;
	  else
	    cout << "List a & b are Not equal" << endl;

	for (int i=1;i<=10;i++)
	   b.insertBefore(i*5);
	cout << "List b : " << endl;

	a.setPos(5);
	b.first();
	for ( int i=1; i<4; i++)
	{
	   a.erase();
	   b.replace(i);
	   b.next();
	}

	cout << "Modified Object 'a' (shorter) " << endl;
    	cout << "List a: " << a.size() << endl;
	cout << "Modified Object 'b' " << endl;
    	cout << "List b: " << b.size() << endl;

	List c(b);
	cout << "Copy Constructor c(b)" << endl;
    	cout << "List b : " << b.size() << endl;
    	cout << "List c : " << c.size() << endl;

	if ( c == b )
	    cout << "List c & b are equal" << endl;
	  else
	    cout << "List c & b are Not equal" << endl;


	List e;
	e = c;
	cout << "Object 'c' assigned to Object 'e':" << endl;
    	cout << "List c : " << c << endl;
    	cout << "List e : " << e << endl;

    	List d;
	d=a;

	d.first();
	endit = d.size();
	for ( int i = 1; i < endit; d.next(), i++)
	{
		d.insertBefore(d.getElement()*(-2));
		d.next();
	}
	cout << "Results after some Replaces on d " << endl;
    	cout << "List d : " << d << endl;

	a.first();
	endit = a.size();
	for ( int i = 1; i < endit; a.next(), i++)
	{
		a.replace(a.getPos()+a.getElement());
		a.next();
	}
	cout << "Results after some weird stuff on list a" << endl;
    	cout << "List a : " << a << endl;

    	List alist(b);
    	alist.clear();
    	for (int i=1;i<=10;i++)
	   alist.insertAfter(i);
	alist.first();
	cout << "New List alist with positions above: " << endl;
    	for (int i=1;i<=10;i++) {
		cout << setw(5) << alist.getPos();
		alist.next();
	}
	cout << endl;
	alist.first();
	for (int i=1;i<=10;i++) {
		cout << setw(5) << alist.getElement();
		alist.next();
	}
	cout << endl;

	cout << endl << "  check out boundary conditions" << endl;
	List sq;
	cout << "number of elements in empty sq list = " << sq.size() << endl;
	sq.first();
	sq.erase();
	sq.setPos(5);
	cout << "empty sq values " << sq << endl;
	sq.insertBefore(777);
	cout << "sq values " << sq << endl;
	sq.next(); sq.next();
	cout << "sq.getElement() = " << sq.getElement() << endl;
	cout << "sq list = " << sq << endl;
	return 0;
  }
