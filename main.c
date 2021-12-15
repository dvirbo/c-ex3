#include <stdio.h>
#include <string.h>
#include "txtFind.h"
#define TXT 1024
#define WORD 30
/**
 * first we need to scan word < 30 until we see
 * @return
 */
int main(){

    char word[WORD];
    char text[TXT];

    char c = getchar();
    int i = 0;

    while (c != '\n' && c != ' ' && c != '\t' && c != EOF && i != 30) {
        word[i] = c;
        i++;
        c = getchar();
    }
    word[i] = '\0';

    c = getchar();
    i = 0;
    while ( c != '~' && i !=256){
       text[i] = c;
       i++;
       c = getchar();
    }
    text[i] = '\0';

    Gematria(word, text);
    Atbash(word, text);
    Anagram (word, text);


}

