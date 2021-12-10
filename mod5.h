/*function responsible for comparing the two inputted files*/

void file_comparison()
{
    
    printf("Enter the first file path.\n");
    char file1[101],file2[101];   //file1 is the file name of first file
    ask1:
    scanf("  %[^\n]%*c", file1);      //file2 is the file name of the second file
    if(checkExtension(file1)==false)goto ask1;//if the file extension is invalid it will again ask the file name
    ask2:
	printf("Enter the second file path.\n");
    scanf("  %[^\n]%*c", file2);
    if(checkExtension(file2)==false)goto ask2;//if the file extension is invalid it will again ask the file name
 

    FILE *x;FILE *y; //pointers for the two files.
    x=fopen(file1,"r");
    y=fopen(file2,"r");
    
    if(x==NULL||y==NULL)//Checks if the two files are present
    {
        if(x==NULL)
        {
            printf("File1 not present");
         
         
        }
        if(y==NULL)
        {
            printf("File2 not present");
         
        }
    }
    else
    {
        fseek(x,0L,SEEK_END);  //fseek is used to move pointer from end to start
        long int size1=ftell(x); //size1 is the size of the first file.
    
    
        fseek(y,0L,SEEK_END);
        long int size2=ftell(y); //size2 is the size of the second file
     
    
        char c1,c2;
        int flag=0; //flag is raised when the corresponding characters in the two files are different.
        rewind(x);
        rewind(y);
        c1=fgetc(x);
        c2=fgetc(y);
        while(c1!=EOF&&c2!=EOF)
        {
        
            if(c1!=c2)  //comparing the corresponding characters at a time
            {
                flag=1;
                break;
            }
            c1=fgetc(x);
            c2=fgetc(y);
        }
    
        fclose(x);  //Closing the files.
        fclose(y);
            
        if (flag==1||(size1!=size2))
            printf("The files are different.\n");
        else
            printf("The files are exactly the same.\n");
    
    }
    
}
