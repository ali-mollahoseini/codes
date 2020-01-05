#include <stdio.h>
#include <math.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
//=====================================
char myarray[1100];
int size = 0;
//------------------------------------
void shiftright(char myarray[], int size, int shiftBy)
{
	if (shiftBy > size) {
		shiftBy = shiftBy - size;
	}
	if (size == 1) {
		//do nothing
	}
	else {
		char temp;
		int i = 0;
		//for loop to print the array with indexes moved up (to the right) --> by 2
		for (int j = 1; j <= shiftBy; j++) {
			temp = myarray[size];
			for ( i = 0; i < size; i++)
			{
				myarray[size-i] = myarray[size-i-1];
				if (i == size-1 ) { myarray[0] = temp; }

			}
		}

	}
}
//=====================================
//=====================================
void shiftleft(char myarray[], int size, int shiftBy)
{
	if (shiftBy > size) {
		shiftBy = shiftBy - size;
	}
	if (size == 1) {
		//do nothing
	}
	else {
		char temp;
		//for loop to print the array with indexes moved up (to the right) --> by 2
		for (int j = 1; j <= shiftBy; j++) {
			temp = myarray[0];
			for (int i = 0; i<size; i++)
			{
				myarray[i] = myarray[i+1];
				if (i == size - 1) { myarray[size] = temp; }
			}
		}

	}
}
//=======================================
void extend(char a[], int n) {
	for (int i = 1; i <= n; i++) {
		myarray[size + i] = '*';
	}
	myarray[size+n+1] = '\0';


}
//=======================================
void shrink(char a[], int n) {
	if (n > size + 1) {
		//myarray[0] = 0x0;
		myarray[0] = '\0';
	}
	else
	myarray[size - n + 1] = '\0';
}
//=======================================
void reverse(char arr[],int start,int end) {


		while (start < end)
		{
			char temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++;
			end--;
		}

}
//=======================================
void put(char a[], int z,char b) {
	z--;
	myarray[z] = b;

}
//======================================
void print() {
	puts(myarray);
}
//=======================================
void dsize() {
	size = 0;
	for (int i = 0;; i++) {
		if (myarray[i] == '\0') { break; }
		size++;
	}
	size--;
}
//=======================================



int main()
{
	char command[15];
	int num = 0,n;
	char q;
	fgets(myarray, 1100, stdin);
	n = strlen(myarray);
	myarray[n - 1] = '\0';
	n--;


	 while (scanf("%s", command) && strcmp(command, "EXIT")) {
		 //scanf("%s", &command);
		 //fgets(command, 25, stdin);
		 if (!strcmp(command, "SHIFT-R")) {
			 dsize();

			 //printf("%d", size);
			 scanf("%d", &num);
			 shiftright(myarray, size, num);

		 }
		 else if (!strcmp(command, "SHIFT-L")) {
			 dsize();

			 scanf("%d", &num);
			 shiftleft(myarray, size, num);

		 }
		 else if (!strcmp(command, "EXTEND")) {
			 dsize();

			 scanf("%d", &num);
			 extend(myarray,num);

		 }
		 else if (!strcmp(command, "SHRINK")) {
			 dsize();

			 scanf("%d", &num);
			 shrink(myarray,num);

		 }
		 else if (!strcmp(command, "REVERSE")) {
			 dsize();
			 reverse(myarray,0,size);

		 }
		 else if (!strcmp(command, "PUT")) {
			 scanf("%d",&num);
			 scanf("%c",&q);
			 scanf("%c", &q);
			 put(myarray,num,q);

		 }
		 else if (!strcmp(command, "PRINT")) {
			 printf("%s\n", myarray);
		 }

		 else if (!strcmp(command, "EXIT")) {
			 break;
		 }
		 for (int i = 0; i < 15; i++) {
			 command[i] = '\0';
		 }
	 }
	//puts(myarray);




	return 0;
}


