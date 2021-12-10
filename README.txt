################################################################
ReadMe for assignment submitted by 2019B3PS0410P and 2019B5PS0781P
Practical section number: P8
Assignment question attempted: 4
################################################################
Team:
1. 2019B3PS0410P   Mridul Bhatia
2. 2019B5PS0781P   Maunil Chopra
3. 2019B4PS0718P   Rahul Moondra
################################################################
How to compile
1. Run the following command - 
gcc 2019B5PS0781P_P8.c -o 2019B5PS0781P_P8.exe

2. Then execute our program by typing the command - 
./2019B5PS0781P_P8.exe

Description of how to run the code and observe the output:
1.At the begining of the execution "WELCOME TO TEXT EDITOR" will be displayed,It is a menu-driven application. In order to see the menu please type 'h' .

2.Different modules and other functions used are written in different header(.h) files.

3.Description of different header files:-
	a)cFileExists.h -- It has a function to check whether a file exists or not. If the file exists it return 1, and if not then it 		returns 0.

	b)checkExtension.h -- It has a function which checks whether the extension of the given file is valid or not. If the 		file name ends with '.txt', then it returns true else it returns false.

	c)edit.h -- It has functions which are used to edit one single line of the inputted file.

	d)help.h -- It has the help menu which in detail describes all the features of the text editors and instructions to use 	different features.

	e)print_file.h -- It has function that prints the file line by line and also label each line so that user can easily 		identify which line is needed to be edited.

	f)scanString.h -- It has a function which scans the input from the user until the user type '~' [to type '~' the user 		need to press simultaneously SHIFT and TILDE buttons] and then press ENTER

	g)mod3.h -- It has functions used to replicate the SAVE AS feature in the file system.

	h)mod4.h -- It has functions to match and highlight an inputted pattern of characters in the inputted file name.

	i)mod5.h --It has functions used to compare two existing files.

	j)mod6.h --It has functions used to remove an existing file.

4.The menu displays options from 1-6 as mentioned in the question.

5.In order to perform a function as displayed in the menu the no. between 1-6 is to be entered.

6.In order to exit the program you have to type 'e' or 'E' ONLY WHEN the computer asks for help or for a no. between the range 1-6 on the console.

7.Whenever in subsequent modules the inputted file does not exist that module is exited and again the prompt of entering the either 'e'/'E' for exit,'h'/H' for help or no. between 1-6 appears. 

8.Please note that if the file is not present in the same directory, user has to type the path of the file.

9. When option 1 is chosen, there will be prompt to enter a file name of atmost 20 character [ using more than that will display an error ] which doesn't exist. If the file already exists, the user will be prompt to enter another name. If the extension is not valid [ as the question was to make a text editor, so any extension except '.txt' is considered as invalid ], then the user will be prompt to enter valid extension. 
	If there is no issue in the name, then an empty file will be created with the inputted name and  the user will be prompt to write the content of the file. To exit, the user should type '~' [to type '~' the user need to press simultaneously SHIFT and TILDE/'~' buttons] and then press ENTER. After that the user will be prompt to choose whether to save the file or not. If 'Y'or 'y' is selected then the file with the inputted name and content will be saved. If 'N' or 'n' is selected then the file with the inputted name and content will be destroyed.

10. When option 2 is chosen, there will be prompt to enter the file name of atmost 20 character [ using more than that will display an error ] which the user want to modify. If the file name is valid[ which means the extension is proper and the file should exist] , the file will be displayed line by line with label for each line just above the line. And then the user will be prompt to choose line number which is needed to be replaced by another line. If the user chooses line number greater than total lines, then there will be a prompt to again choose a line number . If user chooses valid line number, then the content of that particular line will be displayed the user will be prompt to enter the new content for replacing the old content. To exit , the user should press ENTER. After that the new content will be shown.

9.When option 3 is chosen, there will be a prompt to enter a file name [assumed to be of atmost 100 character] which exists for which the user has to change the name.
  Then a prompt appears to type the name of new file.The user has to type the name of file along with extension. If the file with the inputted name does not exist, it creates the file with the new name.
  If the file with the new name already exists, it prompts the user to choose whether to overwrite the file or not. The prompt gives the option of Y or N.
  If 'Y'/'y'(without quotes) is inputted, the file is overwritten. If 'N'/'n'(without quottes) is entered then it does not overwrite and the module is exited.
  If any other character is entered apart from 'Y,'y','N'or'n', then again the prompt appears to enter Y or N.

10.When option 4 is chosen,there will be a prompt to enter the existing file name  [assumed to be of atmost 100 character]. The file name is inputted by the user.If it is present then, it will display the whole content of the file on the console.
  Then it prompts to enter a pattern/word user wants to search. The user has to enter the required pattern.If the exact pattern is present then it is highlighted in red.If it happens that the pattern is present in two consecutive 
  lines then also it performs it's function.

11.When option 5 is chosen, there is a prompt to enter the name of the first file  [assumed to be of atmost 100 character].Then there will be a prompt for entering second file name of atmost 100 characters. Then it compares the two files 
   that whether they are different or exactly the same.The appropriate messages are displayed on the console.Please note that the difference in no. of new line characters also can create a difference.
 
12.When option 6 is chosen, there is a prompt to enter the name of the file  [assumed to be of atmost 100 character] you want to delete.The user enters the name of the file. If the file exists and an appropriate message is displayed then the file is deleted otherwise that module is exited 
   with an appropriate message.




################################################################
Contributions of the team members:
Mridul Bhatia did modules 3,4,5 and 6 and also helped in module 1. Also contributed in Readme
Maunil Chopra did modules 1 and 2.[and thus made-- cfileexists.h ,checkExtension.h ,print_file.h ,edit.h,scanString.h] Also contributed to make the help menu, and made layout of main() to compile all the modules and have an user friendly interface . Also contributed in Readme
Rahul Moondra did not had his PC and in these difficult circumstances he had to go to 
cyber cafe in order to code. He helped in modules 3 and 4 in his own ways under the restraints.

