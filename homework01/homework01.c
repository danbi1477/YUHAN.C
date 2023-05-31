#include <stdio.h>
#include <string.h>


int How_to_play()
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
			else if (a > 99 && a < 117) {
        	strncpy(&sc[99], "Card game between", 17);
			}
			else if (a > 130 && a < 149) {
        	strncpy(&sc[130], "player and dealer.", 18);
			}

			else if (a > 192 && a < 209) {
        	strncpy(&sc[192], "take turns accepting cards", 26);
			}

			else if (a > 250 && a < 281) {
        	strncpy(&sc[250], "A person whose total number of", 27);
			}
			else if (a > 280 && a < 311) {
        	strncpy(&sc[280], "of cards is close to 21 wins.", 29);
			}

			else if (a > 346 && a < 366) {
        	strncpy(&sc[346], "The total number of", 19);
			}
			else if (a > 375 && a < 400) {
        	strncpy(&sc[375], "cards must not exceed 21", 24);
			}
			}
		a=a+1;
	}
	sc[434]='\0';
	printf("%s",sc);
}

int game_start()
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
        	strncpy(&sc[134], "Game Start ", 20);
			}
			}
		a=a+1;
	}
	sc[434]='\0';
	printf("%s",sc);
}


int betting()
{
	int betting=0;
	int money=1000000;
	while (1) {
		printf("현재 자산: %d\n", money);
        printf("현재 배탕 금액: %d\n", betting);
        printf("1. 배팅금액 증가\n");
        printf("2. 배팅금액 감소\n");
        printf("3. 완료\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            betting += 100;
			money-=100;
            printf("배팅금액이 100 증가되었습니다.\n");
        } else if (choice == 2) {
			if(betting<=0){
				printf("금액이 부족합니다.\n");
			}
			else
            {betting-= 100;
			money+=100;
            printf("배팅금액이 100 감소되었습니다.\n");}
        } else if (choice == 3) {
			if(betting<=0){
				printf("배팅 금액이 부족합니다.\n");
			}
			else
            {printf("배팅이 완료되었습니다.\n");
			game_start();
			return 0;}
        } else {
            printf("잘못된 선택입니다.\n");
        }

        printf("\n");
    }

    return 0;
    
}

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
				sc[a]='=';
			}
			else if (a>=401){
				sc[a]='=';
			}
			else if (a > 133 && a < 144) {
        	strncpy(&sc[134], "Black Jack ", 20);
			}
			else if (a > 255 && a < 268) {
        	strncpy(&sc[253], "1)GAME START", 12);
			}
			else if (a > 284 && a < 297) {
        	 strncpy(&sc[284], "2)How to play", 13);
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
	int exit=0;
	int how=0;

	scanf("%d",&main);
	if (main==1){
	betting();
	}

	if(main==2){
		How_to_play();
		printf("Return to menu? (1.yes 2.no)\n");
		scanf("%d",&how);
		while(how==2){
			printf("Return to menu? (1.yes 2.no)\n");
			scanf("%d",&how);
		}
		main_screen();
	}

	if(main==3){
	printf("Should I stop? (1.Yes 2.No)\n");
	scanf("%d", &exit);
		if(exit==1){
			return 0;
		}
		else{
			main_screen();
		}
	
		return 0;
	}

}

int main()
{
	main_screen();
}