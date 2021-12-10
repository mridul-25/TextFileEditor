/*This function removes the file*/

void remove_file()
{
	askForName:
    printf("Enter the name of file with extension which you want to delete.\n");
    char file[101];
    scanf("  %[^\n]%*c", file);
    if(checkExtension(file)==false)goto askForName;//if the file extension is invalid it will again ask the file name
    FILE *fp;
    fp=fopen(file,"r");
    
    if(fp==NULL) //Checks if the file is present
    {
         printf("File not present\n");
         
         
    }
     
    else
    {
        fclose(fp);
     
        if(remove(file)==0)   //remove() function returns 0 when it deletes file.
            printf("The file is deleted\n");
        else 
            printf("The file could not be deleted\n");
    }   
    
}
