#include <iostream>
#include <sstream>
using namespace std;


char mayusculas_a_minusculas(char c){
    if(c >= 'A' && c <= 'Z') return tolower(c);
    else return c;
}

char caracteres_especiales_a_normales(char c){
    if(c==char(0xA1))	return 'a';
    else if (c==char(0xA9))	return 'e';
    else if (c==char(0xAD))	return 'i';
    else if (c==char(0xB3))	return 'o';
    else if (c==char(0xBA)) return 'u';
    else if (c==char(0x9A)) return 'u';
    else if (c==char(0xBC)) return 'u';
    else if (c==char(0x81)) return 'a';
    else if (c==char(0x89)) return 'e';
    else if (c==char(0x8D)) return 'i';
    else if (c==char(0x93)) return 'o';
    else if (c==char(0x9C)) return 'u';
    else return ' ';
}

string normalizar(string input){
	string output;
	for(unsigned int i = 0; i < input.length(); ++i){
		if(input[i] >= 'a' && input[i] <= 'z')	output += input[i];		
		else if(input[i] >= 'A' && input[i] <= 'Z')	output += mayusculas_a_minusculas(input[i]); 
		else if(input[i] == char(0xC3)){
            ++i;
            if(input[i] == char(0x91) || input[i] == char(0xB1)) output = output + char(0xC3) + char(0xB1); // concatenacion necesaria para la ñ
            else    output += caracteres_especiales_a_normales(input[i]);      
		}
		else output += ' ';
	}
	return output;
}