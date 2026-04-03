/* NAME : HASHWANTH P
 * DATE : 7/11/2025
 * DESCRIPTION: 1. This project is to view or edit the mp3 file
                2. Edit the tag and store in temporary file and finally change the name as orginal file name.
*/

#include "header.h"
#include<stdlib.h>

void convert_BE_to_LE(char* size)   // convert size
{
	char temp;
	temp = size[0];
	size[0] = size[3];
	size[3] = temp;
	temp = size[1];
	size[1] = size[2];
	size[2] = temp;

}
void view_mp3( char* argv[])
{
	FILE* fp = fopen(argv[2],"r");
	
	if(fp == NULL)
	{
		printf("Mp3 File is not found\n");
		exit(0);
	}
	else
	{
		char buffer[4];
		fread(buffer,sizeof(buffer)-1,1,fp);
		
		if (buffer[0] != 'I' && buffer[1] != 'D' && buffer[2] != '3')
		{
			printf("ID3 is not found in File\n");
			exit(0);
		}
		buffer[3] = '\0';
		fseek(fp,7,SEEK_CUR);
		
			printf("-------------------------------------------------------------------\n");
			printf("MP3 Tag Reader and Editor for ID3v2\n");
			printf("-------------------------------------------------------------------\n");
		for(int t=0; t<6; t++)
		{
			// Read TAG
			char tag[5];
			fread(tag,sizeof(tag)-1,1,fp);
			tag[4] = '\0';
			// Read size
			int size;
			fread(&size,sizeof(int),1,fp);
			convert_BE_to_LE((char*)&size);    // function call
			
			fseek(fp,3,SEEK_CUR);
		        // Read name 
			char content[size];
			char ch;
			for(int i=0; i<size-1;i++)
			{
				fread(&ch,sizeof(ch),1,fp);
				content[i] = ch;
			}
			content[size-1] = '\0';
			if(t == 0)
			{
				printf("Title     :    %s\n", content);   
			}
			else if(t == 1)
			{
				printf("Artist    :    %s\n", content);
			}
			else if(t == 2)
			{
				printf("Album     :    %s\n", content);
			}
			else if(t == 3)
			{
				printf("Year      :    %s\n", content);
			}
			else if(t == 4)
			{
				printf("Music     :    %s\n", content);
			}
			else if(t == 5)
			{
				printf("Comment   :    %s\n", content);
			}
		}

			printf("-------------------------------------------------------------------\n");
	}
}


