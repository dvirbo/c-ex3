#include <stdio.h>
#include <string.h>

#define TXT 1024
#define WORD 30

int geometVal(char c)
{ // convert to Gematria value
    if (c == 'A' || c == 'a')
    {
        return 1;
    }
    else if (c == 'B' || c == 'b')
    {
        return 2;
    }
    else if (c == 'C' || c == 'c')
    {
        return 3;
    }
    else if (c == 'D' || c == 'd')
    {
        return 4;
    }
    else if (c == 'E' || c == 'e')
    {
        return 5;
    }
    else if (c == 'F' || c == 'f')
    {
        return 6;
    }
    else if (c == 'G' || c == 'g')
    {
        return 7;
    }
    else if (c == 'H' || c == 'h')
    {
        return 8;
    }
    else if (c == 'I' || c == 'i')
    {
        return 9;
    }
    else if (c == 'J' || c == 'j')
    {
        return 10;
    }
    else if (c == 'K' || c == 'k')
    {
        return 11;
    }
    else if (c == 'L' || c == 'l')
    {
        return 12;
    }
    else if (c == 'M' || c == 'm')
    {
        return 13;
    }
    else if (c == 'N' || c == 'n')
    {
        return 14;
    }
    else if (c == 'O' || c == 'o')
    {
        return 15;
    }
    else if (c == 'P' || c == 'p')
    {
        return 16;
    }
    else if (c == 'Q' || c == 'q')
    {
        return 17;
    }
    else if (c == 'R' || c == 'r')
    {
        return 18;
    }
    else if (c == 'S' || c == 's')
    {
        return 19;
    }
    else if (c == 'T' || c == 't')
    {
        return 20;
    }
    else if (c == 'U' || c == 'u')
    {
        return 21;
    }
    else if (c == 'V' || c == 'v')
    {
        return 22;
    }
    else if (c == 'W' || c == 'w')
    {
        return 23;
    }
    else if (c == 'X' || c == 'x')
    {
        return 24;
    }
    else if (c == 'Y' || c == 'y')
    {
        return 25;
    }
    else if (c == 'Z' || c == 'z')
    {
        return 26;
    }
    else
    {
        return 0;
    }
}

void Gematria(char word[], char text[])
{
    printf("Gematria Sequences: ");
    int tilda = 0; // when to print ~
    int geomWord = 0;
    int i = 0;
    char c = word[i];
    while (c != '\0')
    {
        c = word[i];
        geomWord = geomWord + geometVal(c);
        i++;
    }
    // int le1nText = strlen(text);
    for (int i = 0; i < TXT; i++)
    {

        if (text[i] == '\0')
        {
            return;
        }
        if (geometVal(text[i]) == 0)
        {
            continue;
        }
        int check = geomWord - geometVal(text[i]);
        if (check == 0) // if the curr letter in the text have the save geomtry val like the word
        {
            if (tilda)
            {
                printf("~");
            }
            printf("%c", text[i]);
            tilda = 1;
            continue;
        }
        else
        {
            int next = i + 1;
            while (check >= 0) // while there is more letters to add until we get the val of the word
            {
                if (text[next] == '\0')
                {
                    break;
                }
                if (check - geometVal(text[next]) < 0)
                {
                    break;
                }
                else if (check - geometVal(text[next]) == 0)
                {
                    if (tilda)
                    {
                        printf("~");
                    }

                    int len = next - i + 1; // length of the substring
                    char substring[TXT];
                    int j = 0;
                    while (j < len)
                    {
                        substring[j] = text[i + j];
                        j++;
                    }
                    substring[j] = '\0';
                    printf("%s", substring);
                    tilda = 1;
                    break;
                }
                else
                {
                    check = check - geometVal(text[next]);
                    next++;
                }
            }
        }
    }
}

char trans(char c) // transfer to atbash
{
    if (c >= 'a' && c <= 'z')
    { // little letter
        int a = c - 'a';
        int b = 'z' - a;
        c = b;
        return c;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        int a = c - 'A';
        int b = 'Z' - a;
        c = b;
        return c;
    }
    else
        return c;
}

