#include "cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.

#define AB_COUNT 26

/**
 * Calculate the modulo of 26
 * @param x - number to do the modulo
 * @return x%26
 * */
int mod26(int x){
    return x>=0? x%AB_COUNT : (AB_COUNT+x%AB_COUNT)%AB_COUNT;
}

// See full documentation in header file
void encode (char s[], int k)
{
  for(int i=0;i<strlen(s);i++){
      if(97<=s[i] && s[i]<=122){
          s[i] = mod26(s[i]-97+k)+97;;
      }
      if(65<=s[i] && s[i]<=90){
          s[i] = mod26(s[i]-65+k)+65;
      }
  }
}

// See full documentation in header file
void decode (char s[], int k)
{
    for(int i=0;i<strlen(s);i++){
        if(97<=s[i] && s[i]<=122){
            s[i] = mod26(s[i]-97-k)+97;
        }
        if(65<=s[i] && s[i]<=90){
            s[i] = mod26(s[i]-65-k)+65;
        }
    }
}
