#include <stdio.h>
int check_valid(int old,int news);
void main()
{
	int old;
	int news;
	scanf("%d %d",&old,&news);
	printf("%d",check_valid(old,news));	
}
int check_valid(int old , int news)
{
	unsigned char pos[25];
	int mod_new=0;
	int flag=0;
	//storing positions
	pos[0]=034;
	pos[1]=025;
	pos[2]=037;
	pos[3]=025;
	pos[4]=007;
	pos[5]=0124;
	pos[6]=0377;
	pos[7]=0125;
	pos[8]=0377;
	pos[9]=0105;
	pos[10]=0174;
	pos[11]=0125;
	pos[12]=0377;
	pos[13]=0125;
	pos[14]=0307;
	pos[15]=0124;
	pos[16]=0377;
	pos[17]=0125;
	pos[18]=0377;
	pos[19]=0105;
	pos[20]=0160;
	pos[21]=0121;
	pos[22]=0361;
	pos[23]=0121;
	pos[24]=0301;
	
	
	//modifying new value
	switch (old-news)
	{
		case 6:
		{	
			mod_new=1;
			return (pos[old-1] & 128?1:0);
			break;
		}
		case 5:
		{
			mod_new=2;
			return (pos[old-1] & 64?1:0);
			break;
		}	
		case 4:
		{
			mod_new=3;
			return (pos[old-1] & 32?1:0);
			break;
		}
		case -1:
		{
			mod_new=4;
			return (pos[old-1] & 16?1:0);
			break;
		}
		case -6:
		{
			mod_new=5;
			return (pos[old-1] & 8?1:0);
			break;
		}
		case -5:
		{
			mod_new=6;
			return (pos[old-1] & 4?1:0);
			break;
		}
		case -4:
		{
			mod_new=7;
			return (pos[old-1] & 2?1:0);
			break;
		}
		case 1:
		{
			mod_new=8;
			return (pos[old-1] & 1?1:0);
			break;
		}
		
		default:
			{
			return 0;
			break;
			}
	}
	
	
}

	
	
	
	
	
