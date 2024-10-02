#include <stdio.h>
#include <string.h>

void daoCaChuoi(char *str);
void daoTungTu(char *str);


int main(void)
{
	char str[600]; 
	int a;
	snprintf(str, 600, "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's \
standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. \
It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. \
It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, \
and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
	scanf("%d",&a);
	if(a==0)
	{
		daoCaChuoi(str);
		printf("%s",str);
	}else if(a==1)
	{
		daoTungTu(str);
		printf("%s",str);
	}
	
	return 0;
}

void daoCaChuoi(char *str)
{
	int doDaiChuoi = strlen(str);
	int i = 0, j = doDaiChuoi - 1;
	char temp;
	// dao chuoi da cho
	while(i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	
	// Xoa khoang trang thua do khai bao chuoi du
	i = 0;
	j = 0;
	
	// Do xem khoang trang den dau
	while(str[i] == ' ')
	{
		i++;
	}
	
	// Don chuoi ve phia truoc
	while(str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
}

void daoTungTu(char *str)
{
	// them khoang trang vao cuoi chuoi
	str[strlen(str)] = ' ';
	char word[20];
	int count = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ')
		{
			word[count] = '\0';
			daoCaChuoi(word);
			for(int j = 0; j < count; j++)
			{
				str[i - count + j] = word[j];
			}
			count = 0;
			continue;
		}
		
		word[count] = str[i];
		count++;
	}
	
}
