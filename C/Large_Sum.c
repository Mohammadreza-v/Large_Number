#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

int chrtoint(char a) { // function for convert char to int
	int i;
	for (i = 48; i <= 57; i++)
	if (toascii(i)==a) return i-48;
	return 0;
}

char *strrevv(char *str) { // Function for reverse string
	char *p1, *p2;
	if (! str || ! *str) {
		return str;
	}
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

int main () {
	char str1[2048], str2[2048], str_temp[2048];
	char result[2050];
	int len1, len2, i, sum = 0, n = 0, num = 0, test = 0;

	FILE * fp, *resFp;
	fp = fopen ("input.txt", "r");
	resFp = fopen("Sum.txt", "a+");
	fscanf(fp, "%s\n%s\n", str1, str2);

	if(strlen(str1) < strlen(str2)) { // Adjust the number length
		strcpy(str_temp, str1);
		strcpy(str1, str2);
		strcpy(str2, str_temp);
	}

	strrevv(str1); // reverse string
	strrevv(str2);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for(i = 0; i < len1; i++) { // sum of two very large numbers
		if (i <= len2 - 1) {
			sum = chrtoint(str1[i]) + chrtoint(str2[i]) + num;
		}
		else if(i > len2 - 1){
			sum = chrtoint(str1[i]) + num;
		}

		result[i] = sum % 10;
		num = sum / 10; // sum > 9
		n++;
	}

	fprintf(resFp, "\n######################\nSum is :\n");

	for(int j=n-1; j >= 0; j--) { // print result and save into file
		printf("%d", result[j]);
		fprintf(resFp, "%d", result[j]);
	}

	rewind(resFp);
	fclose(resFp);
	fclose(fp);

	return 0;

}
