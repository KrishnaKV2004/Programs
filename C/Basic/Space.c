#include <stdio.h>
#include <string.h>

void main()
{
	int c=0;
	char str[50];

	printf("\nEnter String : ");
	fgets(str,50,stdin);

	for (int i=0; str[i]!='\0'; i++)
	{
		if (str[i]==' ')
		{
			c++;
		}
	}
	printf("\nSpaces >---> %d",c);
}