#include <stdio.h>


int my_strcmp(char *str1, char *str2)
{
        int i, j, num1, num2;
        for (i = 0; str1[i]; i++)
        {
                //printf("%c %c\n", str1[i], str2[i]);
                if (str1[i] > 47 && str1[i] < 58 && str2[i] > 47 && str2[i] < 58)
                {
                        for (j = i, num1=0, num2 = 0 ; str1[j] != '.' && str1[j] && str2[j] ; j++)
                        {
                                num1 = num1 * 10 + str1[j] - 48;
                                num2 = num2 * 10 + str2[j] - 48;
                        }
                        //printf("%d %d %d\n", num1, num2, j);
                        if (!str1[j] != !str2[j])
                                return str1[j] - str2[j];
                        if (num1 != num2)
                                return num1-num2;
                        i = j;
                }
        }
        return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("Usage: a.out num1 num2\n");
		return 0;
	}

        int ret = my_strcmp(argv[1], argv[2]);

        if (ret < 0)
                printf("%s is less than %s\n", argv[1], argv[2]);
        else if (ret > 0)
                printf("%s is greater than %s\n", argv[1], argv[2]);
        else
                printf("%s is equal to %s\n", argv[1], argv[2]);
}

