#include <string>
#include "Biblioteca.h"
#include "Roman.h"
#include "Revista.h"
#include <iostream>

using namespace std;


int main()
{
// +=
// ctor -> Biblioteca, Roman, Revista
// dtor -> Biblioteca - detine obiecte alocate dinamic
// iteratori
/// new, delete, new[], delete[] -> c++
/// malloc, (realloc, calloc,) free -> c
    Biblioteca b;
    (b += new Roman("DON QUIJOTE", "MIGUEL DE CERVANTES"))
        += new Revista("Journal of Artificial Intelligence", 100);

    b += new Roman("MACBETH", "WILLIAM SHAKESPEARE");
    for (auto x : b)
    {
        std::cout << x->GetInfo() << std::endl;
    }

//    for ( auto it = b.begin(); it != b.end(); ++ it ) {
//        auto x = * it; //// begin() -> Iterator, Iterator :: operator * () -> Carte *
//
//        std::cout << x->GetInfo() << std::endl;
//    }

    std::cout << "Numar de intrari in biblioteca: " << (int)b << std::endl;
    std::cout << "Lista doar cu romane:" << std::endl;

    b.PrintFilter( [] ( Carte * c ) ->bool {
        // adaugati codul care determina daca o carte este un Roman

        auto * pRoman = dynamic_cast < Roman * > ( c );
        if ( pRoman != nullptr ) {
            /// asta este roman
            return true;
        } else {
            /// asta nu este roman
            return false;
        }

        /// return dynamic_cast < Roman * > ( c ) != nullptr;
    });

    return 0;
}
