bool checkExtension(char file_name[])
{
	int index;
	bool gotDot = false;
	//the following for()loop code is for checking whether the extension entered is correct or not
	for(index=0;index<20;index++) 
	{
		if(index<17 && file_name[index]=='.')
		{
			gotDot = true;
			if(file_name[index+1]=='t')
			{
				if(file_name[index+2]=='x')
				{
					if(file_name[index+3]=='t')
					{
						if(index < 16 && file_name[index+4]!='\0'){
							printf(ORANGE"\nthe extension is invalid \n"WHITE);
							return false;
						}
						else 
						{
							printf(CYAN"\nyou have entered a '.txt' file \n"WHITE);
						}
					}
					else 
					{
						printf(ORANGE"\nthe extension is invalid \n"WHITE);
						return false;
					}
				}
				else 
				{
					printf(ORANGE"\nthe extension is invalid\n"WHITE);
					return false;
				}
			}
			else 
			{
				printf(ORANGE"\nthe extension is invalid\n"WHITE);
				return false;
			}
		}
	}
	if(!gotDot)
	{
		printf(ORANGE"\nthe extension is invalid\n"WHITE);
		return false;
	}
	return true;
}
