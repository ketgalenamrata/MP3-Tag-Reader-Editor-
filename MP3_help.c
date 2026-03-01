#include "MP3.h"
void no_argument()
{
    // Shown when user provides no arguments
    printf("===================================================================================\n");
    printf("                           INVALID ARGUMENTS PROVIDED\n");
    printf("===================================================================================\n");
    printf("Usage:\n\n");
    printf("View MP3 tag information:\n");
    printf("      ./a.out -v <mp3_filename>\n\n");

    printf("Edit MP3 tag information:\n");
    printf("    ./a.out -e <mp3_filename> <tag_option> <new_value>\n");
    printf("Tag Options:\n");
    printf("      -t   Edit Title\n");
    printf("      -a   Edit Artist\n");
    printf("      -A   Edit Album\n");
    printf("      -y   Edit Year\n");
    printf("      -m   Edit Genre\n");
    printf("      -c   Edit Comment\n");

    printf("Help:\n");
    printf("      ./a.out --help\n");
    printf("===================================================================================\n");
}

void help_mp3()
{
    // Help and documentation
    printf("===================================================================================\n");
    printf("                                MP3 TAG READER HELP\n");
    printf("===================================================================================\n");

    printf("Options:\n");
    printf("  -v <file>                View MP3 tag information\n");
    printf("  -e <file> <tag> <text>   Edit MP3 tag\n\n");

    printf("Tag Options for editing:\n");
    printf("  -t    Edit Title\n");
    printf("  -a    Edit Artist\n");
    printf("  -A    Edit Album\n");
    printf("  -y    Edit Year\n");
    printf("  -m    Edit Genre\n");
    printf("  -c    Edit Comment\n\n");

    printf("Examples:\n");
    printf("  View tags:\n");
    printf("      ./a.out -v sample.mp3\n\n");

    printf("  Edit title:\n");
    printf("      ./a.out -e sample.mp3 -t \"New Song Name\"\n\n");

    printf("  Edit artist:\n");
    printf("      ./a.out -e sample.mp3 -a \"New Artist\"\n\n");

    printf("===================================================================================\n");
}
