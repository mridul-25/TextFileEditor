/*This function is replicates the save as feature*/

void save_as()
{
    char oldname[100], newname[100];
  //path to old file
  	askForName:
    printf("enter old file path or file name\n");
    scanf("  %[^\n]%*c",oldname);
    if(checkExtension(oldname)==false)goto askForName;//if the file extension is invalid it will again ask the file name
    FILE *fp1;
    fp1=fopen(oldname,"r");
    if(fp1==NULL) //to check if the file with the oldname is already present
    {
        printf("File not found\n");
    }
 
    else
    {
       //path to new file  
        printf("enter new file path or file name\n");
        scanf("  %[^\n]%*c", newname);
        if(checkExtension(newname)==false)goto askForName;//if the file extension is invalid it will again ask the file name
 
        FILE *fp2;
        FILE *temp;
        temp=fopen(newname,"r"); //temp is the temporary pointer
        int flag=0;
        if(temp!=NULL) //This searches if the file with the newname already exists
    	{
        	printf("Such file already exists\n");
        	again: //In case the character inputted is not Y or N.
        	printf("Type Y if you want to overwrite the file and N if you don't want to continue\n");
        	char ch;
        	scanf("%c",&ch);
        	if(ch=='Y'||ch=='y')
        	{
                    flag=1;
                    fclose(temp);
        	}
        	else 
		{
			    if(ch=='N'||ch=='n')
        		    {
           		    printf("File will not be overwritten\n"); 
           		    fclose(temp);
        		    }
        	            else
        	            {
            	    		goto again;
        	    	    }
		    }
    	}
    	
    /*Here the file with the newname if present gets overwritten and if not present the old file content gets
    saved with the newname while the oldname file continues to exist*/
    
    
        if(flag==1||temp==NULL) 
        {
    	    fp2=fopen(newname,"w+");
    	    char c=fgetc(fp1);
    	    while(c!=EOF)
    		{
        	    fputc(c,fp2); //The corresponding characters of file with the oldname are written in 
        	    c=fgetc(fp1); //file with the newname.
   		}
    	    fclose(fp1);
    	    fclose(fp2);
    	    printf("Another file with the required name is formed.\n");
	}
    }
}
