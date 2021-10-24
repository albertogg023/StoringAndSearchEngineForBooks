#include "Interprete.h"
#include "ColeccionLibros.h"


ColeccionLibros dic;


int main(void){
    char comando;
    while(cin >> comando){
        interprete(comando, dic);
    }  
}