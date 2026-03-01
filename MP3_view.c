#include "MP3.h"
// Display names for frames
char *Frame[6] ={"Title", "Artist", "Album", "Year", "Genre", "Comment"};
void view_mp3(char *song)
{
    
    FILE *fp = fopen(song,"rb");
    // Check if file exists
    if(fp == NULL)
    {
        perror("Error opening file");
        return;
    }
    // Read 3-byte "ID3" header
    char buffer[4];
    fread(buffer,sizeof(buffer)-1, 1, fp);
    buffer[3]='\0';
    // Validate MP3 ID3 tag
    if(strcmp(buffer,"ID3")==0)
    {
        printf("\n========================================\n");
        printf("\tMP3 tag Informataion\n");
        printf("========================================\n\n");
    }
    else
    {
        printf("Error: Not a valid MP3 file with ID3 tag.\n");
        fclose(fp);
        return;
    }
   
    //skip 7 byte after ID3
    fseek(fp,7,SEEK_CUR);
    // Process 6 frames
    for(int i=0 ; i < 6 ; i++ )
    {
        char tag[5];
        // Read frame ID (4 bytes)
        fread(tag, sizeof(tag)-1, 1, fp);
        tag[4]='\0';
       

        //read 4 byte of content
        int size;
        fread(&size,sizeof(int), 1, fp);
        size = convertBtoL(size);

        // skip flag and null 3 byte 
        fseek(fp,3,SEEK_CUR);
        
        // read one by one byte content
        char content[size];
        fread(content,size-1, 1, fp);
        content[size-1]='\0';
        //print tag and value
        printf("%-10s:  %s\n",Frame[i],content); 
    }
    printf("\n========================================\n");
    fclose(fp);
}
// Convert big-endian 4-byte size to little-endian
int convertBtoL(int size)
{
    char *ptr = (char*)&size;
    int n=sizeof(int);
    for(int i=0; i<n/2; i++)
    {
        char temp = ptr[i];
        ptr[i] = ptr[n-i-1];
        ptr[n-i-1] = temp;
    }
    return size;
}