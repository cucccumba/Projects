#include "String.h"
#include "read_and_write.h"
#include "Sort.h"

//! This program reads text from input file and prints in output file the same text,
//! text, sorted by strings and text, sorted in reverse order by strings

/*! \input
    1) Input file name.
    2) Output file name.
*/

int main()
{
    printf("Enter input file name\n");
    char inputfilename[20];
    char outputfilename[20];
    scanf("%s", inputfilename);

    char *buf = (char *)calloc(bufsize, sizeof(char));
    input_text(buf, inputfilename);
    int strings_count = count_strings(buf);

    String *strings = (String *)calloc(strings_count, sizeof(String));
    strings = make_index(strings, buf);

    String *strings_sorted = (String *)calloc(strings_count, sizeof(String));
    strings_sorted = sort_text(strings, strings_sorted , strings_count);

    String *strings_sorted_back = (String *)calloc(strings_count, sizeof(String));
    strings_sorted_back = sort_text_back(strings, strings_sorted_back, strings_count);

    printf("Enter output file name\n");
    scanf("%s", outputfilename);

    print_text_in_file(strings, strings_count, outputfilename);
    print_text_in_file(strings_sorted, strings_count, outputfilename);
    print_text_in_file(strings_sorted_back, strings_count, outputfilename);

    printf("All is done, check result in output.txt\n");

    free(buf);
    free(strings);
    free(strings_sorted);
    free(strings_sorted_back);
    return 0;
}
