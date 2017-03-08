//  implementation.cxx
//  Created by Isaac Mooney on 3/6/17.

#include <iostream>
#include "complex.h"

using namespace std;

const int g_size = 2;

int main() {
    cout << "Testing!" << '\n';
    double vec_a[g_size] = {0,0}; double vec_b[g_size] = {0,1};
    double vec_c[g_size] = {1,0}; double vec_d[g_size] = {-1,-3.1};
    double vec_e[g_size] = {4,19}; double vec_f[g_size] = {-12,33};
    
    //test variables
    complex *test_empty = new complex();
    complex *test_a = new complex(vec_a); complex *test_b = new complex(vec_b);
    complex *test_c = new complex(vec_c); complex *test_d = new complex(vec_d);
    complex *test_e = new complex(vec_e); complex *test_f = new complex(vec_f);
    
    //functions
        //Print:
        cout << "~~~testing print function~~~\n";
        cout << "empty = "; test_empty->Print();
        cout << "\na = "; test_a->Print(); cout << "\nb = "; test_b->Print();
        cout << "\nc = "; test_c->Print(); cout << "\nd = "; test_d->Print();
        cout << "\ne = "; test_e->Print(); cout << "\nf = "; test_f->Print();
    
        //Length:
        cout << "\n~~~testing length function~~~\n";
        cout << "empty: " << test_empty->Length() << '\n';
        cout << "a: " << test_a->Length() << '\n'; cout << "b: " << test_b->Length() << '\n';
        cout << "c: " << test_c->Length() << '\n'; cout << "d: " << test_d->Length() << '\n';
        cout << "e: " << test_e->Length() << '\n'; cout << "f: " << test_f->Length() << '\n';
    
    //operators
        //+:
        cout << "~~~testing + operator~~~\n";
        cout << "empty + a = "; (*test_empty + *test_a).Print(); cout << '\n';
        cout << "a + b = "; (*test_a + *test_b).Print(); cout << '\n';
        cout << "c + d = "; (*test_c + *test_d).Print(); cout << '\n';
        cout << "e + f = "; (*test_e + *test_f).Print(); cout << '\n';
    
        //-:
        cout << "~~~testing - operator~~~\n";
        cout << "empty - a = "; (*test_empty - *test_a).Print(); cout << '\n';
        cout << "a - b = "; (*test_a - *test_b).Print(); cout << '\n';
        cout << "c - d = "; (*test_c - *test_d).Print(); cout << '\n';
        cout << "e - f = "; (*test_e - *test_f).Print(); cout << '\n';
    
        //+=:
        cout << "~~~testing += operator~~~\n";
        *test_empty += *test_a; *test_a += *test_b; *test_c += *test_d; *test_e += *test_f;
        //should be {0, 0}
        cout << "empty += a: "; test_empty->Print(); cout << '\n';
        //should be {0, 1}
        cout << "a += b: "; test_a->Print(); cout << '\n';
        //should be {0, -3.1}
        cout << "c += d: "; test_c->Print(); cout << '\n';
        //should be {-8, 52}
        cout << "e += f: "; test_e->Print(); cout << '\n';
    
        //-=:
        cout << "~~~testing -= operator~~~\n";
        *test_empty -= *test_d; *test_a -= *test_b; *test_e -= *test_a; *test_c -= *test_f;
        //should be {1, 3.1}
        cout << "empty -= d: "; test_empty->Print(); cout << '\n';
        //should be {0, 0}
        cout << "a -= b: ";  test_a->Print(); cout << '\n';
        //should be {-8, 52}
        cout << "e -= a: "; test_e->Print(); cout << '\n';
        //should be {12, -36.1}
        cout << "c -= f: "; test_c->Print(); cout << '\n';
    
        //[]:
        cout << "~~~testing [] operator~~~\n";
        cout << "empty[0] = " << (*test_empty)[0] << '\n';
        cout << "a[0] = " << (*test_a)[0] << '\n';
        cout << "c[1] = " << (*test_c)[1] << '\n';
        cout << "e[1] = " << (*test_e)[1] << '\n';

    //deletes
    delete test_empty; test_empty = NULL;
    delete test_a; test_a = NULL; delete test_b; test_b = NULL;
    delete test_c; test_c = NULL; delete test_d; test_d = NULL;
    delete test_e; test_e = NULL; delete test_f; test_f = NULL;
    
    return 0;
}
