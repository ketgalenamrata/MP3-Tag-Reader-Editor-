#include "MP3.h"

void edit_mp3(char *filename, char *tag, char *newname)
{
    char edittags[6];
    // Match user tag option with corresponding ID3 frame
    if (strcmp(tag,"-a") == 0)
        strcpy(edittags,"TPE1");//artist name
    else if (strcmp(tag,"-t") == 0)
        strcpy(edittags,"TIT2"); // Title / song name
    else if (strcmp(tag,"-A") == 0)
        strcpy(edittags,"TALB"); // Album
    else if (strcmp(tag,"-y") == 0)
        strcpy(edittags,"TYER"); // Year
    else if (strcmp(tag,"-m") == 0)
        strcpy(edittags,"TCON"); // Content type
    else if (strcmp(tag,"-c") == 0)
        strcpy(edittags,"COMM");// Comment
    else 
    {
        printf("Invalid tags\n");
        return ;
    }
    FILE *fp = fopen(filename,"rb");
    // Original MP3 file must open
    if(fp==NULL)
    {
        perror("Error opening MP3");
        return;
    }
    FILE *tmp = fopen("duplicate.mp3","wb");
    // Temporary file to write updated data
    if(tmp==NULL)
    {
        perror("Error creating temporary file");
        fclose(fp);
        return;
    }
    // Copy 10-byte header
    char buff[10];
    fread(buff, 10, 1,fp);
    fwrite(buff, 10, 1, tmp);
    // Process 6 frames
    for(int i=0; i<6; i++)
    {
        char TAG[5];
        // Read frame ID
        fread(TAG,sizeof(TAG)-1, 1, fp);
        TAG[4]='\0';
        // Write frame ID to temporary file
        fwrite(TAG,sizeof(TAG)-1, 1,tmp);
         // Check if current frame matches the target frame
        if(strcmp(TAG,edittags) == 0)
        {
            // Calculate new size (content length + null byte)
            int size = strlen(newname) + 1;
            int tmp_size = size - 1;
            //converting
            size = convertBtoL(size);
            fwrite(&size, sizeof(size), 1, tmp);

            char flag[2];
            int new_size;
            fread(&new_size, sizeof(new_size), 1, fp);
            fread(flag, 2, 1, fp);

            //write the same flag
            fwrite(flag, 2, 1, tmp);
            char null = '\0';
            fwrite(&null, 1, 1, tmp);
            fwrite(newname, tmp_size, 1, tmp); 

            // Skip old content in original file
            new_size = convertBtoL(new_size);
            fseek(fp, new_size, SEEK_CUR);
            break;
        }
        else
        {
            // Copy original frame size and data unchanged
            int size;
            fread(&size, 4, 1, fp);
            fwrite(&size, 4, 1, tmp);

            size = convertBtoL(size);

            char flag[2];
            fread(flag, 2, 1, fp);
            fwrite(flag, 2, 1, tmp);

            char content2[size];
            fread(content2, size, 1, fp);
            fwrite(content2, size, 1, tmp);
        }
    }
    // Copy remaining bytes 
    char buffer[1];
    while (fread(buffer, 1, 1, fp))
    {
        fwrite(buffer, 1, 1, tmp);
    }

    fclose(fp);
    fclose(tmp);
    // Replace original file
    remove(filename);

    rename("duplicate.mp3",filename);

    printf("File edited successfully.\n");

}
