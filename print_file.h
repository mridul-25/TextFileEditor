/*this function prints the file [given by file pointer fptr] line by line 
so that it is easy for the user to identify the line number in which the content is needed to be edited */
int print_file(FILE *fptr)
{
    char c;
	c = fgetc(fptr);
	bool isFileEmpty = false;
	static int i;
	i=1;
	while (c != EOF) 
		{
			if(!isFileEmpty)
			{
				printf("\n-------------------------------");
				printf("\n_line number %d_\n",i);
				printf("-------------------------------\n");
				isFileEmpty = true;	
			}
        	printf("%c", c);
        	c = fgetc(fptr);
        	if(c=='\n')
			{
				i+=1;
				printf("\n-------------------------------");
				printf("\n_line number %d_\n",i);
				printf("-------------------------------");
			}
	 	}
	 	printf("\n");
	return i;
	//this return value will give us the total number of line in the file
}				

