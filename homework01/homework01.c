#include <stdio.h>
#include <string.h>

int main_screen()
{
	char sc[465];
	int a = 0;

	while(a < 465)
	{
		if(a %31 == 30){
			sc[a]='\n';
		}
		else{
			sc[a] = ' ';
			if(a%31==0){
				sc[a]='|';
			}
			else if (a%31==29){
				sc[a]='|';
			}
			else if (a<=28){
				sc[a]='-';
			}
			else if (a>=401){
				sc[a]='_';
			}
			else if (a > 133 && a < 144) {
        	strncpy(&sc[134], "Black Jack ", 20);
			}
			else if (a > 253 && a < 266) {
        	strncpy(&sc[253], "1)GAME START", 12);
			}
			else if (a > 284 && a < 310) {
        	 strncpy(&sc[284], "2)How To Play The Game", 22);
			}
			else if (a > 315 && a < 321) {
        	strncpy(&sc[315], "3)exit", 6);
			}
		
			}
		a=a+1;
	}
	sc[434]='\0';
	return 0;
}

int How_To_Play_The_Game()
{
	char sc[465];
	int a = 0;

	while(a < 465)
	{
		if(a %31 == 30){
			sc[a]='\n';
		}
		else{
			sc[a] = ' ';
			if(a%31==0){
				sc[a]='|';
			}
			else if (a%31==29){
				sc[a]='|';
			}
			else if (a<=28){
				sc[a]='-';
			}
			else if (a>=401){
				sc[a]='_';
			}
			else if (a > 72 && a < 83) {
        	strncpy(&sc[72], "Black Jack ", 20);
			}
		}
		a=a+1;
	}
	sc[434]='\0';
}

int main()
{
	char sc[465];
	int a = 0;

	while(a < 465)
	{
		if(a %31 == 30){
			sc[a]='\n';
		}
		else{
			sc[a] = ' ';
			if(a%31==0){
				sc[a]='|';
			}
			else if (a%31==29){
				sc[a]='|';
			}
			else if (a<=28){
				sc[a]='=';
			}
			else if (a>=401){
				sc[a]='=';
			}
			else if (a > 133 && a < 144) {
        	strncpy(&sc[134], "Black Jack ", 11);
			}
			else if (a > 253 && a < 266) {
        	strncpy(&sc[253], "1)GAME START", 12);
			}
			else if (a > 284 && a < 310) {
        	 strncpy(&sc[284], "2)How To Play The Game", 22);
			 }
			else if (a > 315 && a < 321) {
        	strncpy(&sc[315], "3)exit", 6);
			}
			}
			a=a+1;
	}
	sc[434]='\0';
	printf("%s",sc);

	int main=0;
	int how=0;
	
	scanf("%s",&main);
	if (main==1)
	{
	main_screen();
	scanf("%d", &main);
	}
	if(main==2)
	{
	How_To_Play_The_Game();
	printf("return to menu? (1.Yes 2.No)");
	scanf("%d",&how);

	while(how==2) {
	How_To_Play_The_Game();
	printf("return to menu? (1.Yes 2.No)");
	scanf("%d", &how);
	}
	}
        return 0;
}