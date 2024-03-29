#include "cipher.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// your code goes here
#define READ_AT_A_TIME 3
#define CHAR0 48
#define CHAR9 59

void encode_decode(char command[],FILE* in_file,FILE* out_file,int k);

int test_passed();

int valid_shift_value(char *str);

int main (int argc, char*argv[])
{
    switch (argc)
      {
        case 2:
          if (strcmp (argv[1], "test") == 0)
            {
              if (test_passed () != 0)
                {
                  return EXIT_FAILURE;
                }
              else
                {
                  return EXIT_SUCCESS;
                }
            }
          else
            {
              fprintf (stderr, "Usage: cipher test\n");
              return EXIT_FAILURE;
            }
        case 5:
          if (strcmp (argv[1], "encode") != 0 && strcmp (argv[1], "decode") != 0)
            {
              fprintf (stderr, "The given command is invalid.\n");
              return EXIT_FAILURE;
            }
        if (valid_shift_value (argv[2]) == 0)
          {
            fprintf (stderr, "The given shift value is invalid.\n");
            return EXIT_FAILURE;
          }
        char *ptr;
        int k = strtol (argv[2], &ptr, 10);
        FILE *in_file;
        in_file = fopen (argv[3], "r");
        if (in_file == NULL)
          {
            fprintf (stderr, "The given file is invalid.\n");
            return EXIT_FAILURE;
          }
        FILE *out_file;
        out_file = fopen (argv[4], "w");
        if (out_file == NULL)
          {
            fprintf (stderr, "The given file is invalid.\n");
            fclose (in_file);
            return EXIT_FAILURE;
          }
        encode_decode (argv[1], in_file, out_file, k);
        fclose (in_file);
        fclose (out_file);

        break;
        default:
          fprintf (stderr, "The program receives 1 or 4 arguments only.\n");
        return EXIT_FAILURE;
      }
    return EXIT_SUCCESS;
}

void encode_decode(char *command,FILE* in_file,FILE* out_file,int k)
{
    char str[READ_AT_A_TIME+1];
    while (fgets(str,READ_AT_A_TIME+1,in_file))
      {
        if (strcmp (command, "encode") == 0)
          {
            encode (str, k);
          }
        else
          {
            decode (str, k);
          }
        fprintf (out_file, "%s", str);
      }
}

int test_passed()
{
    if (test_encode_non_cyclic_lower_case_positive_k() != 0)
      {
        return 1;
      }
    if (test_encode_cyclic_lower_case_special_char_positive_k() != 0)
      {
        return 1;
      }
    if (test_encode_cyclic_upper_case_positive_k() != 0)
      {
        return 1;
      }
    if (test_encode_non_cyclic_lower_case_positive_k() != 0)
      {
        return 1;
      }
    if (test_encode_non_cyclic_lower_case_special_char_negative_k() != 0)
      {
        return 1;
      }
    if (test_decode_non_cyclic_lower_case_positive_k() != 0)
      {
        return 1;
      }
    if (test_decode_cyclic_lower_case_special_char_positive_k() != 0)
      {
        return 1;
      }
    if (test_decode_cyclic_upper_case_positive_k() != 0)
      {
        return 1;
      }
    if (test_decode_non_cyclic_lower_case_positive_k() != 0)
      {
        return 1;
      }
    if (test_decode_non_cyclic_lower_case_special_char_negative_k() != 0)
      {
        return 1;
      }
    return 0;
}

int valid_shift_value(char *str)
{
  for (size_t i = 0; i < strlen (str); i++)
    {
      if ((str[i] > CHAR9 || str[i] < CHAR0) && str[i]!= '-')
        {
          return 0;
        }
    }
  return 1;
}