void toReverse(char reverse[], int wordLen) // reverse the word
{
    int i = 0, k = 0;
    char tmp[wordLen];
    while (i < wordLen)
    {
        tmp[i] = reverse[i];
        i++;
    }

    i = wordLen - 1;
    while (i >= 0)
    {
        reverse[k] = tmp[i];
        i--;
        k++;
    }
    reverse[wordLen] = '\0';
}

void toAtbash(char atbashWord[], int wordLen) // change the string to atbash
{
    char c;
    for (int i = 0; i < wordLen; ++i)
    {
        c = atbashWord[i];
        c = trans(c);
        atbashWord[i] = c;
    }
}

void Atbash(char word[], char text[])
{
    printf("Atbash Sequences: ");
    int tilda = 0; // when to print ~
    int wordLen = strlen(word);
    int textLen = strlen(text);
    // atbashWord
    char atbashWord[WORD];
    strcpy(atbashWord, word);
    toAtbash(atbashWord, wordLen);

    char reverse[wordLen];
    strcpy(reverse, atbashWord);
    toReverse(reverse, wordLen);

    char temp;
    int subPtr;
    int j;
    int n;

    for (int i = 0; i < textLen; i++)
    {
        char ptrText = text[i];
        if (ptrText == atbashWord[0])
        {
            char sub[wordLen];
            sub[0] = atbashWord[0];

            for (j = 1, subPtr = 1, n = 1; j <= textLen; j++, n++)
            {
                if (j == wordLen)
                {
                    sub[subPtr] = '\0';
                    if (tilda)
                    {
                        printf("~");
                    }
                    printf("%s", sub);
                    tilda = 1;
                    break;
                }
                temp = text[i + n];
                if (geometVal(temp) == 0)
                { // check if the char not include in the abc..
                    sub[subPtr] = temp;
                    subPtr++;
                    n++;
                    j--;
                    continue;
                }
                else if (temp == atbashWord[j])
                {
                    sub[subPtr] = temp;
                    subPtr++;
                }
                else
                {
                    break;
                }
            }
        }
        else if (ptrText == reverse[0])
        {
            char sub[wordLen];
            sub[0] = reverse[0];
            j = 1, subPtr = 1, n = 1;
            while (j <= wordLen)
            {
                if (j == wordLen)
                {
                    sub[subPtr] = '\0';
                    if (tilda)
                    {
                        printf("~");
                    }
                    printf("%s", sub);
                    tilda = 1;
                    break;
                } //*
                temp = text[i + n];
                if (geometVal(temp) == 0) // if the next val isn't word- add
                {
                    sub[subPtr] = temp;
                    subPtr++;
                    n++;
                    continue;
                }
                else if (temp == reverse[j])
                {
                    sub[subPtr] = temp;
                    subPtr++;
                    n++;
                    j++;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

// check the appearance  of the chars
int checkAn(char currString[], char word[])
{
    int appearance[127];
    memset(appearance, 0, sizeof(appearance));
    int loc;
    for (int i = 0; currString[i] != '\0'; i++)
    {
        if (currString[i] != ' ')
        {
            loc = (int)*(currString + i);
            appearance[loc]++;
        }
        if (word[i] != ' ' && strlen(word) > i)
        {
            loc = (int)*(word + i);
            appearance[loc]--;
        }
    }
    for (int i = 0; i < 127; i++)
    {
        if (appearance[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void Anagram(char word[], char text[])
{
    printf("Anagram Sequences: ");
    int textlen = strlen(text);
    char copy[textlen];
    strcpy(copy, text);

    int tilda = 0;
    for (int i = 0; i < textlen; i++)
    {
        int pSub = 0; //curr of the substring
        char sub[textlen];
        memset(sub, 0, textlen);

        for (int j = 0; j < strlen(copy); j++)
        {
            if (copy[0] != ' ')
            {
                char c = copy[j];
                sub[pSub] = c;
                pSub++;
                if (checkAn(word, sub))
                {
                    if (tilda)
                        printf("~%s", sub);
                    else
                    {
                        tilda = 1;
                        printf("%s", sub);
                    }
                    break;
                }
            }
        }//      dest     src
        memmove(&copy[0], &copy[1], strlen(copy));
    }
}