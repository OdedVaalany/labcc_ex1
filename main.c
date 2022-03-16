#include "cipher.h"
#include "tests.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// your code goes here
#define read_at_a_time 1

int main (int argc, char*argv[])
{
    switch (argc) {
        case 2:
            if (strcmp(argv[1], "test") == 0)
                if (test_passed())
                    return EXIT_FAILURE;
                else
                    return EXIT_SUCCESS;
            else
                fprintf(stderr, "Usage: cipher test\n");
            break;
        case 5:
            if(strcmp(argv[1],"encode") != 0 & strcmp(argv[1],"decode") != 0){
                fprintf(stderr, "The given command is invalid.\n");
                return EXIT_SUCCESS;
            }
            if(strstr(argv[2],".")!=NULL){
                fprintf(stderr, "The given shift value is invalid\n");
                return EXIT_SUCCESS;
            }
            FILE* in_file;
            in_file = fopen("in.txt",'r');
            if(in_file == NULL){
                fclose(in_file);
                fprintf(stderr, "The given file is invalid.\n");
                return EXIT_FAILURE;
            }
            FILE*out_file;
            out_file = fopen("out.txt",'w');
            if(out_file == NULL){
                fprintf(stderr, "The given file is invalid.\n");
                fclose(out_file);
                return EXIT_FAILURE;
            }
            char read_str[read_at_a_time];
            while(fgets(read_str,read_at_a_time,in_file)){
                if(argv[1] == "encode")
                    encode(read_str,atoi(argv[2]));
                else
                    decode(read_str,atoi(argv[2]));
                fprintf(out_file,"%s",read_str);
            }
            fclose(in_file);
            fclose(out_file);

            break;
        default:
            fprintf(stderr, "The program receives 1 or 4 arguments only.\n");
            break;
    }
    return EXIT_SUCCESS;
}

int test_passed(){
    if (test_encode_non_cyclic_lower_case_positive_k() != 0)
        return 1;
    if (test_encode_cyclic_lower_case_special_char_positive_k() != 0)
        return 1;
    if (test_encode_cyclic_upper_case_positive_k() != 0)
        return 1;
    if (test_encode_non_cyclic_lower_case_positive_k() != 0)
        return 1;
    if (test_encode_non_cyclic_lower_case_special_char_negative_k() != 0)
        return 1;
    if (test_decode_non_cyclic_lower_case_positive_k() != 0)
        return 1;
    if (test_decode_cyclic_lower_case_special_char_positive_k() != 0)
        return 1;
    if (test_decode_cyclic_upper_case_positive_k() != 0)
        return 1;
    if (test_decode_non_cyclic_lower_case_positive_k() != 0)
        return 1;
    if (test_decode_non_cyclic_lower_case_special_char_negative_k() != 0)
        return 1;
    return 0;
}