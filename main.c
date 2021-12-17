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
    char word_temp[WORD];
    char text_temp[TXT];

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
    while ( c != '~' && i !=1024){
       text[i] = c;
       i++;
       c = getchar();
    }
    text[i] = '\0';



    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Gematria(word_temp, text_temp);
    printf("\n");
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Atbash(word_temp, text_temp);
    printf("\n");
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Anagram (word_temp, text_temp);

    return 0;
}

