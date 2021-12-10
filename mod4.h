/*This function searches and highlights the pattern thus replicating the Ctrl+F feature*/

void highlight()
 {
     FILE *fp;
     char file_name[100];
     char content;  //content is the variable to print the content of the file
     askForName:
     printf("Enter the file path\n");
     scanf("  %[^\n]%*c", file_name);
     if(checkExtension(file_name)==false)goto askForName;
     int c=0;
     fp=fopen(file_name,"r+");
     if(fp==NULL) //to check if the file entered is present
     {
         printf("File not present");
         
     }
     else
     {
         printf("Here are the contents of the file which you opened\n\n");
         
         content=fgetc(fp); 
         while(content!=EOF)
         {
             printf("%c",content);
             content=fgetc(fp);
         }
        
        printf("\n*****************THIS LINE IS INTENTIONALLY LEFT BLANK********************\n"); 
        printf("\nEnter the pattern/word you want to find in the file\n");
        
     
        //str is the pattern to be searched.
        char str[101];
        scanf("  %[^\n]%*c", str);//The pattern entered to be searched.
        char replace[100]; //String to be printed and highlighted if it matches the inputted pattern
     
        rewind(fp);//The pointer starts from the beginning after reaching EOF
     
        char ch=fgetc(fp);
        while(ch!=EOF)
        {
        
            if(ch==str[0])
            {
                replace[0]=ch;
                c=1;       //counter for the no. of characters in the pattern we are checking
             	int i;
			    for(i=1;i<strlen(str);i++)
                {
                    ch=fgetc(fp);
                    if(ch=='\n')    //This ensures that if the characters are  on two different lines then it would be able to search
                    {
                        replace[c++]=ch;
                        if(str[i]!=' ')
                        --i;
                     
                    }
                    else if(str[i]==ch)
                    {
                    
                        replace[c++]=ch; //Adding the character to the replace string
                    }
                    else
                    {
                        replace[c]='\0';
                        break;
                    }
                 
                 
                }
             
             
                if(c>=strlen(str))
                {
                 
                    printf(RED     "%s"    WHITE,replace); //highlight in red colour and then get back to white
                 
                    replace[0]='\0';
                }
             
                else if(c>0)
                {
                	int i;
                    for(i=0;i<c;i++)
                    {
                        printf("%c",replace[i]); //Print those characters in white which are substring of the pattern not wholly
                    }
                 
                }
                replace[0]='\0'; 
                c=0;
                ch=fgetc(fp);
            
            }
            else
            {
                printf("%c",ch); //Print those characters in white if does not match the pattern even partially
                ch= fgetc(fp); 
            }
         
         }
         fclose(fp);
    }
     
}
