/* Description - MP3 TAG READER PROJECT. Handles user input and decides whether to view or edit MP3 tag 
    Name - Namrata Ketgale
    Start date -  15/1/2026
    End date - 24/1/2026
    Admission id - 25031_168
*/

#include "MP3.h"
int main(int argc, char* argv[])
{
    // Check if arguments are provided
    if(argc<2)
    {
        no_argument();
        printf("Use --help for usage information.\n");
        return 1;
    }
    // Show help message
    if(strcmp(argv[1],"--help")==0)
    {
        help_mp3();
        return 0;
    }
    // view MP3 tags
    else if(strcmp(argv[1],"-v")==0)
    {
        // Requires filename
        if (argc < 3)
        {
            printf("Error: Missing MP3 filename for -v option.\n");
            printf("Usage: ./mp3tag -v <filename>\n");
            return 1;
        }
        view_mp3(argv[2]);
    }
    // Edit MP3 tags
    else if(strcmp(argv[1],"-e")==0)
    {
        // Requires filename + tag + new value
        if (argc < 5)
        {
            printf("Error: Invalid arguments for -e.\n");
            printf("Usage: ./mp3tag -e <filename> <tag> <value>\n");
            return 1;
        }
        edit_mp3(argv[2],argv[3],argv[4]);
    }
    // Invalid option
    else
    {
        printf("Error: Unknown option '%s'\n", argv[1]);
        printf("Use --help for usage.\n");
        return 1;
    }
    return 0;
}