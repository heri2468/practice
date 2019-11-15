#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>
//#include<bios.h>

#define RETURNTIME 15

char catagories[][15]={"DAL","SABJI","CHAPATI","SAMBHAR","RICE","IDLI"};
void returnfunc(void);
void mainmenu(void);
void addfood(void);
void deletefood(void);
void editfood(void);
void searchfood(void);
void viewfood(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
//void show_mouse(void);
void Password();
void loaderanim();

//list of global files that can be acceed form anywhere in program
FILE *fp,*ft,*fs;


COORD coord = {0, 0};
//list of global variable
int s;
char findfood;
char password[10]={"ritesh"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct food
{
int id;
char name[20];
int quantity;
int count;
char *cat;
};
struct food a;
int main()
{
Password();
getch();
return 0;

}
void mainmenu()
{
//loaderanim();
system("cls");
//textbackground(13);
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
//    show_mouse();
gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Add FOOD   ");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Delete FOOD");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Search FOOD");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. View FOOD list");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. Edit FOOD's Record");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. Close Application");
gotoxy(20,19);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,20);
printf("Enter your choice:");
switch(getch())
{
case '1':
addfood();
break;
case '2':
deletefood();
break;
case '3':
searchfood();
break;
case '4':
viewfood();
break;
case '5':
editfood();
break;
case '6':
{
system("cls");
gotoxy(16,3);
printf("\tHostel Food Management System");
gotoxy(16,4);
printf("\tOpen Ended  in C");
gotoxy(16,5);
printf("\tis brought to you by");
gotoxy(16,10);
printf("\nRITESH\nRISHIKESH\nNISHANT\nPARIKSHITH\n");
gotoxy(10,14);
printf("\n\nExiting in 3 second...........>");
//flushall();
Sleep(3000);
exit(0);
}
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-enter correct option");
if(getch())
mainmenu();
}

}
}
void addfood(void)    //funtion that add food
{
system("cls");
gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. DAL");
gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. SABJI");
gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. CHAPATI");
gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 4. SAMBHAR");
gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. RICE");
gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. IDLI");
gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
gotoxy(20,21);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,22);
printf("Enter your choice:");
scanf("%d",&s);
if(s==7)

mainmenu() ;
system("cls");
fp=fopen("food.txt","a+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
gotoxy(21,14);
printf("The record is sucessfully saved");
gotoxy(21,15);
printf("Save any more?(Y / N):");
if(getch()=='n')
mainmenu();
else
system("cls");
addfood();
}
}
void deletefood()    //function that delete items from file fp
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
gotoxy(10,5);
printf("Enter the Food ID to  delete:");
scanf("%d",&d);
fp=fopen("food.txt","r+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

gotoxy(10,7);
printf("The food record is available");
gotoxy(10,8);
printf("food name is %s",a.name);
findfood='t';
}
}
if(findfood!='t')
{
gotoxy(10,10);
printf("No record is found modify the search");
if(getch())
mainmenu();
}
if(findfood=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):");
if(getch()=='y')
{
ft=fopen("test.txt","w+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("food.txt");
rename("test.txt","food.txt"); //copy all item from temporary file to fp except that
fp=fopen("food.txt","r+");    //we want to delete
if(findfood=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted");
gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
gotoxy(10,15);
mainmenu();
}
void searchfood()
{
system("cls");
int d;
printf("*****************************Search Food*********************************");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Search By ID");
gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Search By Name");
gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("food.txt","r+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Food By Id****");
gotoxy(20,5);
printf("Enter the food id:");
scanf("%d",&d);
gotoxy(20,7);
printf("Searching........");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
Sleep(2);
gotoxy(20,7);
printf("The Food is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Qantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
findfood='t';
}

}
if(findfood!='t')  //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchfood();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");
gotoxy(25,4);
printf("****Search Food By Name****");
gotoxy(20,5);
printf("Enter Food Name:");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Food is available");
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
d++;
}

}
if(d==0)
{
gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)");
if(getch()=='y')
searchfood();
else
mainmenu();
break;
}
default :
getch();
searchfood();
}
fclose(fp);
}

void viewfood(void)  //show the list of food persists in hostel
{
int i=0,j;
system("cls");
gotoxy(1,1);
printf("********************************Hostel List*****************************");
gotoxy(2,2);
printf(" CATEGORY     ID    FOOD NAME     QTY  ");
j=4;
fp=fopen("Food.txt","r+");
while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j);
printf("%s",a.cat);
gotoxy(5,j);
printf("%d",a.id);
gotoxy(7,j);
printf("%s",a.name);
gotoxy(9,j);
printf("%d",a.quantity);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Food =%d",i);
fclose(fp);
gotoxy(35,25);
returnfunc();
}
void editfood(void)  //edit information about food
{
system("cls");
int c=0;
int d;
gotoxy(20,4);
printf("****Edit Food Section****");
char another='y';
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Food Id to be edited:");
scanf("%d",&d);
fp=fopen("food.txt","r+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("The food is availble");
gotoxy(15,8);
printf("The food ID:%d",a.id);
gotoxy(15,9);
printf("Enter new food:");scanf("%s",a.name);
gotoxy(15,10);
printf("Enter new quantity:");scanf("%d",&a.quantity);
gotoxy(15,11);
printf("The record is modified");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}
}
gotoxy(15,16);
printf("Modify another Record?(Y/N)");
fflush(stdin);
another=getch() ;
}
returnfunc();
}
void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2");gotoxy(46,11);printf("\xB2");
gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category of Food:");
gotoxy(31,5);
printf("%s",catagories[s-1]);
gotoxy(21,6);
printf("Food ID:\t");
gotoxy(30,6);
scanf("%d",&t);
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aThe food id already exists\a");
getch();
mainmenu();
return 0;
}
a.id=t;
gotoxy(21,7);
printf("FOOD Name:");gotoxy(33,7);
scanf("%s",a.name);
gotoxy(21,8);
printf("Quantity:");gotoxy(31,9);
scanf("%d",&a.quantity);
return 1;
}
int checkid(int t)  //check whether the food is available or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if food is available
return 1; //return 1 if  not
}

void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;
//textbackground(WHITE);
//textcolor(RED);
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
//textcolor(BLINK);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
mainmenu();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}
