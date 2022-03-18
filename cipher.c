#include "cipher.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.

#define AB_COUNT 26
#define CAP_A 65
#define CAP_Z 90
#define LIT_A 97
#define LIT_Z 122


/**
 * Calculate the modulo of 26
 * @param x - number to do the modulo
 * @return x%26
 * */
int mod26(int x)
{
    return x>=0? x%AB_COUNT : (AB_COUNT+x%AB_COUNT)%AB_COUNT;
}

// See full documentation in header file
void encode (char *s, int k)
{
  for(int i=0;i<strlen(s);i++){
      if(LIT_A<=s[i] && s[i]<=LIT_Z){
          s[i] = mod26(s[i]-LIT_A+k)+LIT_A;;
      }
      if(CAP_A<=s[i] && s[i]<=CAP_Z){
          s[i] = mod26(s[i]-CAP_A+k)+CAP_A;
      }
  }
}

// See full documentation in header file
void decode (char *s, int k)
{
    for(int i=0;i<strlen(s);i++){
        if(LIT_A<=s[i] && s[i]<=LIT_Z){
            s[i] = mod26(s[i]-LIT_A-k)+LIT_A;
        }
        if(CAP_A<=s[i] && s[i]<=CAP_Z){
            s[i] = mod26(s[i]-CAP_A-k)+CAP_A;
        }
    }
}
