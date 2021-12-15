#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30


char upCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

void Gematria(char *word, char *text) {
    int lenWord = strlen(word);
    int geomWord = 0;
    for (int i = 0; i < lenWord; i++) {
        int tst = upCase(word[i]) - 'A' + 1;
        if (tst < 0 || tst > 27) { //not valid..
            continue;
        }
        geomWord += tst;
    }
    int counter = 0;
    int lenText = strlen(text);
    char sequence[lenText];
    int seqPtr = 0; //"pointer" on the seq
    memset(sequence, 0, lenText);
    for (int j = 0; j < lenText; j++) {
        int tst = upCase(text[j]) - 'A' + 1;
        if (tst < 0 || tst > 27) { //not valid or blankSpace
            sequence[seqPtr] = *(text + j); //add the char to the seq
            seqPtr += 1;
            continue;
        }
        counter += tst;
        if (counter == geomWord) { //if there is something in the string
            sequence[seqPtr] = *(text + j);
            sequence[seqPtr + 1] = '~';
            puts(sequence); //print the seq
            memset(sequence, 0, lenText); //reset
            seqPtr = 0;
            continue;
        }
        else if(geomWord<counter){
            sequence[seqPtr] = *(text + j);
            seqPtr += 1;
        } else{
            memset(sequence, 0, lenText); //reset
            seqPtr = 0;
            continue;
        }

    }

}

void Atbash(char *word, char *text) {


}

void Anagram(char *word, char *text) {


}







