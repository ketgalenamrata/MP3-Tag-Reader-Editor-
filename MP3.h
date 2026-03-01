#ifndef MP3_H
#define MP3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function declarations for MP3 tag operations
void no_argument();
void help_mp3();
void view_mp3(char *song);
void edit_mp3(char *filename, char *tag, char *newname);

// Convert 4-byte big-endian size to little-endian
int convertBtoL(int size);

#endif