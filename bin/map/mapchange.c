#include<stdlib.h>
#include<stdio.h>
#include<string.h>
main(){
	char a[20][80];
	int i;
	FILE*fp;
	fp=fopen("map0.txt","r");
	for(i=0;i<20;i++)
	fgets(a[i],80,fp);
	fclose(fp);
	fp=fopen("maptest.txt","w");
	for(i=20;i>=0;i--)
	fprintf(fp,"%s",a[i]);
	fclose(fp);
}
