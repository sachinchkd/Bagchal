#include <stdio.h>
char isPiece(char s[], int pos);
int goat_mcheck(int old,int news);
int tiger_mcheck(int old, int news);

int main()
{
	char s[24];
	int i,on=1;
	int extra_goats=20;
	_Bool player=0;
	int oldPos,newPos;
	for (i=0;i<25;i++) 
	{
		s[i]=32;
	}
	s[0]=s[4]=s[20]=s[24]=84;
	while( on )
	{
		printf(" %c-----%c-----%c-----%c-----%c \n",s[0],s[1],s[2],s[3],s[4]);
		printf(" | \\   |   / | \\   |   / |\n");
		printf(" |   \\ | /   |   \\ | /   |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[5],s[6],s[7],s[8],s[9]);
		printf(" |   / | \\   |    /| \\   |\n");
		printf(" | /   |   \\ |  /  |   \\ |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[10],s[11],s[12],s[13],s[14]);
		printf(" | \\   |   / | \\   |   / |\n");
		printf(" |   \\ | /   |   \\ | /   |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[15],s[16],s[17],s[18],s[19]);
		printf(" |   / | \\   |   / | \\   |\n");
		printf(" | /   |   \\ | /   |   \\ |\n");
		printf(" %c-----%c-----%c-----%c-----%c\n",s[20],s[21],s[22],s[23],s[24]);
		
		if (player==0)
		{
			//goats turn
			if (extra_goats)
			{	//if there are spare goats
				printf("Enter your move:Goat(5) ");
				scanf("%d",&newPos);
				while (getchar()!='\n');
				
				if (isPiece(s,newPos)==32)
				{
					s[newPos]=71;
					player=1;
				}
				else
				{
					printf("\nNot valid\n");
				}
				
			}
			else
			{	//if there arent spare goats
				printf("Enter your move:(5,10) ");
				scanf("%d%d",&oldPos,&newPos);
				while (getchar()!='\n');
				if ((isPiece(s,newPos)==32) && goat_mcheck(oldPos,newPos))
				{
					s[newPos]=71;
					s[oldPos]=32;
					player=1;
				}
				else
				{
					printf("\nNot valid\n");
				}
			}
		}
		
		else
		{
			//tiger turn
			printf("Enter your move:Tiger(5,10)");
			scanf("%d%d",&oldPos,&newPos);
			while (getchar()!='\n');
			if (isPiece(s,newPos)==32 && s[oldPos]==84)
			{
				s[newPos]=84;
				s[oldPos]=32;
				player=0;
			}
			else
			{
				printf("\nNot valid\n");
			}
		}
		
		if (s[5]!=' ')
		{
			on=0;
		}
	}
	return 0;
}


int goat_mcheck(int old,int news)
{
	if ((news-old)%2 == 0)
	{	return 1;	}
	else
	{	return 0;	}
}


int tiger_mcheck(int old, int news)
{
	if ((news-old)%2 == 0)
	{
		return 1;	
	}
		
	else
	{
		return 0;	
	}
}

char isPiece(char s[], int pos)
{
	if (s[pos]=='G')
	{
		return 'G';
	}
	else if (s[pos]=='T')
	{
		return 'T';
	}
	else
	{
		return ' ';
	}
}
