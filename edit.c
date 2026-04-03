/* NAME : HASHWANTH P
 * DATE : 7/11/2025
 * DESCRIPTION: 1. This project is to view or edit the mp3 file
                2. Edit the tag and store in temporary file and finally change the name as orginal file name.
*/

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_LE_to_BE(char* size)  // Convert size
{
	char temp;
	temp = size[0];
	size[0] = size[3];
	size[3] = temp;
	temp = size[1];
	size[1] = size[2];
	size[2] = temp;

}
char *map_tag(char *tag)  // Finding TAG
{
    if (strcmp(tag, "-t") == 0) return "TIT2";  // Title
    if (strcmp(tag, "-a") == 0) return "TPE1";  // Artist
    if (strcmp(tag, "-A") == 0) return "TALB";  // Album
    if (strcmp(tag, "-y") == 0) return "TYER";  // Year
    if (strcmp(tag, "-C") == 0) return "TCON";  // Content type
    if (strcmp(tag, "-c") == 0) return "COMM";  // Comment
    return NULL;  // Invalid flag
}
void edit_mp3(char* argv[])
{
	char* tag = argv[2];
	char* new_name = argv[3];
	FILE* samp = fopen(argv[4],"r");
	FILE* temp = fopen("temp.mp3","w");
	if((samp == NULL)||(temp == NULL))
	{
		printf("File is not found\n");
		exit(0);
	}
	else
	{
		// Copy 10-byte ID3 header
		char header[11];
    		fread(header, 1, 10, samp);  
		header[10] = '\0';
   		fwrite(header, 1, 10, temp);
		while(1)
		{
			char Tag[5];
			fread(Tag,1,4,samp);
			Tag[4] = '\0';
			if(strcmp(map_tag(tag),Tag) == 0)
			{
	            		fwrite(Tag, 1, 4, temp);
				// Write new size
            			int new_size = strlen(new_name) + 1;
            			convert_LE_to_BE((char*)&new_size);    // function call for little Endian to BE
            			fwrite(&new_size, 4, 1, temp);
				int size;
				fread(&size,sizeof(int),1,samp);
            			convert_LE_to_BE((char*)&size);    // function call for little Endian to BE
 				
				// Read & Write flag,null
				char flags[4];
				fread(flags, 1, 3, samp);
				flags[3]='\0';
            			fwrite(flags, 1, 3, temp);

            			// Write new name
            			fwrite(new_name,1,strlen(new_name), temp);

            			// Skip old frame data from samp
            			fseek(samp, size-1, SEEK_CUR);
				break;
			}
			else
			{
				fwrite(Tag, 1, 4, temp);
				// Write size
				int size;
				fread(&size,4,1,samp);
				fwrite(&size, 4, 1, temp);
				
				// Read & Write flag,null
				char flags[4];
				fread(flags, 1, 3, samp);
				flags[3] = '\0';
            			fwrite(flags, 1, 3, temp);
				convert_LE_to_BE((char*)&size);    // function call for little Endian to BE
            			
				// Write name
				char ch;
				for(int i=0; i<size-1;i++)
				{
					fread(&ch,sizeof(char),1,samp);
            				fwrite(&ch,sizeof(char),1 , temp);
				}
			}
		}

	}
	// Copy the rest of the MP3 (audio data)
    	char ch;
    	while(!(feof(samp)))
	{
		fread(&ch,sizeof(char),1,samp);
            	fwrite(&ch,sizeof(char),1,temp);
	}
    	fclose(samp);
    	fclose(temp);

    	remove(argv[4]);
    	rename("temp.mp3",argv[4]);

	printf("Tag edited successfully!\n");	
}

