#include <stdio.h>              //C standard library header file for printf(),fprintf(),scanf(),etc.
#include <string.h>				//used for strlen(),NULL
#include <stdbool.h>			//use to define true and false macros
#include <stdlib.h>				// for using exit()
#define RED     "\x1b[31m"		//this is for displaying red color in the console
#define WHITE   "\x1b[0m"		//this is for displaying white color in the console
#define GREEN	"\x1b[32m"		//this is for displaying green color in the console
#define	CYAN	"\x1b\[36m"		//this is for displaying cyan color in the console
#define ORANGE	"\x1b\[33m"		//this is for displaying orange color in the console
#include"help.h"				//use for calling help() to display help menu
#include"cFileExists.h"			//use to check whether file exists or not
#include"scanString.h"			//to call scanString() which will scan input including '\n' , except '~'
#include"edit.h"				//to call edit_line() which will edit one line of the file and save it
#include"print_file.h"			//to call print_file() which 
#include"checkExtension.h"		//to include checkExtension() which will check whether .txt extension is used or not
#include"mod3.h"				//to include save-as function
#include"mod4.h"				//to call highlight() which replicates the Ctrl+F feature
#include"mod5.h"				//to call file_comparison() for comparing the two inputted files are exactly same or not
#include"mod6.h"				//to call remove_file() for deleting the file

int main() 
{	
	printf("********************WELCOME TO THE TEXT EDITOR********************\n\n\n");
    printf(CYAN"Note: Enter 'h' for help or 'e' to exit the program."WHITE);
    //if 'h' is pressed a help menu will be displayed in which all the available features of the 
    printf(CYAN"\nEnter numbers between the range(1-6): "WHITE);
    char input;
    //input is used to take know what the user what to do.
    scanf("%c", &input);
    while (true) 
	{
        
        if (input == 'h' || input == 'H')
		{
		help();// Help menu will be displayed in which all the features/modules of the text editor are explained
		}
        
        else
			{
			if (input == '1')/*we can input a desired name for the text file,
			then can write content in it and then finally we'll be asked whether to save it or not */ 
			{
	            FILE *filePointer;
		        char file_name[20];
	    	    new_file:
	        	printf(CYAN"Enter the name of file within 20 characters with extension '.txt': "WHITE);
	            scanf(" %[^\n]%*c", file_name);
	            if(checkExtension(file_name)==false)goto new_file;//if the file extension is invalid it will again ask the file name
		        char* filename = file_name;
	    	    int exist = cFileExists(filename);
	    	    /*to know when the cFileExits will have value as 0 or 1 is commented in 'cFileExists.h' header file*/
	    	    /*when exist==0 then if(exist){} will not work and when exist==1
	    	    then if(exist){} will work */
	       		if (exist) 
				   {
	            	printf(ORANGE"File Name Already Taken :(\n"WHITE);
	            	goto new_file;				
					/*as the file whose name was entered was already existing 
					so it again returned to 'new file:' in which we can enter another valid input*/
	        		} 
				else 
					{
						filePointer=fopen(file_name,"w");
						if (filePointer == NULL) 
								//fopen will return NULL if the file doesn't exist or some permission is denied
							{
	                    		printf(ORANGE"%s file failed to open"WHITE, file_name);
	                		}
						char *t=scanString();
						fprintf(filePointer,"%s",t);
						repeat:
	            		printf(CYAN"Do you want to save the file? [Y/N]\n"WHITE);
	            		char run;
	            		scanf(" %c", &run);
	            		if (run == 'Y' || run == 'y')
	            			{
					   		//	filePointer = fopen(file_name, "w+");
								fclose(filePointer);
							}
						else 
							{if (run == 'N' || run == 'n') 
								{
								remove(file_name);
	                			goto task;
	            				}
							else 
								{
	                			printf(ORANGE"Bad Input. Please Choose from Y/N.\n"WHITE);
	                			goto repeat;
	            				}
							}
	            } 
            }
        
    
        
        	else
			{
			 if (input == '2') // Open an existing file, edit its contents and save it
			 {
            	choose_file:;
            	FILE *fptr;
    			char file_name[20];
				new_file1:    
			    printf(CYAN"Enter the file name you want to open with extension .txt within 20 characters: "WHITE);
			    scanf(" %[^\n]%*c", file_name);
			    if(checkExtension(file_name)==false)goto new_file1;//if the file extension is invalid it will again ask the file name

			    fptr = fopen(file_name, "r+");
				if(fptr == NULL) 
				{	
					perror("fopen");//it tells the error
			        printf(ORANGE"Cannot open file\n"WHITE);
			        goto task;
				}
				
 
				int total_lines_in_file = print_file(fptr);
				int line_number_to_edit; 
				get_line_number: 
				printf("The file has %d lines\n", total_lines_in_file);
			    printf(CYAN"Enter the line number you want to edit: "WHITE);
			    scanf("%d", &line_number_to_edit);
			    if (line_number_to_edit > total_lines_in_file)
					{
			    	printf(ORANGE"The file has only %d lines but you wanted to edit line number %d which does not exist. Please enter smaller line number"WHITE,
					 total_lines_in_file, line_number_to_edit);
					goto get_line_number;
					}
				 
			    edit_line(fptr, line_number_to_edit, file_name);
			    }
    		
        	else 
			{
			if (input == '3'){save_as();}
        	else
				{
				if (input == '4') {highlight();}
        		else
					{
					if (input == '5'){file_comparison();}
        			else 
						{	
							if (input == '6') {remove_file();}
// Exit Condition for the program
        					else 
								{	
								if (input == 'e' || input == 'E') 
									{
            						ask:
            						printf(ORANGE"\nDo you really want to exit? [Y/N]\n"WHITE);
            						char test;
            						scanf(" %c", &test);
            						if (test == 'y' || test == 'Y')
										{
	               		 					printf("\nThank You !!");
	                						exit(0);
	       								} 
									else
										{ 
											if (test == 'n' || test == 'N') 
												{
		            							goto task;
		        								} 
											else 
												{
		            							printf(ORANGE"\nPlease enter the character among Y/N.\n"WHITE);
		            							goto ask;
		        								}
										}
        							}
        						}
        					}
        				}
        			}
        		}
			}
		}
	task:
    printf(CYAN"Note: Enter 'h' for help or 'e' to exit the program."WHITE);
    //if 'h' is pressed a help menu will be displayed in which all the available features of the 
    printf(CYAN"\nEnter numbers between the range(1-6): "WHITE);
    scanf(" %c", &input);
	}
}

