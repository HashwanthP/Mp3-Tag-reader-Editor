/* NAME : HASHWANTH P
 * DATE : 7/11/2025
 * DESCRIPTION: 1. This project is to view or edit the mp3 file
                2. Edit the tag and store in temporary file and finally change the name as orginal file name.
*/

#include "header.h"

void usage_msg(void)
{
	printf("\n..........................................................................\n");
	printf("                          MP3 USAGE GUIDELINE \n");
	printf("............................................................................\n\n");
	
	printf("............................................................................\n");
	printf("____For Help :       ./a.out -h\n");
	printf("____For View :       ./a.out -v file_name.mp3\n");
	printf("____For Edit :       ./a.out -e -t/-a/-A/-y/-C/-c new_filename file_name.mp3\n");
	printf("............................................................................\n");
}

int main(int argc,char* argv[])
{
	if(argc == 1) // For ./a.out only
	{
		printf("Error : Invalid Option\n");
		usage_msg();
	}
	else if(strcmp(argv[1],"-h") == 0) // For Help guidline
	{
		usage_msg();
	}
	else if(strcmp(argv[1],"-v") == 0)  // View condition check
	{
		if(argc == 3)
		{
			view_mp3(argv);
		}
		else
		{
	
			printf("Error : View Command line\n");
			usage_msg();
		}
	}
	else if(strcmp(argv[1],"-e") == 0)  // Edit condition check
	{
		if(argc == 5)
		{
			edit_mp3(argv);
		}
		else
		{
			printf("Error : Edit Command line\n");
			usage_msg();
		}
	}

	return 0;
}

