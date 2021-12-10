//Accepting string from the user till he requires typing, he can type as long as he want[unless memory is not over] 

char* scanString()
{
    int   i = 2, j = 0;
    char  *data;
    
    printf("Enter any string: \n");
    printf("TYPE ~  AND THEN PRESS ENTER to exit\n"); 
    //use of dynamic memory allocation
    
    data = malloc(sizeof(char));
    while(1)
    {
    	char c= getchar();
    	if (c == 126) break; // Exit the loop if we receive '~'
    	//as we used '~' for exiting so we can't write this character in our file
    	//126 is ascii for '~'
    	//note:we need to press both shift key and the key below esc to type '~'
		data[j] = c;
        data = (char *) realloc(data, sizeof(char) * i);
        //this is used to increase the memoryn of data according to the inout from the user
        i++;
        j++;
        
    }
    
    /*the above code will first get a character from the user,
	and then it will check whether that character is '~' or not.
	if it is '~', then it will come out of the while loop. 
	otherwise it will assign the value of that character,
	which was taken from user to the elments of array of pointers data[]*/
	 
    data[j]='\0'; 
    return data;
}

