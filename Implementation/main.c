/********************************************
Project Name: PASTRY SHOP CENTRAL SYSTEM
Author: NIRMAL KUMAR D R
Source filename:main.c
Date: 21th-Nov-2021.
*********************************************/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ENTER 13
#define BKSP 8
#define SPACE 32
#define TAB 9

void setcolor(int ForgC)
{ WORD wColor;
HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
{
	wColor=(csbi.wAttributes & 0xF0)+(ForgC & 0x0F);

	SetConsoleTextAttribute(hStdOut,wColor);
	
}
}


struct item
{
	char productname[40],productcomp[40],c;
	int productid;
	int price;
	int Qnt;
}st;

void wel_come(void);
void title(void);
void login();
void menu(void);
void title(void);
void deleteproduct(void);
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void add_item();
void read_item();
void search_item();
void edit_item();
void main(void)

{
wel_come(); 
login(); 
}



void wel_come(void)

{
	setcolor(11);
	time_t t;
	time(&t);
	printf("                                                                                                         \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t**********************************\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t*\t       WELCOME TO \t *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t*\tPastry Shop Central System\t *\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t**********************************\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t          RS Puram, CBE\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t         8734534895\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t    \"WE BELIEVE IN QUALITY\"\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t\t|\n");

	printf("---------------------------------------------------------------------------------------------------------\n");
	 
getch();
system("cls");
}

void login()
{

	int valid=0;
	int a=0, i=0;
	char username[20];
	char password[20];
	char uname[20]="nirmal";
	char pword[20]="kumar";
	
	
		system("cls");
	gotoxy(15,1);
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LOGIN PAGE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	do
	{
		
	
		printf("\n			Please Enter Your Valid Username & Password.");
		printf("\n\n					Username:");
		scanf("%s",username);
		
		printf("\n			    		Password:");

		scanf("%s", password);
		
		if (strcmp(username,uname)==0&&strcmp(password,pword)==0)
		{
			printf("\n			LOGGED INTO SYSTEM! PRESS ANY KEY TO MAIN MENU!");
			getch();
			menu();
			break;
		}
		else
		{
			printf("\n		 			Invalid!Try Again");
			getch();
			a++;
		
		}
	} 
	

	
	while(a<=2);	
	if(a>2){
		printf("\nSorry,You are the wrong User.");
		getch();
		exit(0);
	}
	
	
}

void menu(void)
{
	int choice;
	system("cls");
	main:
	printf("<<<<<<<<<<<<<<<<<<<<<<<<Welcome To Product Detail Management System>>>>>>>>>>>>>>>>>>>>>>>");
	printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n\t\tPress <1> Add Products");
	printf("\n\t\tPress <2> Delete Products");
	printf("\n\t\tPress <3> Search Products");
	printf("\n\t\tPress <4> Read Items");
	printf("\n\t\tPress <5> Edit Items");
	printf("\n\t\tPress <6> Exit!");	
	
	printf("\n\t\tEnter your choice[1-6]");
	scanf("%i", &choice);
	
	system("cls");
	
	switch(choice)	
	{
		case 1:
			add_item();
			break;
		case 2:
			deleteproduct();
			break;
		case 3:
		search_item();
			break;
		case 4:
		read_item();
			break;	
		case 5:
			edit_item();
			break;
		case 6:
		printf("System Exit");
		exit(0);
		break;
			
		
		default:
		printf("Invalid Choice! System Exit\n");
			getch();
	}
	
}

