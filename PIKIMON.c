#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<dir.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dos.h>
#include<windows.h>
#include<io.h>
#include<windowsx.h>
#include<mmsystem.h>
#include<stdarg.h>
char pw[21], pw1[21], pwp[21];

int mpcol[8] = {13,//charactor 
				13,
				14,};

int fig[6][3] = { //fight data //hp,atk,amr
	{8, 8, 6},  //bat
	{6, 9, 7},  //gold
	{15, 6, 8}, //wood
	{11, 7, 6}, //water
	{7, 11, 5}, //fire
	{10, 6, 15},//rock
	};
/*
		bat
			mhp[i]=lv[i]*8;
			atk[i]=lv[i]*8;
			amr[i]=lv[i]*6;
		gold
			mhp[i]=lv[i]*6;
			atk[i]=lv[i]*9;
			amr[i]=lv[i]*7;
		wood
			mhp[i]=lv[i]*15;
			atk[i]=lv[i]*6;
			amr[i]=lv[i]*8;
		water
			mhp[i]=lv[i]*11;
			atk[i]=lv[i]*7;
			amr[i]=lv[i]*6;
		fire
			mhp[i]=lv[i]*7;
			atk[i]=lv[i]*11;
			amr[i]=lv[i]*5;
		rock
			mhp[i]=lv[i]*10;
			atk[i]=lv[i]*6;
			amr[i]=lv[i]*15;
	*/
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
      	wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
     	SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void delay(int milli_seconds){ 
    clock_t start_time = clock();  
    while (clock() < start_time + milli_seconds) 
        ;
}

