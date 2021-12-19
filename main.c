#include <stdio.h>
#include <string.h>
#include "txtFind.h"
#define TXT 1024
#define WORD 30
/**
 * first we need to scan word < 30 until we see
 */
int main()
{

    char word[WORD];
    char text[TXT];

    char c;
    int i = 0;
    while (c != '\n' && c != ' ' && c != '\t' && i < 30)
    {
        scanf("%c", &c);
        word[i] = c;
        i++;
    }
    word[i-1] = '\0';

    i = 0;
    while (c != '~' && i < 1024)
    {
        scanf("%c", &c);
        text[i] = c;
        i++;
    }
    text[i-1] = '\0';

    
    Gematria(word, text);
    printf("\n");
    Atbash(word, text);
    printf("\n");
    Anagram(word, text);
    return 0;
}
