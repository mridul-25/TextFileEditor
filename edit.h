// This function moves the file pointer to the beginning of a line whose number is line_number 
void goto_line_number(FILE *fptr, int line_number)
{
	rewind(fptr);//The pointer starts from the beginning after reaching EOF
	char c;
	int i = 1;
	if(i==line_number)
	{
		return;
	}
	c = fgetc(fptr);
	while (c != EOF) 
		{
        	c = fgetc(fptr);
        	if(c=='\n')
			{
				i+=1;
				if(i==line_number){
					break;
				}
			}
	 	}
}

// This function prints the next line of the file
void print_line(FILE *fptr){
	char c;
	c = fgetc(fptr);
	while (c != '\n' && c!= EOF) 
		{
        	printf("%c", c);
        	c = fgetc(fptr);
	 	}
}

// This function writes a line whose content is new_line_content to the file
void write_line_to_file(FILE *fptr, char new_line_content[])
{
	int i = 0;
	for(i=0;i<2000;i++){
		char c = new_line_content[i];
		if(c=='\0'){
			break;
		}
		fputc(c, fptr);
	}
}

// This function copies rest of content from file fptr_from to the file fptr_to
void copy_rest_of_file(FILE *fptr_from, FILE *fptr_to)
{
	char c = ' ';
	c = fgetc(fptr_from);
	if(c != EOF){
		fputc('\n', fptr_to);
	}
	while (c != EOF) 
	{
		fputc(c, fptr_to);
    	c = fgetc(fptr_from);
 	}
}

// This function writes content till given line number from file fptr_from to file fptr_to
void write_till_line_number(FILE *fptr_from, FILE *fptr_to, int line_number)
{
	rewind(fptr_from);
	rewind(fptr_to);
	char c;
	int i = 1;
	if(i==line_number)
	{
		return;
	}
	while (c != EOF) 
		{
        	c = fgetc(fptr_from);
        	fputc(c, fptr_to);
        	if(c=='\n')
			{
				i+=1;
				if(i==line_number){
					break;
				}
			}
	 	}
	return;
}

// This function calls all of the above functions to allow editting one single line in a file
void edit_line(FILE *fptr, int line_number_to_edit, char file_name[])
{
	goto_line_number(fptr, line_number_to_edit);
	printf("Contents of line %d are\n", line_number_to_edit);
	print_line(fptr);
	printf("\nEnter new content for this line:\n");
	char new_line_content[2000];    
	scanf(" %[^\n]%*c", new_line_content);
	printf("New content is\n");
	printf("%s\n", new_line_content);
	FILE *fptr_temp;
	fptr_temp = fopen("temporary.txt", "w+");
	write_till_line_number(fptr, fptr_temp, line_number_to_edit);
	write_line_to_file(fptr_temp, new_line_content);
	goto_line_number(fptr, line_number_to_edit + 1);
	char *rest_of_file_content = (char*) malloc(100 * sizeof(char));
	copy_rest_of_file(fptr, fptr_temp);
	fclose(fptr_temp);
	fclose(fptr);
	remove(file_name);
	rename("temporary.txt", file_name);
}