void printf_xy(int x, int y, const char * format, ...){//print with xy
	gotoxy(x, y);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void printf_c(int c, const char * format, ...){//print with color
	color(c);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void printf_cxy(int c, int x, int y, const char * format, ...){//with xy and color
	color(c);
	gotoxy(x, y);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}

void clear(char a){
	color(10);
	int i;
	if(a == 'b'){
		printf_xy(0, 17, "|              |              |              |              |A.PIKIMON| B.CATCH|");
				printf("|              |              |              |              |         |        |");
				printf("|              |              |              |              |=========|========|");
				printf("|              |              |              |              | C.ITEM  |D.ESCAPE|");
				printf("|              |              |              |              |         |        |");
	}else if(a == 1){
		printf_xy(0, 16, "                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
		printf("                                                                                ");
	}else if(a == 2){
		printf_xy(3, 19, "                                                                      ");
		printf_xy(3, 21, "                                                                      ");
	}else if(a == 3){
		for(i = 0; i < 12; i++){
			printf_xy(0, 5 + i, "                                                                                ");
		}
	}else if (a == 4){
		printf_xy(0, 5, "                                                                                ");
	}else if(a == 5){
		for(i = 0;i < 10; i++){
			printf_xy(40, 5 + i, "                                        ");
		}
	}else if(a == 6){
		for(i = 0; i < 10; i++){
			printf_xy(0, 5 + i, "                                        ");
		}
	}
	gotoxy(0, 0);
	gotoxy(1, 1);
}

void printf_plot(char a[10000], char b[10000], int c, const char * format, ...) {
	clear(2);
	color(10);
	gotoxy(3, 19);
	va_list args;
	va_start(args, format);
	if(c == 1){
		vprintf(format, args);
	}
	print_plot(10, a);
	if(c == 2){
		vprintf(format, args);
	}
	gotoxy(3, 21);
	if(c == 3){
		vprintf(format, args);
	}
	print_plot(10, b);
	if(c == 4){		
		vprintf(format, args);
	}
	va_end(args);
	if(c != 5){
		gotoxy(50, 23);
		printf("Press any key to continue...");
		getch();
	}
}

void print_ui(int a){
	int i;
	if(a == 0){
		printf_c(10, "\n|==============================================================================|");
		for(i = 17; i < 25; i++){
			printf_xy(0, i, "|");
			printf_xy(79, i, "|");
		}
		printf_xy(0, 24, "|==============================================================================");
		gotoxy(0, 0);
	}else if(a < 14){
		printf_c(10, "________________________________________________________________________________\n");
		color(11);
		delay(25);
		if(a == 1){
			printf("\n\n                  Please login or register for playing pikimon.\n\n\n");
		}else if(a == 2){
			printf("\n\n              Please enter the number 1 or 2 for login or register.\n\n\n");
		}else if(a == 3){
			printf("\n\n                                    Login\n\n\n");
		}else if(a == 4){
			printf("\n\n                                  register\n\n\n");
		}else if(a == 5){
			printf("\n                                 Admin Start\n\n");
		}else if(a == 6){
			printf("\n                                 Check password\n\n");
		}else if(a == 7){
			printf("\n                                 Delete user\n\n");
		}else if(a == 8){
			printf("\n                                 Edit Password\n\n");
		}else if(a == 9){
			printf("\n\n                                 Change Password\n\n\n");
		}else if(a == 10){
			printf("\n\n                                   PIKIMON\n\n");
		}else if(a == 11){
			printf_c(12, "                                    FIGHT\n");
		}else if(a == 12){
			printf("\n\n                                    Start\n\n\n");
		}else if(a == 13){
			printf("\n                                     Bag\n");
		}
		delay(25);
		printf_c(10, "________________________________________________________________________________\n");
		delay(50);
	}else if(a == 14){
		printf_cxy(10, 0, 16, "|==============================================================================|");
		printf("|              |              |              |              |A.PIKIMON| B.CATCH|");
		printf("|   1.ATTACK   |   2.ATTACK   |   3.ATTACK   |   4.ATTACK   |         |        |");
		printf("|              |              |              |              |=========|========|");
		printf("|              |              |              |              | C.ITEM  |D.ESCAPE|");
		printf("|              |              |              |              |         |        |");
		printf("|==============================================================================|");
	}
}

void load(int a){
	system("cls");
	int i = 0,j,b = 0;
	char c;
	printf("________________________________________________________________________________\n");
	if(a == 1)
		printf("                                Login Sucess!\n\n");
	else if(a == 2)
		printf("                              Register Sucess!\n\n");
	printf_c(12, "\n\n              __     "); printf_c(11, "           "); printf_c(14, "                "); printf_c(13, "    ____");
	printf_c(12, "\n             /  \\   []"); printf_c(11, "  |  /  []"); printf_c(14, "  |\\          /|"); printf_c(13, "   /    \\"); printf_c(9, "   |\\     |");
	printf_c(12, "\n            |    |    "); printf_c(11, "  | /     ");  printf_c(14, "  | \\        / | "); printf_c(13, " |      |"); printf_c(9, "  | \\    |");
	printf_c(12, "\n            |    |  ||"); printf_c(11, "  |/    ||");  printf_c(14, "  |  \\      /  | "); printf_c(13, " |      |"); printf_c(9, "  |  \\   |");
	printf_c(12, "\n            |___/   ||"); printf_c(11, "  |\\    ||"); printf_c(14, "  |   \\    /   |"); printf_c(13, "  |      |"); printf_c(9, "  |   \\  |");
	printf_c(12, "\n            |       ||"); printf_c(11, "  | \\   ||"); printf_c(14, "  |    \\  /    |"); printf_c(13, "  |      |"); printf_c(9, "  |    \\ |");
	printf_c(12, "\n            |       ||"); printf_c(11, "  |  \\  ||"); printf_c(14, "  |     \\/     |"); printf_c(13, "   \\____/"); printf_c(9, "   |     \\|");
			printf_c(10, "\n\n                                 loading ......\n");
			printf_c(13, "\n\n              --------------------------------------------------%d%%\n\n\n\n",i);
			printf_c(10, "                                                                      Ver.0.3.1\n");
			printf("________________________________________________________________________________\n");
	int y = 15;
	if(a != 0)
		y = y + 2;
	for(i = 0; i <= 100; i++){
		if(i % 2 == 0)
			b++;
 	printf_xy(13 + b, y,  ">");
 	printf_cxy(11, 64, y, "%d%%", i);
	delay(10);
	if (kbhit() == 1){
        c = getch(); 
        if (c == 13) 
        	break;
        }
	}
	color(10);
	system("cls");
}

int welcome(){
	printf("________________________________________________________________________________\n");
	printf_c(12, "\n\n              __     "); printf_c(11, "           "); printf_c(14, "                "); printf_c(13, "    ____");			                           //________________________________________________________________________________
	delay(300);                                                                                                                                                            //
	printf_c(12, "\n             /  \\   []"); printf_c(11, "  |  /  []"); printf_c(14, "  |\\          /|"); printf_c(13, "   /    \\"); printf_c(9, "   |\\     |");     //              __                                    ____
	delay(250);                                                                                                                                                            //             /  \   []  |  /  []  |\          /|   /    \   |\     |
	printf_c(12, "\n            |    |    "); printf_c(11, "  | /     "); printf_c(14, "  | \\        / | "); printf_c(13, " |      |"); printf_c(9, "  | \\    |");       //            |    |      | /       | \        / |  |      |  | \    |
	delay(100);                                                                                                                                                            //            |    |  ||  |/    ||  |  \      /  |  |      |  |  \   |
	printf_c(12, "\n            |    |  ||"); printf_c(11, "  |/    ||"); printf_c(14, "  |  \\      /  | "); printf_c(13, " |      |"); printf_c(9, "  |  \\   |");       //            |___/   ||  |\    ||  |   \    /   |  |      |  |   \  |
	delay(50);                                                                                                                                                             //            |       ||  | \   ||  |    \  /    |  |      |  |    \ |
	printf_c(12, "\n            |___/   ||"); printf_c(11, "  |\\    ||"); printf_c(14, "  |   \\    /   |"); printf_c(13, "  |      |"); printf_c(9, "  |   \\  |");      //            |       ||  |  \  ||  |     \/     |   \____/   |     \|
	delay(50);                                                                                                                                                             //
	printf_c(12, "\n            |       ||"); printf_c(11, "  | \\   ||"); printf_c(14, "  |    \\  /    |"); printf_c(13, "  |      |"); printf_c(9, "  |    \\ |");      //
	delay(50);                                                                                                                                                             //                                welcome to my game!
	printf_c(12, "\n            |       ||"); printf_c(11, "  |  \\  ||"); printf_c(14, "  |     \\/     |"); printf_c(13, "   \\____/"); printf_c(9, "   |     \\|");     //                                       I am
	printf_c(10, "\n\n\n                              welcome to my game!\n\n");                                                                                           //                                     rickyho.
	delay(200);                                                                                                                                                            //
	printf("                                     I ");                                                                                                                     //
	delay(50);                                                                                                                                                             //                                                                          Ver.0.1
	printf("am\n");                                                                                                                                                        //
	delay(200);    	                                                                                                                                                       //________________________________________________________________________________
	printf("                                   rickyho.");                                                                                                                 //                         press any key to continue ......
	delay(50);
	printf("\n\n\n                                                                      Ver.0.3.1");
	printf("\n________________________________________________________________________________\n");
	printf("                        press any key to continue ......");
	getch();
	system("cls");
	return login_system(1);
}

int login_system(int b){
	print_ui(b);
	printf("Enter the number for login or register:");
	delay(50);
	printf("\n\n1.Login\n\n");
	delay(50);
	printf("2.Register\n\n");
	delay(50);
	printf("3.exit\n");
	char a[2];
	scanf("%s",a);
	if(a[0]-'0' == 1&&a[1] == '\0'){ 
		system("cls");
		return login(0);
	} 
	else if(a[0] - '0' == 2 && a[1] == '\0'){
		system("cls");
   		return Register(0);
	} 
	else if(a[0]-'0' == 3 && a[1] == '\0'){
		system("cls");
   		exit(0);
	}
	else {
		system("cls");
		delay(25);
		return login_system(2);
	}
}

int login(int e){
	print_ui(3);
	if(e == 1)
		printf("No this ID, please enter your ID one more time or enter 0 to register\n");
	else if(e == 2)
		printf("Wrong password, please enter your ID and password again\nPlease enter your ID:\n");
	else
		printf("Please enter your user ID or enter 0 to register:\n");
	char a[11], b[16], f[1000]= {".\\userdata\\"};
	scanf("%s", a);
	if(a[0] == '0' && a[1] == '\0'){
		system("cls");
		return Register(0, 0);
		}
	strcat(f, a);
	strcat(f, "\\password.txt");
	FILE*fp;
	fp = fopen(f, "r");
	if(fp == NULL){
		fclose(fp);
		system("cls");
		return login(1);
	}
	fscanf(fp, "%s", b);
	fclose(fp);
	delay(25);
	password(0, 0);
	int d = strcmp(b, pw);
	if(d == 0){
		system("cls");
		if(strcmp(a, "admin") == 0){
			return admin_start(a, 0);
		}
		load(1);
		return start(a, 0); 
	}else{
		system("cls");
		return login(2);
	}
}

int password(int b, int a){
	system("cls");
	if(b == 0)
		print_ui(3);
	else
		print_ui(4);
 	if(b == 0 || b == 1)
		printf("Please enter your user password:\n");
	else 
		printf("Please enter your user password again:\n");
	int i;
	for(i = 0; i < a; i++){
		printf("*");
	}
	if(b == 0 || b == 1){
		while(pw[a] != 13){
		pw[a] = getch();
		if(pw[a] != 8 && pw[a] != 13){
			printf("*");
			a++;
		}else if(pw[a] == 8 && a != 0){
			a--;
			printf("\b \b");
		}else if(pw[a] == 13){
			pw[a] = '\0';
			return 0;
		}
		}
	}else {
		while(pw1[a] != 13){
		pw1[a] = getch();
		if(pw1[a] != 8 && pw1[a] != 13){
			printf("*");
			a++;
		}else if(pw1[a] == 8 && a != 0){
			a--;
			printf("\b \b");
		}else if(pw1[a] == 13){
			pw1[a] = '\0';
			return 0;
		}
		}
	}
}

int admin_start(char a[], int c){
	char b[2];
	print_ui(5);
	printf("1.Continue game\n\n");
	delay(25);
	printf("2.Change password\n\n");
	delay(25);
	printf("3.Delete user\n\n");
	delay(25);
	printf("4.Check password\n\n");
	delay(25);
	printf("5.Version\n\n");
	delay(25);
	printf("6.Logout\n\n");
	delay(25);
	printf("7.Exit\n\n");
	printf("Enter number to action:\n");
	scanf("%s", b);
	if(b[0] - '0' == 1 && b[1] == '\0'){
		system("cls");
	system("COLOR 07");
		return position(a);
	}
	if(b[0] - '0' == 2 && b[1] == '\0'){
		system("cls");
		return admin_password(0, 0);
	}
	if(b[0] - '0' == 3 && b[1] == '\0'){
		system("cls");
		return delete_user(0);
	}
	if(b[0] - '0' == 4 && b[1] == '\0'){
		system("cls");
		return check(0);
	}
	if(b[0] - '0' == 5 && b[1] == '\0'){
		system("cls");
		return version(a);
	}
	if(b[0] - '0' == 6 && b[1] == '\0'){
		system("cls");
		printf("                                   Logout Success!\n");
		return welcome();
	}
	if(b[0] - '0' == 7 && b[1] == '\0'){
		exit(0);
	}
	system("cls");
	return admin_start(a, 0);
}

int check(int c){
	print_ui(6);
	char d[15], a[21], f[100]= {".\\userdata\\"};; 
	if(c == 0)
		printf("Please enter the user id that you want to check or press 0 to back admin start\n");
	else 
		printf("No this id, Please enter the user id again or press 0 to back admin start\n");
	scanf("%s", d);
	if(d[0] == '0' && d[1] == '\0'){
		system("cls");
	return admin_start("admin", 0);
		}
	FILE*fp;
	strcat(f, d);
	strcat(f, "\\password.txt");
	fp = fopen(f, "r");
	if(fp == NULL){
		fclose(fp);
		system("cls");
		return check(1);
	}
	fscanf(fp, "%s", a);
	fclose(fp);
	printf("%s's user password is: %s\n", d, a);
	printf_c(10, "\n________________________________________________________________________________\n");
	printf("                        press any key to continue ......");
	getch();
	system("cls");
	return admin_start("admin", 0); 
}

int delete_user(int c){
	char a[11], f[1000] = {".\\userdata\\"}, g[1000] = {".\\userdata\\"}, h[1000] = {".\\userdata\\"};
	print_ui(7);
	if(c == 0){
	printf("Please enter the user ID that you want to delete or enter 0 to return start\n");
	}else if(c == 1){
		printf("No this ID,please enter the user ID again that you want to delete or enter 0 to return start\n");
	}
	scanf("%s", a);
	if(a[0] == '0' && a[1] == '\0'){
		system("cls");
	return admin_start("admin", 0);
		}
	strcat(f, a);
	strcat(f, "\\password.txt");
	FILE*fp;
	fp = fopen(f, "r");
	if(fp == NULL){
		fclose(fp);
		system("cls");
		return delete_user(1);
	}
	fclose(fp);
	strcat(g, a);
	int d;
	chdir(g);
	remove("password.txt");
	remove("pikimon.txt");
	remove("position.txt");
	remove("data.txt");
	chdir("..");
	chdir("..");
	rmdir(g);
	printf("%s's account have deleted", a);
	getch();
	system("cls");
	return admin_start("admin", c);
}

int admin_password(int c,int z){
	char a[11], b[21], d[21], f[1000]={".\\userdata\\"}, g[21], h[21];
	print_ui(8);
	if(z == 1){
		printf("No this ID, please enter user ID one more time or enter 0 to return start page\n");
	}else if(c == 1){
		printf("New password is not the same.\nPlease enter the user id again or enter 0 to return start page.\n");
		delay(25);
	}else if(c == 2){
		printf("                 Your new password should be less then 20 character.\n");
		delay(25);
		printf("Please enter the user id again or enter 0 to return start page.\n");
		delay(25);
	}else printf("Please enter the id of the user or enter 0 to return start page\n");
	scanf("%s", a);
	if(a[0] == '0' && a[1] == '\0'){
		system("cls");
		return admin_start("admin", 0);
	}
	FILE*fp;
	strcat(f, a);
	strcat(f, "\\password.txt");
	fp = fopen(f, "r");
	if(fp == NULL){
		fclose(fp);
		system("cls");
		return admin_password(0, 1);
	}
	printf("\nPlease enter the user's' new password or enter 0 to return start page\n");
	scanf("%s", b);
	fp = fopen(f, "r");
	fscanf(fp, "%s", g);
	fclose(fp);
	if(b[0] == '0' && b[1] == '\0'){
		system("cls");
		return admin_start("admin", 0);
	}
	if(strlen(b) > 20){
		system("cls");
		return admin_password(2, 0);
	}
	printf("Please enter the user's' password again:\n");
	scanf("%s", d);
	int e = strcmp(b, d);
	if(e != 0){
		return  admin_password(1 , 0);
	}else {
	fp = fopen(f, "w");
	fprintf(fp, "%s", d);
	fclose(fp);
	system("cls");
	printf("                              Changed password!\n");
	return admin_start(a, 0);
	}
}

int money(char d[], int a){
	int i, b[100];
	char e[100] = {"./userdata/"};
	FILE*fp;
	strcat(e, d);
	strcat(e, "/data.txt");
	fp = fopen(e, "r");
	if(fp == NULL){
		printf("bug%s", e);
	}
	for(i = 0; i < 12; i++){
		fscanf(fp, "%d", &b[i]);
	}
	fclose(fp);
	if(b[0] + a <= 0 && a < 0)
		return 0;
	b[0] = b[0] + a;
	fp=fopen(e, "w");
	if(fp == NULL){
		printf("bug%s", e);
	}
	for(i = 0; i < 12; i++){
		fprintf(fp, "%d\n", b[i]);
	}
	fclose(fp);
	return 1;
}

int item(char d[], int a, int n){
	int i, b[100];
	char e[100] = {"./userdata/"};
	FILE*fp;
	strcat(e, d);
	strcat(e, "/data.txt");
	fp=fopen(e, "r");
	for(i = 0; i < 12; i++){
		fscanf(fp, "%d", b[i]);
	}
	fclose(fp);
	b[a] = b[a] + n;
	fp = fopen(e, "w");
	for(i = 0; i < 12; i++){
		fprintf(fp, "%d", b[i]);
	}
	fclose(fp);
}

int Register(int c){
	char a[11], b[21],  d[21], f[100] = {".\\userdata\\"}, g[100], h[100], x[100];
	print_ui(4);
	if(c == 1){
		printf("          Passwords not same, please enter your ID and password again.\n");
		delay(25);
	}else if(c == 2){
		printf("        Already has this user, please enter your ID and password again.\n");
		delay(25);
	}else if(c == 3){
		printf("                    Your ID should be less then 10 charactor.\n");
		delay(25);
		printf("                     Please enter your ID and password again\n");
		delay(25);
	}else if(c == 4){
		printf("                 Your password should be less then 20 charactor.\n");
		delay(25);
		printf("                     Please enter your ID and password again\n");
		delay(25);
	}
	printf("Please enter the ID that less then 10 charactor for register or enter 0 to login\n");
	scanf("%s", a);
	if(a[0] == '0' && a[1] == '\0'){
		system("cls");
		return login(0);
	}
	strcat(f, a);
	strcpy(g, f);
	strcpy(h, g);
	strcpy(x, g);
	strcat(f, "\\password.txt");
	FILE*fp;
	fp = fopen(f, "r");
	if(fp == NULL && strlen(a) <= 10){
		fclose(fp);
		printf("\nPlease enter your password that less than 20 charactor:\n");
		password(1, 0);
		if(strlen(pw) > 20){
			system("cls");
			return Register(4);
		}
		printf("Please enter your password again:\n");
		password(2, 0);
		int e = strcmp(pw, pw1);
		if(e == 0){
			mkdir(g);
			fp = fopen(f, "w");
			fprintf(fp, "%s", pw1);
			fclose(fp);
			strcat(g, "\\position.txt");
			fp = fopen(g, "w");
			fprintf(fp, "39 15 32 0");
			fclose(fp);
			strcat(h, "\\pikimon.txt");
			fp = fopen(h, "w");
			fprintf(fp, "1 bat 5 40 0");
			fclose(fp);
			strcat(x, "\\data.txt");
			fp = fopen(x, "w");
			fprintf(fp, "5000 10 0 0 0 0 0 0 0 0 0 0 0");
			fclose(fp);
			load(2);
			system("cls");
			return plot(a);
		}else{
			system("cls");
			return Register(1);
		}
	}else if(fp != NULL){
		fclose(fp);
		system("cls");
		return Register(2);
	}else if(strlen(a) > 10){
		fclose(fp);
		system("cls");
		return Register(3);
	}
}

int change_password(int c, char a[]){
	char b[21], d[21], f[1000] = {".\\userdata\\"}, g[21], h[21];
	print_ui(9);
	strcat(f, a);
	strcat(f, "\\password.txt");
	if(c == 0){
		printf("Please enter your old password or enter 0 to return start page\n");
	}else if(c == 1){
		printf("New password is not the same.\nPlease enter your old password again or enter 0 to return start page.\n");
		delay(25);
	}else if(c == 2){
		printf("                 Your new password should be less then 20 character.\n");
		delay(25);
		printf("Please enter your old password again or enter 0 to return start page.\n");
		delay(25);
	}if(c == 3){
		printf("Old password is invalid.\nPlease enter your old password again or enter 0 to return start page.\n");
		delay(25);
	}
	FILE*fp;
	fp = fopen(f, "r");
	fscanf(fp, "%s", g);
	fclose(fp);
	scanf("%s", h);
	if(h[0] == '0' && h[1] == '\0' && ! (g[0] == '0' && g[1] == '\0')){
		system("cls");
		return start(a, 0);
	}
	int e = strcmp(h, g);
	if(e != 0){
		system("cls");
		return change_password(3, a);
	}
	printf("\nPlease enter your new password\n");
	scanf("%s", b);
	if(strlen(b) > 20){
		system("cls");
		return change_password(2, a);
	}
	printf("Please enter your new password again:\n");
	scanf("%s", d);
	e = strcmp(b, d);
	if(e != 0){
		system("cls");
		return  change_password(1, a);
	}else {
	fp = fopen(f, "w");
	fprintf(fp, "%s", d);
	fclose(fp);
	system("cls");
	printf("                              Changed password!\n");
	return start(a, 0);
	}
}

int print_plot(int t, char b[1000]){
	int i, kb=0;
	int l = strlen(b);
	char c;
	for(i = 0; i < l; i++){
		printf("%c", b[i]);
		if (kbhit() == 1){
			c = getch();
			if(c == 13)
  		 	 	kb = 1;
  		}
 		if (kb == 0){
			delay(t);
    	}
	}
}

int print_photo(char c[10001], int x, int y, int type){//0 for photo 1 for ball.
	FILE*fp;
	int i, j;
	char b[1000];
	fp = fopen(c, "r");
	if(fp == NULL){
		printf_c(12, "bug %s", c);
	}
	while(fgets(b, 1000, fp)){
		y++;
		gotoxy(x, y);
		if(type == 0){
			printf("%s", b);
		}else if(type == 1){
			for(j = 0; j < 10; j++){
				if(b[4] == '[' && b[j] == '=')
					color(8);
				else if(b[j] == '='){
					color(12);
				}else
					color(15);
				printf("%c", b[j]);
			}
		}
	}
	fclose(fp);
	return y;
}

int plot(char d[10]){//new player plot
 	int i;
	FILE*fp;
	int x, y, j;
	char p[5][9];
	char a[1000], b[1000];
	print_ui(10);
	color(11);
	print_plot(10, "                       This is the world of PIKIMON!!!\n\n");
	print_plot(10, "             In here, no magic, no KungFu. ");
	print_plot(10, "But we have PIKIMON here!!\n\n"); 
	print_plot(10, "                  In this world, only PIKIMON and the trainers.\n\n");
	print_plot(10, "                       WELCOME To the world of PIKIMON!\n\n");
	print_plot(10, "                                   Dear ");
	printf("%s.\n\n", d);
	print_plot(10, "     Bring your PIKIMON and fight to become the Master Trainer of PIKIMON!!!\n\n");
	printf_c(10, "\n________________________________________________________________________________\n");
	printf("                        Press any key to continue ......");
	getch();
	system("CLS");
	for(i = 0; i < 4; i++){
		system("COLOR FA");
		delay(100);
		system("COLOR 0A");
		delay(100);
	}
	color(15);
	print_photo("./bin/npc/boy.txt", 0, 0, 0);
	print_ui(0);
	printf_cxy(14, 2, 18, "Dr PI");
	printf_plot("Welcome to the world of PIKIMON,", "I am Dr PI. One of the scientists who studies PIKIMON.", 2, " %s.", d);
	printf_plot(" I am Dr PI, today I will teach you about PIKIMON.", "First, you should catch a PIKIMON first.", 1, "Hello %s.", d);
	color(7);
	print_photo("./bin/pikimon/bat1.txt", 40, 4, 0);
	printf_plot("See, there is a BAT!", "Let's catch it!", 0, "");
	clear(5);
	print_photo("./bin/item/ball1.txt",55, 7, 1);
	printf_plot("Take the PIKIMON BALL.","And go!!!!!!!!!!!!", 0, "");
	system("cls");
	print_ui(11);
 	printf_cxy(12, 5, 5, "LV:??? <<<????/????>>>");
 	printf_xy(46, 5, "LV:??? <<<????/????>>>");
 	print_ui(14);
	for(i = 0; i < 4; i++){
		printf_xy(3 + i * 15, 20, "Damage:???");
	}
	printf_cxy(12, 0, 23, "Press ");
	printf_c(14, "1,2,3 or 4 ");
	printf_c(12, "to use the skill to attack your enemy");
	gotoxy(0,1);
	char c;
	int m = 0, kb = 0,s;
	color(15);
	print_photo("./bin/pikimon/q.txt", 0, 5, 0);
	while(c != 27){
		color(15);
		print_photo("./bin/pikimon/bat1.txt", 40, 5, 0);
		for(i = 0; i < 50; i++){
			delay(10);
			if (kbhit() == 1){
      		  	c = getch();
      		  	kb = 1;
      		  	}
     		if (c == 'b' && kb == 1 || c == '1' && kb == 1){
      		  	kb = 0;
      		  	break;
        	}
		}
		print_photo("./bin/pikimon/bat2.txt", 40, 5, 0);
		for(i = 0; i < 50; i++){
			delay(10);
			if (kbhit() == 1){
      	 		c = getch();
      		  	kb = 1;
        	}
     		if (c == 'b' && kb == 1 || c == '1' && kb == 1){
      		  	kb = 0;
      		  	break;
      		}
		}
		color(10);
		if((c == '1' || c == '2' || c == '3' || c == '4') && m == 0){
			m = 1;
			gotoxy(23, 10);
			color(12);
			for(i = 0; i < 25; i++){
				delay(10);
				printf("-");
			}
			printf_xy(46, 5, "<<<   1/????>>>   -????");
			print_photo("./bin/pikimon/bat1.txt",40 ,5 ,0);
			gotoxy(23, 10);
			for(i = 0; i < 18; i++){
				delay(20);
				printf(" ");
			}
			print_photo("./bin/pikimon/bat2.txt", 40, 5, 0);
			delay(500);
			printf_xy(46, 5, "<<<   1/????>>>        ");
			printf_cxy(12, 0, 23,"Press ");
			printf_c(14, "B ");
			printf_c(12, "to select the PIKIMON BALL and press ");
			printf_c(14, "1");
			printf_c(12, " to use the PIKIMON BALL");
			color(15);
			gotoxy(0, 0);
		}else if (c == 'b' &&m == 1){
     		clear(c);
			printf_xy(1, 19, "1.");
   	 		y = 16;
   	 		x = 3;
			y = print_photo("./bin/item/ball1.txt", x, y, 1);
			m = 2;
		}else if(c == '1' && m == 2){
			clear(1);
			clear(3);
			color(7);
			print_photo("./bin/pikimon/bat1.txt", 40, 5, 0);
			for(i = 0; i < 9; i++){
				printf_xy(x, y + 2, "   ");
				printf_xy(x, y + 3, "   ");
				printf_xy(x + 1, y + 4,"   ");
				printf_xy(x + 3, y + 5,"    ");
     			y = 17 - i;
     			x = 3 + i * 3;
				print_photo("./bin/item/ball1.txt", x, y, 1);
				gotoxy(0, 0);
				delay(100);
			}
			color(14);
			for(i = 0; i < 10; i++){
				x++;
				gotoxy(x + 12, 12);
				print_plot(20, "-");
				if(i == 9)
					print_photo("./bin/pikimon/bat1.txt", 40, 5, 0);
			}
			for(i = 5; i < 16; i++){
				gotoxy(40, i);
				print_plot(2, "                                        ");
			}
			for(i = 0; i < 6; i++){
				y = 9;
     			x = 27;
				if(i % 2 == 0){
					printf_xy(27, 12, " ");
					x++;
					y++;
				}
				for(j = 6;j >= 0; j--){
				printf_xy(x - 2, y + j, "             ");
				}
				print_photo("./bin/item/ball1.txt", x, y, 1);
				delay(500);
			}
			printf_cxy(14, 24, 6, "    SUCCESS!!");
				printf_xy(24, 8, "\\*\\*\\      /*/*/");
				printf_xy(26, 9, "\\*\\*\\  /*/*/");
			color(8);
			delay(1000);
			system("cls");
			break;
		}
		kb = 0;
    }
	color(15);
	print_photo("./bin/npc/boy.txt", 0, 0, 0);
	print_ui(0);
	printf_cxy(14, 2, 18, "Dr PI");
	printf_plot("OH! You have caught the bat, ", "Congratulations!!!", 2, "%s!!", d);
	printf_plot("Then now start your own legendary jounrey!!!", "", 3, "%s!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", d);
	system("cls");
	start(d, 0);
}

int start(char a[], int c){
	char b[2];
	print_ui(12);
	printf("1.Continue game\n\n");
	delay(25);
	printf("2.Change password\n\n");
	delay(25);
	printf("3.Version\n\n");
	delay(25);
	printf("4.Logout\n\n");
	delay(25);
	printf("5.Exit\n\n");
	printf("Enter number to action:\n");
	scanf("%s", b);
	if(b[0] - '0' == 1 && b[1] == '\0'){
		system("cls");
	system("COLOR 07");
		return position(a);
	}
	if(b[0] - '0' == 2 && b[1] == '\0'){
		system("cls");
		return change_password(0, a);
	}
	if(b[0] - '0' == 3 && b[1] == '\0'){
		system("cls");
		return version(a);
	}
	if(b[0] - '0' == 4 && b[1] == '\0'){
		system("cls");
		printf("                                   Logout Success!\n");
		return welcome();
	}
	if(b[0] - '0' == 5 && b[1] == '\0'){
		exit(0);
	}
	system("cls");
	return start(a, 0);
}

int version(char a[]){//????? :)
	printf("________________________________________________________________________________\n");
	delay(25);
	printf("Readying for 0.3.1\n");
	printf("                        press any key to continue ......\n");
	printf("________________________________________________________________________________\n");
	delay(25);
	printf("Ver.0.2.1\n\n");
	printf("1.Added the basic fighting system\n");
	delay(25);
	printf("2.Added the newbie plot\n");
	delay(25);
	printf("3.Added the color of map\n");
	delay(25);
	printf_c(10, "________________________________________________________________________________\n");
	delay(25);
	printf("Ver.0.1.1\n\n");
	printf("1.Added the admin control panel\n");
	delay(25);
	printf_c(13, "2.Added the color of user in the map\n");
	delay(25);
	printf("3.Added the color in login system\n");
	delay(25);
	printf_c(10, "________________________________________________________________________________\n");
	delay(25);
	printf("Ver.0.0.1\n\n");
	delay(25);
	printf("1.Added the road\n");
	delay(25);
	printf("2.Added the basic login system\n");
	delay(25);
	printf("3.Added four maps\n");
	printf("________________________________________________________________________________\n");
	gotoxy(0, 0);
	gotoxy(56, 3);
	getch();
	system("cls");
	if(strcmp(a, "admin") == 0)
		return admin_start(a, 0);
	return start(a, 0);
}

int save_position(int a, char f[1000], int x, int y, char c, int map){
	FILE*fp;
	fp = fopen(f, "w");
	fprintf(fp,"%d\n%d\n%d\n%d\n", x, y, c, map);
	fclose(fp);
	if(a == 0)
	system("cls");
}

int print_color(char c, int map){//print color of map
	if(c == '!'){
		printf_c(mpcol[0], "!");
	}else if(c == '\\' || c == '/'){
		printf_c(2, "%c", c);
	}else if(c == '%'){
		printf_c(8, "%c", c);
	}else if(c == '$'){
		printf_c(14, "%c", c);
	}else if(c == '~'){
		printf_c(3, "%c", c);
	}else if(c == '='){
		if(map == 0){
			printf_c(7, "%c", c);
		}else{
			printf_c(12, "%c", c);
		}
	}else if(c == '&'){
		printf_c(2, "%c", c);
	}else if(c == '#' && map == 0){
		printf_c(12, "%c", c);
	}else
		printf("%c", c);
	color(7);
}

int bag(char d[100]){//bag of player
	system("cls");
	FILE*fp;
	int c, hp[3], lv[3], exp[3], i, atk, amr, mhp;
	char e[100] = {"./userdata/"}, p[3][100];
	print_ui(13);
	strcat(e, d);
	strcat(e, "/pikimon.txt");
	fp = fopen(e, "r");
	if(fp == NULL){
		printf("%s BUGGGGGGGGGGGGGGG", e);
	}
	fscanf(fp, "%d", &c);
	for(i = 0; i < c; i++){
		fscanf(fp, "%s", p[i]);
		fscanf(fp, "%d", &lv[i]);
		fscanf(fp, "%d", &hp[i]);
		fscanf(fp, "%d", &exp[i]);
	}
	fclose(fp);
	printf("	Player %s have %d PIKIMONs.\n", d, c);
	printf("|==============================================================================|");	
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|                         |                          |                         |");
	printf("|==============================================================================|");
	for(i = 0; i < c; i++){
		if(strcmp(p[i], "bat") == 0){
			mhp = lv[i] * fig[0][0];
			atk = lv[i] * fig[0][1];
			amr = lv[i] *fig[0][2];
		}else if(strcmp(p[i], "gold") == 0){
			mhp = lv[i] * fig[1][0];
			atk = lv[i] * fig[1][1];
			amr = lv[i] * fig[1][2];
		}else if(strcmp(p[i], "wood") == 0){
			mhp = lv[i] * fig[2][0];
			atk = lv[i] * fig[2][1];
			amr = lv[i] * fig[2][2];
		}else if(strcmp(p[i], "water") == 0){
			mhp = lv[i] * fig[3][0];
			atk = lv[i] * fig[3][1];
			amr = lv[i] * fig[3][2];
		}else if(strcmp(p[i], "fire") == 0){
			mhp = lv[i] * fig[4][0];
			atk = lv[i] * fig[4][1];
			amr = lv[i] * fig[4][2];
		}else if(strcmp(p[i], "rock") == 0){
			mhp = lv[i] * fig[5][0];
			atk = lv[i] * fig[5][1];
			amr = lv[i] * fig[5][2];
		}
		int ad = 27;
		printf_xy(11 + i * ad, 9, "LV:%d", lv[i]);
		printf_xy(9 + i * ad, 11, "Name:%s", p[i]);
		printf_xy(6 + i * ad, 13, "<<<%4d/%4d>>>", hp[i], mhp);
		printf_xy(8 + i * ad, 15, "Attack:%d", atk);
		printf_xy(8 + i * ad, 17, "Armor:%4d", amr);
	}
	printf_cxy(15, 0, 20, "Press any key to continue ......");
	getch();
}

int addhp(char command[10], char d[100]){//hospital use???
	FILE*fp;
	char l[999] = {"./userdata/"};
	long long i, c, lv[4], hp[4], exp[4], mexp, nexp = 0;
	char p[4][100];
	strcat(l, d);
	strcat(l, "/pikimon.txt");
	if(strcmp(command, "all") == 0){
		fp = fopen(l, "r");
		if(fp == NULL){
			printf("%s BUGGGGGGGGGGGGGGG", l);
			getch();
		}
		fscanf(fp, "%lld", &c);
		for(i = 0; i < c; i++){
			fscanf(fp, "%s", p[i]);
			fscanf(fp, "%lld", &lv[i]);
			fscanf(fp, "%lld", &hp[i]);
			fscanf(fp, "%lld", &exp[i]);
		}
		fclose(fp);
		for(i = 0; i < c; i++){
			if(strcmp(p[i],"bat") == 0){
				hp[i] = lv[i] * fig[0][0];
			}else if(strcmp(p[i], "gold") == 0){
				hp[i] = lv[i] * fig[1][0];
			}else if(strcmp(p[i], "wood") == 0){
				hp[i] = lv[i] * fig[2][0];
			}else if(strcmp(p[i], "water") == 0){
				hp[i] = lv[i] * fig[3][0];
			}else if(strcmp(p[i], "fire") == 0){
				hp[i] = lv[i] * fig[4][0];
			}else if(strcmp(p[i], "rock") == 0){
				hp[i] = lv[i] * fig[5][0];
			}
		}
		fp = fopen(l, "w");
		if(fp == NULL){
			printf("%s BUGGGGGGGGGGGGGGG", l);
			getch();
		}
		fprintf(fp, "%lld\n", c);
		for(i = 0; i < c; i++){
			fprintf(fp, "%s\n", p[i]);
			fprintf(fp, "%lld\n", lv[i]);
			fprintf(fp, "%lld\n", hp[i]);
			fprintf(fp, "%lld\n", exp[i]);
		}
		fclose(fp);
	}
}

int hospital(char d[]){//XD
	system("cls");
	color(15);
	print_photo("./bin/npc/nurse.txt", 0, 0, 0);
	print_ui(0);
	printf_cxy(14, 2, 18,"Miss Alice");
	printf_plot("Do you want to spend $200 to heal all your PIKIMONs' HP?", "Press Y to yes or N to back the map.", 5, "");
	char a = getch();
	while(a != 'n' && a != 'y'){
		a = getch();
	}
	if(a == 'y'){
		int m = money(d, -200);
		if(m == 0){
			printf_plot("Sorry, you have not enough money to pay it", "Go and earn money!!!!!!",0 ,"");
		}
		addhp("all", d);
		printf_plot("Your PIKIMONs' HP has been healed,", "Bye bye!", 2, "%s", d);
	}else if(a == 'n'){
		printf_plot("OH, you don't need my help.'", "Bye bye!", 2, "%s",d);
	}
}

int move(char a[20][80], int x, int y, char c, char d[], int map){//map moverment
	system("cls");
	int i, j, fight = 0;
	for(i = 0; i < 20; i++){
		for(j = 0; j < 78; j++){
			print_color(a[i][j], map);
		}
		printf("\n");
	}
	printf("Please enter");
	printf_c(11, " W,A,S,D");
	printf_c(7, " to move or press");
	printf_c(11, " B");
	printf_c(7, " to enter the bag\n");
	printf("Press ");
	printf_c(11, "0 ");
	printf_c(7, "to back the home page...");
	char b;
	while(b != '0'){
		delay(10);
		b = getch();
		char f[1000]={".\\userdata\\"};
		strcat(f,d);
		strcat(f,"\\position.txt");
		if(b == '0'){
			system("cls");
			system("COLOR 0A");
			if(strcmp(d, "admin") == 0)
				return admin_start(d, 0);
			else 
				return start(d, 0);
		}else if(b == 'b'){
			bag(d);
			break;
		}else if(b == 'w'){
			if(y == 9 && x == 59 && map == 1){// saving positions. and change map
				hospital(d);
				save_position(0, f, x, y, c, map);
				return position(d);
			}if(y == 0 && x >= 37 && x <= 40 && map == 1){
				y = 19;
				map = 2;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(y == 0 && x >= 37 && x <= 40 && map == 3){
				y = 19;
				map = 1;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(y == 12 && x >= 37 && x <= 40 && map == 1){
				y = 19;
				map = 0;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(y == 0 && x >= 37 && x <= 40 && map == 0){
				y = 7;
				map = 1;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(a[y - 1][x] != '#'){
				a[y][x] = c;
				gotoxy(x, y);
				print_color(c, map);
				y--;
				printf_cxy(mpcol[0], x, y, "!");
				color(7);
				c = a[y][x];
				a[y][x] = '!';
				gotoxy(32, 21);
				fight = touch(c, d,map);
			}
		}else if(b == 'a'){
			if(x == 0 && y >= 9 && y <= 10 && map == 0){
				x = 34;
				map = 1;
				c = 32;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(x == 43 && y >= 9 && y <= 10 && map == 1){
				x = 77;
				map = 0;
				c = 61;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(a[y][x - 1] != '#'){
				a[y][x] = c; 
				gotoxy(x, y);
				print_color(c, map);
				x--;
				printf_cxy(mpcol[0], x, y, "!");
				color(7);
				c = a[y][x];
				a[y][x] = '!';
				gotoxy(32, 21);
				fight = touch(c, d,map);
			}
		}else if(b == 's'){
			if(y == 19 && x >= 37 && x <= 40 && map == 2){
				y = 0;
				map = 1;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(y == 19 && x >= 37 && x <= 40 && map == 1){
				y = 0;
				map = 3;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(y == 19 && x >= 37 && x <= 40 && map == 0){
				y = 12;
				map = 1;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(y == 7 && x >= 37 && x <= 40 && map == 1){
				y = 0;
				map = 0;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(a[y + 1][x] != '#'){
				a[y][x] = c;
				gotoxy(x, y);
				print_color(c, map);
				y++;
				printf_cxy(mpcol[0], x, y, "!");
				color(7);
				c = a[y][x];
				a[y][x] = '!';
				gotoxy(32, 21);
				fight = touch(c, d, map);
			}
		}else if(b == 'd'){
			if(x == 77 && y >= 9 && y <= 10 && map == 0){
				x = 43;
				map = 1;
				c = 32;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(x == 34 && y >= 9 && y <= 10 && map == 1){
				x = 0;
				map = 0;
				c = 61;
				save_position(0, f, x, y, c, map);
				return position(d);
			}else if(a[y][x + 1] != '#'){
				a[y][x] = c;
				gotoxy(x, y);
				print_color(c, map);
				x++;
				printf_cxy(mpcol[0], x, y, "!");
				color(7);
				c = a[y][x];
				a[y][x] = '!';
				gotoxy(32, 21);
				fight=touch(c, d, map);
			}
		}
		save_position(1, f, x, y, c, map);
	if(fight == 1)
		break;
	}
	return move(a, x, y, c, d, map);
}

int position(char d[]){//change map
	char a[20][80] = {0,}, f[1000] = {".\\userdata\\"}, g[1000] = {".\\bin\\map\\map"};
	strcat(f, d);
	strcat(f, "\\position.txt");
	int i, j, x, y, c, map;
	char z, mn[2];
	FILE*fp;
	fp = fopen(f, "r");
	fscanf(fp, "%d%d%d%d", &x, &y, &c, &map);
	fclose(fp);
	g[strlen(g)] = map + '0';
	strcat(g, ".txt");
	fp = fopen(g, "r");
	if(fp == NULL){
		printf("bug%s", g);
	}
	for(i = 0; i < 20; i++)
	fgets(a[i], 80, fp);
	fclose(fp);
	z = c;
	a[y][x] = '!';
	return move(a, x, y, z, d, map);
}

int touch(int c, char d[], int map){//probability of monstor
	int r, m;
	r = (rand() % 100) + 1;
	if(map == 2){
		m = r / 4;
	}else if(map  == 3){
		m = r / 4 + 25;
	}
	if(map != 0 && map != 1){
		if(c == 36 && r % 5 == 1){
				cal_fight(1, m, d);
				return 1;
		}else if(c == 38 && r % 5 == 2){
				cal_fight(2, m, d);
				return 1;
		}else if(c == 126 && r % 5 == 3){
				cal_fight(3, m, d);
				return 1;
		}else if(c == 61 && r % 5 == 4){
				cal_fight(4, m, d);
				return 1;
		}else if(c == 37 && r % 5 == 0){
				cal_fight(5, m, d);
				return 1;
		}
	}
	return 0;
}

int cal_fight(int s, int plv, char d[]){//cal for hp and attack and armor
	FILE*fp;
	int c, i;
	int lv[4], hp[4], mhp[4], atk[4], amr[4], exp[4];
	char l[3][100], e[100] = {"./userdata/"}, p[4][100];
	strcat(e, d);
	strcat(e, "/pikimon.txt");
	fp=fopen(e, "r");
	if(fp == NULL){
		printf("%s BUGGGGGGGGGGGGGGG", e);
		getch();
	}
	fscanf(fp, "%d", &c);
	for(i = 0; i < c; i++){
		fscanf(fp, "%s", p[i]);
		fscanf(fp, "%d", &lv[i]);
		fscanf(fp, "%d", &hp[i]);
		fscanf(fp, "%d", &exp[i]);
	}
	fclose(fp);
	if(plv != 0){
		lv[3] = plv;
	}else {
		lv[3] = 1;
	}
	for(i = 0; i < 4; i++){
		if(s == 0 || strcmp(p[i], "bat") == 0){
			mhp[i] = lv[i] * fig[0][0];
			atk[i] = lv[i] * fig[0][1];
			amr[i] = lv[i] * fig[0][2];
			strcpy(p[i], "bat");
		}else if(s == 1 || strcmp(p[i], "gold") == 0){
			mhp[i] = lv[i] * fig[1][0];
			atk[i] = lv[i] * fig[1][1];
			amr[i] = lv[i] * fig[1][2];
			strcpy(p[i], "gold");
		}else if(s == 2 || strcmp(p[i], "wood") == 0){
			mhp[i] = lv[i] * fig[2][0];
			atk[i] = lv[i] * fig[2][1];
			amr[i] = lv[i] * fig[2][2];
			strcpy(p[i],"wood");
		}else if(s == 3 || strcmp(p[i], "water") == 0){
			mhp[i] = lv[i] * fig[3][0];
			atk[i] = lv[i] * fig[3][1];
			amr[i] = lv[i] * fig[3][2];
			strcpy(p[i], "water");
		}else if(s == 4 || strcmp(p[i], "fire") == 0){
			mhp[i] = lv[i] * fig[4][0];
			atk[i] = lv[i] * fig[4][1];
			amr[i] = lv[i] * fig[4][2];
			strcpy(p[i], "fire");
		}else if(s == 5 || strcmp(p[i], "rock") == 0){
			mhp[i] = lv[i] * fig[5][0];
			atk[i] = lv[i] * fig[5][1];
			amr[i] = lv[i] * fig[5][2];
			strcpy(p[i], "rock");
		}
	}
	hp[3] = mhp[3];
	system("cls");
/*	printf("...test...\n");
	for(i=0;i<4;i++){
		printf(" n:%s\n lv:%d\n hp:%d/%d\n atk:%d\n amr:%d\n\n",p[i],lv[i],hp[i],mhp[i],atk[i],amr[i]);
	}
	getch();*/
	fight(d, p, lv, hp, mhp, atk, amr, exp, c);
}

int color_p(char p[100]){//color of pikimon
	if(strcmp(p, "bat") == 0){
		color(7);
	}else if(strcmp(p, "gold") == 0){
		color(14);
	}else if(strcmp(p, "wood") == 0){
		color(2);
	}else if(strcmp(p, "water") == 0){
		color(11);
	}else if(strcmp(p, "fire") == 0){
		color(12);
	}else if(strcmp(p, "rock") == 0){
		color(7);
	}
}

int cal_atk(int atk, int amr){//????????????????????????????????????????????????????
	int a;
	a = ceil(atk * (1 - ceil(sqrt((double) amr)) / 50));
	return a;
}

int cal_exp(int addexp, char d[], int pt){//calculating exp
	FILE*fp;
	char l[999] = {"./userdata/"};
	long long i, c, lv[4], hp[4], exp[4], mexp, nexp = 0;
	char p[4][100];
	strcat(l, d);
	strcat(l, "/pikimon.txt");
	fp = fopen(l, "r");
	if(fp == NULL){
		printf("%s BUGGGGGGGGGGGGGGG", l);
		getch();
	}
	fscanf(fp, "%lld", &c);
	for(i = 0; i < c; i++){
		fscanf(fp, "%s", p[i]);
		fscanf(fp, "%lld", &lv[i]);
		fscanf(fp, "%lld", &hp[i]);
		fscanf(fp, "%lld", &exp[i]);
	}
	fclose(fp);
	mexp = lv[pt] * lv[pt] * 10 - 10 * lv[pt] + 100;
	exp[pt] = addexp + exp[pt];
	while(mexp < exp[pt]){
		mexp = lv[pt] * lv[pt] * 10 - 10 * lv[pt] + 100;
		exp[pt] = exp[pt] - mexp;
		lv[pt]++;
		if(strcmp(p[pt], "bat") == 0){
			hp[pt] = lv[pt] * fig[0][0];
		}else if(strcmp(p[pt], "gold") == 0){
			hp[pt] = lv[pt] * fig[1][0];
		}else if(strcmp(p[pt], "wood") == 0){
			hp[pt] = lv[pt] * fig[2][0];
		}else if(strcmp(p[pt], "water") == 0){
			hp[pt] = lv[pt] * fig[3][0];
		}else if(strcmp(p[pt], "fire") == 0){
			hp[pt] = lv[pt] * fig[4][0];
		}else if(strcmp(p[pt], "rock") == 0){
			hp[pt] = lv[pt] * fig[5][0];
		}
   		printf_cxy(13, 28, 8, "%s", p[pt]);
   		printf_c(7, " is level");
   		printf_c(14, " %lld", lv[pt]);
   		printf_c(7, " now!!!");
	}
   		printf_cxy(13, 22, 6, "%s", p[pt]);
   		printf_c(7, " still need");
   		printf_c(14, " %lld", mexp - exp[pt]);
   		printf_c(7, " exp to next level.");
	fp = fopen(l, "w");
	if(fp == NULL){
		printf("%s BUGGGGGGGGGGGGGGG", l);
		getch();
		exit(0);
	}
	fprintf(fp, "%d\n", c);
	for(i = 0; i < c; i++){
		fprintf(fp, "%s\n", p[i]);
		fprintf(fp, "%lld\n", lv[i]);
		fprintf(fp, "%lld\n", hp[i]);
		fprintf(fp, "%lld\n", exp[i]);
	}
	fclose(fp);
}

//fighting monitor
int fight(char d[], char p[4][100], int lv[4], int hp[4], int mhp[4], int atk[4], int amr[4], int exp[4], int n){
	int h, i, j, x, y, pt, dam;
	char l[5][100];
	system("cls");
	print_ui(11);
	gotoxy(0, 16);
	print_ui(14);
	printf_c(12, "Press ");
	printf_c(14, "1,2,3,4 or A,B,C,D");
	printf_c(12, " to continue.");
	gotoxy(0, 1);
	char c;
	int m = 0, kb = 0, s;
	color(15);
	for(i = 0; i < 3; i++){
	strcpy(l[i], "./bin/pikimon/");
	if(strcmp(p[i], "bat") == 0){
		strcat(l[i], "bat1");
	}else 
		strcat(l[i], p[i]);
	strcat(l[i], ".txt");
	}
	strcpy(l[3], "./bin/pikimon/");
	strcat(l[3], p[3]);
	strcat(l[3], ".txt");
	pt = 0;
	for(i = 0; i < 4; i++){
		printf_xy(3 + i * 15, 20, "Damage:%3d", atk[pt] / lv[pt] * 10);//?????????????????????????????????????????????????
	}
 	printf_cxy(12, 46, 5, "lv:%3d <<<%4d/%4d>>>", lv[3], hp[3], mhp[3]);//enemy
 	printf_xy(5, 5, "lv:%3d <<<%4d/%4d>>>", lv[pt], hp[pt], mhp[pt]);
 	color_p(p[3]);
	print_photo(l[3], 40, 5, 0);//enemy
	if(strcmp(p[pt], "bat") != 0){
	 	color_p(p[pt]);
		print_photo(l[pt], 0, 5, 0);
	}
	while(c != 27){
		h = 0;
		color(15);
		if(strcmp(p[pt], "bat") == 0){
 			color_p(p[0]);
			print_photo("./bin/pikimon/bat1.txt", 0, 5, 0);
			for(i = 0; i < 50; i++){
				delay(10);
				if (kbhit() == 1){
	      		  	c = getch();
	      		  	kb = 1;
	      		  	}
	     		if (c == 'b' && kb == 1 || c == '1' && kb == 1){
	      		  	h = 1;
	      		  	kb = 0;
	      		  	break;
	        	}
			}
 			color_p(p[0]);
			print_photo("./bin/pikimon/bat2.txt", 0, 5, 0);
			for(i = 0; i < 50; i++){
				delay(10);
				if (kbhit() == 1){
	      	 		c = getch();
	      		  	kb = 1;
	        	}
	     		if (c == 'b' && kb == 1 || c == '1' && kb == 1){
	      		  	h = 1;
	      		  	kb = 0;
	      		  	break;
	      		}
			}
			color(10);
		}else{
			for(i = 0; i < 500; i++){
				delay(1);
				if (kbhit() == 1){
	      		  	c = getch();
	      		  	kb = 1;
	      		}
	     		if ((c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == '1' || c == '2' || c == '3' || c == '4' ) && kb == 1){
	      		  	h = 1;
	      		  	kb = 0;
	      		  	break;
	        	}
			}
		}
		if(c == 'd'){
			color(7);
			system("cls");
			break;
		}else if(m != 0 && c == 'a'){
			h = 0;
			print_ui(14);
			for(i = 0; i < 4; i++){
				printf_xy(3 + i * 15, 20, "Damage:%3d", atk[pt] / lv[pt] * 10);
			}
		}else if((c == '1' || c == '2' || c == '3' || c == '4') && m == 0){
			c = 0;
			gotoxy(23, 10);
			color(12);
			for(i = 0; i < 25; i++){
				delay(10);
				printf("-");
			}
			dam = cal_atk(atk[pt], amr[3]);
			hp[3] = hp[3] - dam;
			if(hp[3] < 0){
				hp[3] = 0;
			}
			printf_cxy(12, 53, 5, "<<<%4d/%4d>>>   -%d", hp[3], mhp[3], dam);
			print_photo(l[3], 40, 5, 0);
			color_p(p[pt]);
			gotoxy(23, 10);
			for(i = 0; i < 18; i++){
				delay(20);
				printf(" ");
			}
			print_photo(l[pt], 0, 5, 0);
			color_p(p[3]);
			print_photo(l[3], 40, 5, 0);
			delay(500);
			if(hp[3] <= 0){
				color(7);
				system("cls");
				break;
			}
			printf_cxy(12, 53, 5, "<<<%4d/%4d>>>", hp[3], mhp[3]);//enemy
			gotoxy(0, 0);
		}else if (c == 'b' && m != 1){
			h = 0;
     		clear(c);
			printf_xy(1, 19, "1.");
   	 		y = 16;
   	 		x = 3;
			y = print_photo("./bin/item/ball1.txt", x, y, 1);
			m = 1;
		}else if(c == '1' && m == 1){
			clear(1);
			clear(3);
			clear(4);
			for(i = 0; i < 9; i++){
				printf_xy(x, y + 2, "   ");
				printf_xy(x, y + 3, "   ");
				printf_xy(x + 1, y + 4, "   ");
				printf_xy(x + 3, y + 5, "    ");
     			y = 17 - i;
     			x = 3 + i * 3;
				print_photo("./bin/item/ball1.txt", x, y, 1);
				gotoxy(1, 0);
				delay(100);
			}
			color(14);
			for(i = 0; i < 10; i++){
				x++;
				gotoxy(x + 12, 12);
				print_plot(20, "-");
			} 
			print_photo(l[3], 40, 5, 0);
			for(i = 5; i < 16; i++){
				gotoxy(40, i);
				print_plot(5, "                                        ");
			}
			for(i = 0; i < 6; i++){
				y = 9;
     			x = 27;
				if(i % 2 == 0){
					printf_xy(27, 12, " ");
					x++;
					y++;
				}
				for(j = 6; j >= 0; j--){
				printf_xy(x - 2, y + j, "             ");
				}
				print_photo("./bin/item/ball1.txt", x, y, 1);
				delay(500);
			}
			printf_cxy(14, 24, 6, "    SUCCESS!!");
			printf_xy(24, 8, "\\*\\*\\      /*/*/");
			printf_xy(26, 9, "\\*\\*\\  /*/*/");
			color(7);
			catchp(d, p[3], lv[3], hp[3], exp[3]);
			getch();
			system("cls");
			break;
		}
		if(h == 1){
			color(12);
			for(i = 0; i < 25; i++){
				delay(10);
				printf_xy(53 - i, 10, "-");
			}
			dam = cal_atk(atk[3], amr[pt]);
			hp[pt] = hp[pt] - dam;
			if(hp[pt] < 0){
				hp[pt] = 0;
			}
			printf_cxy(12, 5, 5, "lv:%3d <<<%4d/%4d>>>   -%d", lv[pt], hp[pt], mhp[pt], dam);
			print_photo(l[pt], 0, 5, 0);
			color_p(p[3]);
			for(i = 0; i < 18; i++){
				delay(20);
				printf_xy(53 - i, 10, " ");
			}
			print_photo(l[3], 40, 5, 0);
			color_p(p[pt]);
			print_photo(l[pt], 0, 5, 0);
			delay(500);
			if(hp[pt] <= 0){
				color(7);
				system("cls");
				break;
			}
			printf_cxy(12, 5, 5, "lv:%3d <<<%4d/%4d>>>", lv[pt], hp[pt], mhp[pt]);//enemy
			gotoxy(0, 0);
		}
		kb = 0;
    }
	system("cls");
    int nexp;
    cal_dam(d, p, lv, hp, exp, n);
	printf("\n|==============================================================================|");	
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|                                                                              |");
	printf("|==============================================================================|");
    if(hp[pt] > 0 && c != 'd'){
		nexp = ceil(lv[3] * lv[3] * 20 / (double)lv[pt]);
	    cal_exp(nexp, d, pt);
	}else {
		nexp = 0;
		cal_exp(nexp, d, pt);
	}
    printf_cxy(13, 32, 4, "%s", p[pt]);
	printf_c(7, " get exp:");
	printf_c(14, "%d\n", nexp);
	printf_xy(24, 10, "press any key to continue .....");
	getch();
	color(7);
	system("cls");
}

int cal_dam(char d[], char p[4][100], int lv[4], int hp[4], int exp[4], int c){//cal damage in file
	FILE*fp;
	char l[999] = {"./userdata/"};
	long long i;
	strcat(l, d);
	strcat(l, "/pikimon.txt");
	fp= fopen(l, "w");
	if(fp == NULL){
		printf("%s BUGGGGGGGGGGGGGGG", l);
		getch();
	}
	fprintf(fp, "%d\n", c);
	for(i = 0; i < c; i++){
		fprintf(fp, "%s\n", p[i]);
		fprintf(fp, "%lld\n", lv[i]); 
		fprintf(fp, "%lld\n", hp[i]);
		fprintf(fp, "%lld\n", exp[i]);
	}
	fclose(fp);
}

int catchp(char d[100], char ap[100], int alv, int ahp, int aexp){//catch pikimon
	FILE*fp;
	char l[999] = {"./userdata/"};
	long long i, c, lv[4], hp[4], exp[4], mexp, nexp = 0;
	char p[4][100];
	strcat(l, d);
	strcat(l, "/pikimon.txt");
	fp = fopen(l, "r");
	if(fp == NULL){
		printf("%s BUGGGGGGGGGGGGGGG", l);
		getch();
	}
	fscanf(fp, "%d", &c);
	for(i = 0; i < c; i++){
		fscanf(fp, "%s",p[i]);
		fscanf(fp, "%d", &lv[i]);
		fscanf(fp, "%d", &hp[i]);
		fscanf(fp, "%d", &exp[i]);
	}
	fclose(fp);
	if(c < 3){
		printf("%s  %d",l,c);
		fp = fopen(l, "w");
		c++;
		fprintf(fp, "%d\n",c);
		for(i = 0; i < c - 1; i++){
			fprintf(fp, "%s\n", p[i]);
			fprintf(fp, "%lld\n", lv[i]);
			fprintf(fp, "%lld\n", hp[i]);
			fprintf(fp, "%lld\n", exp[i]);
		}
			fprintf(fp, "%s\n", ap);
			fprintf(fp, "%lld\n", alv);
			fprintf(fp, "%lld\n", ahp);
			fprintf(fp, "%lld\n", aexp);
		fclose(fp);
	}
}

main(){//no use :P
	srand(time(NULL));
	system("COLOR 0A");
	load(0);
	welcome();
}