void add_item()
{
	int index, valid;
	char c;
	int a=0;

	FILE *fp;
	

	do
	{
		system("cls");
		printf("<<<<<<<<<<<<<<Enter Product Detail>>>>>>>>>>>>>");
		int ID;
		fp = fopen("NextFile.dat","a+");
		
		if((fp = fopen("NextFile.dat","a+"))!=NULL)
		{
			I:
			printf("\nProduct Code\t :");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
			{
				
				if(ID == st.productid)
				{
					printf("\n\tTHE PRODUCT CODE ALREADY EXIST.\n");
					goto I;
				}
			}
			st.productid = ID;
		}
		else
		{
			printf("\nProduct Code\t :");
			scanf("%i",&st.productid);
		}
		
		do
		{
		
			
			fflush(stdin);
			printf("\nProduct Name\t :");
			gets(st.productname); 
			st.productname[0]=toupper(st.productname[0]);
			
			for (index=0; index<strlen(st.productname); ++index)
			{	
				if(isalpha(st.productname[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n Name contain invalid character. Please 'Enter' again");
				getch();
			
				
			}
		}while(!valid);	
		

		
			do
		{
			char productcomp[40];
			fflush(stdin);
			printf("\nProduct Company\t :");
			gets(st.productcomp); 
			st.productcomp[0]=toupper(st.productcomp[0]);
			
			for (index=0; index<strlen(st.productcomp); ++index)
			{	
				if(isalpha(st.productcomp[index]))
					valid = 1;
				else
				{
					valid = 0;
					break;
				}
			}
			if (!valid)
			{
				printf("\n Name contain invalid character. Please 'Enter' again");
				getch();
			
				
			}
		}while(!valid);
		
		
		do
			{
				printf("\nPrice [10-5000]Rupees:");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tYou Cannot Enter the price limit [10-5000].Re-Enter.");
				}
			}while(st.price<10 || st.price>5000);
			
				do
			{
				printf("\nQuantity [1-500]\t:");
				scanf("%i",&st.Qnt);
				if(st.Qnt<1 || st.Qnt>500)
				{
					printf("\n\tEnter Quantity[1-500] only.Re-Enter.");
				}
			}while(st.Qnt<1 || st.Qnt>500);
	
	
		
		fp=fopen("NextFile.dat","a");
		fprintf(fp,"\n%s %s %i %i %i", st.productname, st.productcomp,st.price, st.productid,st.Qnt);
		fclose(fp);
		printf("\nPress 'Enter' to add more item and any other key to go to main menu");
		
	}
	while((c = getch()) =='\r');
	menu();
}

void search_item()
{
	char target[40];
	int found=0;
	FILE *sfile;
	sfile=fopen("NextFile.dat","r");
	printf("\nEnter name to search:");
	fflush(stdin);
	gets(target);
	target[0]=toupper(target[0]);
	while (!feof(sfile) && found==0)
	{
		fscanf(sfile,"%s %s %i %i %i", st.productname, st.productcomp, &st.price, &st.productid,&st.Qnt);
		if(strcmp(target, st.productname)==0)
		{
			found=1;		
		}
	}
	
	if(found)
	{
		printf("\n Record found");
		printf("\nProduct Name\t\t:%s  \nProduct Company\t\t:%s \nProduct Price\t\t:%i \nProduct ID\t\t:%i \nProduct Quantity\t:%i", st.productname, st.productcomp, st.price, st.productid, st.Qnt);
	
	}
	else 
		printf("Noo Record found");
		fclose(sfile);
		printf("\nPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		menu();
		
}

void deleteproduct(void)
{
	char target[40]; 
	int found=0;
	FILE *sfile, *tfile;
	sfile=fopen("NextFile.dat","r");
	tfile=fopen("TempFile.dat","w+");
	printf("\n Enter name to Delete: ");
	fflush(stdin);
	scanf("%s",target);
	target[0]=toupper(target[0]);
	while (fscanf(sfile,"%s %s %i %i %i\n",st.productname,st.productcomp, &st.price,&st.productid,&st.Qnt)!=EOF)
	{
		if(strcmp(target,st.productname)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tfile,"%s %s %i %i %i\n", st.productname,st.productcomp, st.price,st.productid,st.Qnt);
		}
	}
			if(!found)
			{
				printf("\n Record not Found");
				getch();
				menu();
			}
			else
			{
				printf("\n Record deleted");	
			}
			fclose(sfile);
			fclose(tfile);
			remove("NextFile.dat");
			rename("TempFile.dat","NextFile.dat");
			
			printf("\nPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		menu();
}

void read_item()
{
	FILE *f;
	int i, q;
	if((f=fopen("NextFile.dat","r"))==NULL)
	{
	
		gotoxy(10,3);
		printf("NO RECORDS");
		printf("\n\t\tPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{
	
		gotoxy(0,5);
			for(i=0;i<100;i++)
		{
			printf("-");
		}
		gotoxy(5,6);
		printf("Product Name");
		gotoxy(25,6);
		printf("Product Price");
		gotoxy(40,6);
		printf("Product Company");
		gotoxy(60,6);
		printf("Product CODE");
		gotoxy(80,6);
		printf("Product Quantity\n");
		
		for(i=0;i<100;i++)
		{
			printf("-");
		}
		q=8;
		while(fscanf(f,"%s %s %i %i %i\n", st.productname,st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
		{
			gotoxy(5,q);
			printf("%s",st.productname);
			gotoxy(25,q);
			printf("%i",st.price);
			gotoxy(40,q);
			printf("%s",st.productcomp);
			gotoxy(60,q);
			printf("%i",st.productid);
			gotoxy(80,q);
			printf("%i",st.Qnt);
	
			q++;
		}
		printf("\n");
		for(i=0;i<100;i++)
			printf("-");
	}
	fclose(f);
	
	printf("\nPress any key to go to Main Menu!");
		
		getch();
		menu();
}

void edit_item()
{
	int index, valid;
	char target[40];
	FILE *fp, *rp;
	int a=0;
	int id;
	char edit;
	long int size=sizeof(st);
	if((fp=fopen("NextFile.dat","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		menu();
	}
	else
	{
		rp = fopen("TempFile.dat","a");
		system("cls");
		printf("Enter Product Code for edit:");
		scanf("%i",&id);
		fflush(stdin);
		while(fscanf(fp,"%s %s %i %i %i\n", st.productname,st.productcomp, &st.price, &st.productid,&st.Qnt)!=EOF)
		{
			if(id==st.productid)
			{
				
				a=1;
				printf("\n\t*****  Record Found  *****");
				printf("\nProduct Name\t\t: %s",st.productname);
				printf("\nProduct Company\t\t: %s",st.productcomp);
				printf("\nPrice\t\t\t: %i",st.price);
				printf("\nProduct Code\t\t: %i",st.productid);
				printf("\nProduct Quantity\t:%i",st.Qnt);
			
				printf("\n\n\t*** New Record ***");
			do
				{
					
					fflush(stdin);
					printf("\nNew Product Name\t\t: ");
					gets(st.productname); 
					st.productname[0]=toupper(st.productname[0]);
					
					for (index=0; index<strlen(st.productname); ++index)
					{	
						if(isalpha(st.productname[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();
					
						
					}
				}while(!valid);	
				
		
				
				do
				{
					char productcomp[40];
					fflush(stdin);
					printf("\nNew Product Company\t\t:");
					gets(st.productcomp); 
					st.productcomp[0]=toupper(st.productcomp[0]);
					
					for (index=0; index<strlen(st.productcomp); ++index)
					{	
						if(isalpha(st.productcomp[index]))
							valid = 1;
						else
						{
							valid = 0;
							break;
						}
					}
					if (!valid)
					{
						printf("\n Name contain invalid character. Please 'Enter' again");
						getch();
					
						
					}
				}while(!valid);
				
					do
			{
				printf("\nNew Price [10-5000]Rupees:");
				scanf("%i",&st.price);
				if(st.price<10 || st.price>5000)
				{
					printf("\n\tYou Cannot Enter the price limit [10-5000].Re-Enter.");
				}
			}while(st.price<10 || st.price>5000);
			
				printf("\nEnter New Product Code\t\t:");
				scanf("%i",&st.productid); 
				
				do
			{
				printf("\nNew Quantity [1-500]\t:");
				scanf("%i",&st.Qnt);
				if(st.Qnt<1 || st.Qnt>500)
				{
					printf("\n\tEnter New Quantity[1-500] only.Re-Enter.");
				}
			}while(st.Qnt<1 || st.Qnt>500);
				
				
				printf("Press 'y' to edit the existing record or any key to cancel...");
				edit=getche();
				if(edit=='y' || edit=='Y')
				{
					fprintf(rp,"%s %s %i %i %i\n", st.productname, st.productcomp, st.price, st.productid,st.Qnt);
					fflush(stdin);
					printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
				}
			}
			else
			{
				fprintf(rp,"%s %s %i %i %i\n", st.productname, st.productcomp, st.price, st.productid,st.Qnt);
				fflush(stdin);
			}
			
		}
		if(!a)
		{
			printf("\n\nTHIS PRODUCT DOESN'T EXIST!!!!");
		}
		fclose(rp);
		fclose(fp);
		remove("NextFile.dat");
		rename("TempFile.dat","NextFile.dat");
		getch();
	}
	menu();
}

  
