#include<string.h>
#include<iostream>
using namespace std;

#define d 10

void rabinKarp(char pattern[], char text[], int q) {
    int i,j;
    int h1 = 0;
    int h2 = 0;
    int h = 1;
    int plen = strlen(pattern);
    int tlen = strlen(text);

    for(i = 0; i<plen-1; i++)
        h = (h * d) % q;

    for (i = 0; i < plen; i++) {
        h2 = (d * h2 + pattern[i]) % q;
        h1 = (d * h1 + text[i]) % q;
    }

    for(i = 0; i<=tlen - plen; i++)
    {
        if(h1 == h2)
        {
            for(j = 0; j<plen; j++)
            {
                if(text[i+j] != pattern[j]) break;
            }
        }

        if(j == plen) cout<<i<<endl;

        if(i<tlen - plen)
        {
            h1 = (d * (h1 - text[i]*h) + (text[i + plen]))%q;

            if(h1 < 0)
                h1 = h1 + q;
        }
    }
}

int main() {
  char text[] = "ABCCDDAEFGCDDDCD";
  char pattern[] = "CDD";
  int q = 1;
  rabinKarp(pattern, text, q);
}