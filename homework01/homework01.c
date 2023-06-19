#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>



//네모 화면
int screen(char* screenBuf, int width, int height)
{
   int i = 0;
   int j = 0;

   while (j < height)
   {
      while (i < width + 1)
      {
         if (i == width)

            screenBuf[i + (j * (width + 1))] = '\n';

         else
         {
            if (i == 0 || i == (width - 1) || i == (width - 1) || j == 0 || j == (height - 1))

               screenBuf[i + (j * (width + 1))] = '#';

            else

               screenBuf[i + (j * (width + 1))] = ' ';
         }
         i = i + 1;

      }
      i = 0;
      j = j + 1;
   }

   screenBuf[height * (width + 1) - 1] = '\0';

   return 0;

}

//네모 상자에 문자열을 넣을 수 있게 도와주는
int writeStringToBuffer(const char* string, int x, int y, char* screenBuf, int width, int height)
{
   int pos = x + (y * (width + 1));
   int i = 0;

   while (string[i] != '\0')
   {
      screenBuf[pos + i] = string[i];
      i++;
   }
   return 0;
}
//---------------------------------------------------------------------

	int result=0;
	int betting_money=0;
	int money=100000;

    int player_Total = 0;
    int player_onecard = 0;
    int player_secritcard = 0;
    int player_newcard=0;

    int dealer_Total=0;
    int dealer_onecard = 0;
	int dealer_onecard2=0;
    int dealer_secritcard = 0;
    int dealer_newcard=1;
    int dealer_newcard2=0;
    char choice;


    // 플레이어와 딜러에게 초기 두 장의 카드를 나누는 함수
    int dealInitialCards() {
		player_onecard=0;
		player_secritcard=0;
		dealer_onecard=0;
		dealer_secritcard=0;
		
        player_onecard = (rand() % 11)+1;  // 랜덤한 합계로 플레이어의 초기 카드 합계 설정
        player_secritcard = (rand() % 11)+1;
        player_Total = player_onecard + player_secritcard;

		dealer_onecard = (rand() % 11)+1;   // 랜덤한 합계로 딜러의 초기 카드 합계 설정
        dealer_onecard2 += dealer_onecard;
		dealer_secritcard = (rand() % 11)+1;
        dealer_Total = dealer_onecard + dealer_secritcard;  //알단은 시크릿카드와 원카드를 토탈에 넣음

		// game_start_screen 함수 호출 시 인수 전달
    }

	int game_start_screen(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_onecard);
    	writeStringToBuffer(temp, 23, 1, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''|", 17, 3, screenBuf, width, height);
		writeStringToBuffer("|   | | ? |", 17, 4, screenBuf, width, height);
		sprintf(temp, "%d", dealer_onecard2);
		writeStringToBuffer(temp, 19, 4, screenBuf, width, height);
		writeStringToBuffer("|___| |___|", 17, 5, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''|", 3, 8, screenBuf, width, height);
		writeStringToBuffer("|   | |   |", 3, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_secritcard);
    	writeStringToBuffer(temp, 5, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_onecard);
    	writeStringToBuffer(temp, 11, 9, screenBuf, width, height);
		writeStringToBuffer("|___| |___|", 3, 10, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
		writeStringToBuffer(temp, 3, 12, screenBuf, width, height);


		printf("%s\n", screenBuf);

		return 0;
		}	

		int player_newcard_dealer_nocard(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_onecard);
    	writeStringToBuffer(temp, 23, 1, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''|", 17, 3, screenBuf, width, height);
		writeStringToBuffer("|   | | ? |", 17, 4, screenBuf, width, height);
		sprintf(temp, "%d", dealer_onecard2);
		writeStringToBuffer(temp, 19, 4, screenBuf, width, height);
		writeStringToBuffer("|___| |___|", 17, 5, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''| |'''|", 3, 8, screenBuf, width, height);
		writeStringToBuffer("|   | |   | |   |", 3, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_secritcard);
    	writeStringToBuffer(temp, 5, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_onecard);
    	writeStringToBuffer(temp, 11, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_newcard);
		writeStringToBuffer(temp, 17, 9, screenBuf, width, height);
		writeStringToBuffer("|___| |___| |___|", 3, 10, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
		writeStringToBuffer(temp, 3, 12, screenBuf, width, height);


		printf("%s\n", screenBuf);

		return 0;
		}

		int game_clear(){
		COORD Cur = { 0,0 };
		
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E A R-----------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------  A M E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G   M E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A   E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M   C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E   L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C   E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L   A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E   R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E A  ------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------  A M E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G   M E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A   E C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M   C L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E   L E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C   E A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L   A R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E   R------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E A  ------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("------------G A M E C L E A R------------\n\n");
		Sleep(100);
		
		return 0;
		}

		int game_over(){
		COORD Cur = { 0,0 };
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------  A M E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G   M E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A   E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M   O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E   V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O   E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V   R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V E  -------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------  A M E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G   M E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A   E O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M   O V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E   V E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O   E R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V   R-------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V E  -------------\n\n");
		Sleep(100);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		printf("-------------G A M E O V E R-------------\n\n");
		Sleep(100);
		
		return 0;
		}

		int player_newcard_dealer_newcard(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_onecard);
    	writeStringToBuffer(temp, 23, 1, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''| |'''|", 11, 3, screenBuf, width, height);
		writeStringToBuffer("|   | |   | | ? |", 11, 4, screenBuf, width, height);
		sprintf(temp, "%d", dealer_newcard);
		writeStringToBuffer(temp, 13, 4, screenBuf, width, height);
		sprintf(temp, "%d", dealer_onecard2);
		writeStringToBuffer(temp, 19, 4, screenBuf, width, height);
		writeStringToBuffer("|___| |___| |___|", 11, 5, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''| |'''|", 3, 8, screenBuf, width, height);
		writeStringToBuffer("|   | |   | |   |", 3, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_secritcard);
    	writeStringToBuffer(temp, 5, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_onecard);
    	writeStringToBuffer(temp, 11, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_newcard);
		writeStringToBuffer(temp, 17, 9, screenBuf, width, height);
		writeStringToBuffer("|___| |___| |___|", 3, 10, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
		writeStringToBuffer(temp, 3, 12, screenBuf, width, height);


		printf("%s\n", screenBuf);

		return 0;
		}

		int how_to_play2(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		writeStringToBuffer("dealer", 4, 1, screenBuf, width, height);
    	writeStringToBuffer("? /21", 23, 1, screenBuf, width, height);
		writeStringToBuffer(" new  scrit  one", 11, 2, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''| |'''|", 11, 3, screenBuf, width, height);
		writeStringToBuffer("|   | |   | | ? |", 11, 4, screenBuf, width, height);
		writeStringToBuffer("|___| |___| |___|", 11, 5, screenBuf, width, height);
		writeStringToBuffer(" one  scrit  new", 3, 7, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''| |'''|", 3, 8, screenBuf, width, height);
		writeStringToBuffer("|   | |   | |   |", 3, 9, screenBuf, width, height);
		writeStringToBuffer("|___| |___| |___|", 3, 10, screenBuf, width, height);

		writeStringToBuffer("? /21", 3, 12, screenBuf, width, height);
		writeStringToBuffer("total", 3, 13, screenBuf, width, height);
		writeStringToBuffer("player", 20, 13, screenBuf, width, height);


		printf("%s\n", screenBuf);

		return 0;
		}

		int player_nocard_dealer_newcard(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_onecard);
    	writeStringToBuffer(temp, 23, 1, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''| |'''|", 11, 3, screenBuf, width, height);
		writeStringToBuffer("|   | |   | | ? |", 11, 4, screenBuf, width, height);
		sprintf(temp, "%d", dealer_newcard);
		writeStringToBuffer(temp, 13, 4, screenBuf, width, height);
		sprintf(temp, "%d", dealer_onecard2);
		writeStringToBuffer(temp, 19, 4, screenBuf, width, height);
		writeStringToBuffer("|___| |___| |___|", 11, 5, screenBuf, width, height);
		writeStringToBuffer("|'''| |'''|", 3, 8, screenBuf, width, height);
		writeStringToBuffer("|   | |   |", 3, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_secritcard);
    	writeStringToBuffer(temp, 5, 9, screenBuf, width, height);
		sprintf(temp, "%d", player_onecard);
    	writeStringToBuffer(temp, 11, 9, screenBuf, width, height);
		writeStringToBuffer("|___| |___|", 3, 10, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
		writeStringToBuffer(temp, 3, 12, screenBuf, width, height);


		printf("%s\n", screenBuf);

		return 0;
		}

		int Player_Wins(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_Total);
    	writeStringToBuffer(temp, 12, 3, screenBuf, width, height);
		writeStringToBuffer("Player Wins", 9, 7, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
    	writeStringToBuffer(temp, 12, 11, screenBuf, width, height);
		


		printf("%s\n", screenBuf);

		return 0;
		}

		int dealer_Wins(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_Total);
    	writeStringToBuffer(temp, 12, 3, screenBuf, width, height);
		writeStringToBuffer("dealer Wins", 9, 7, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
    	writeStringToBuffer(temp, 12, 11, screenBuf, width, height);
		


		printf("%s\n", screenBuf);

		return 0;
		}

		int draw(char* screenBuf, int width, int height){

		//스크린을 먼저 띄운다
		screen(screenBuf, 30, 15);

		const char* a = "a";
		char temp[10];

		//임시저장소 temp에 값을 저장하고 불러옴.
		sprintf(temp, "%d/21", dealer_Total);
    	writeStringToBuffer(temp, 12, 3, screenBuf, width, height);
		writeStringToBuffer("a draw", 12, 7, screenBuf, width, height);
		sprintf(temp, "%d/21", player_Total);
    	writeStringToBuffer(temp, 12, 11, screenBuf, width, height);
		


		printf("%s\n", screenBuf);

		return 0;
		}

    // 카드를 한 장 더 받는 함수
    int dealCard() {
        return (rand() % 11) + 1;  // 1에서 13까지의 랜덤한 카드 값 반환
    }

    // 플레이어가 더 많은 카드를 요청하는 함수
    int hit() {
    player_newcard = dealCard();  // 한 장의 카드를 받음
    player_Total += player_newcard;  // 플레이어의 카드 합계에 추가
	}

    // 딜러의 턴을 처리하는 함수
    int dealerTurn() {
        dealer_newcard2 = 0;
        dealer_newcard = 0;

		srand(time(NULL));

        if (dealer_Total < 9) {                             //딜러의 카드가 9이하라면
        if(player_onecard > 17 && rand() % 100 < 70){       // 만약 딜러가 플레이어의 카드가 17이 넘은걸 안다면 받지 않고 넘긴다.
            dealer_newcard=0;
        }else{
        dealer_newcard = dealCard();                        //아니라면 카드를 받는다
        dealer_newcard2+=dealer_newcard;
		dealer_onecard += dealer_newcard;}                  // 딜러의 원카드에 받은 카드를 넣는다.
        
    } else if (dealer_Total <= 13 && rand() % 100 < 90) {
        if(player_onecard > 17 && rand() % 100 < 70){
            dealer_newcard=0;
        }else{
        dealer_newcard = dealCard();
		dealer_newcard2+=dealer_newcard;
        dealer_onecard += dealer_newcard;}

    } else if (dealer_Total <= 15 && rand() % 100 < 70) {
        if(player_onecard > 17 && rand() % 100 < 70){
            dealer_newcard=0;
        }else{
        dealer_newcard = dealCard();
		dealer_newcard2+=dealer_newcard;
        dealer_onecard += dealer_newcard;}

    } else if (dealer_Total <= 18 && rand() % 100 < 30) {
        if(player_onecard > 17 && rand() % 100 < 70){
            dealer_newcard=0;
        }else{
        dealer_newcard = dealCard();
		dealer_newcard2+=dealer_newcard;
        dealer_onecard += dealer_newcard;}
    }else if (dealer_Total >18 ){
        dealer_newcard = 0;
		dealer_newcard2+=dealer_newcard;
        dealer_onecard += dealer_newcard;
    }
    //이 행동이 끝나면
    dealer_Total = dealer_onecard + dealer_secritcard;  //딜러의 카드에 원카드와 시크릿카드를 합친다.
    // dealer_newcard2 += dealer_newcard;                  //임시 저장소인 딜러의 뉴카드2에 뉴카드 값을 넣어놓는다.
    }

    //중간결과
    void print() {

		char screen[450 + 1];
		int width = 30;
   		int height = 15;
   		int p = 0;
  		int q = 1;

		if((choice=='y' || choice=='Y') && dealer_newcard==0){
			player_newcard_dealer_nocard(screen, 30, 15);
			
		}else if((choice=='Y' || choice=='y') && dealer_newcard >=1){
			player_newcard_dealer_newcard(screen, 30, 15);
		}else if((choice=='N' || choice=='n') && dealer_newcard >=1){
			player_nocard_dealer_newcard(screen,30,15);
		}else if ((choice=='N' || choice=='n') && dealer_newcard == 0){
			game_start_screen(screen,30,15);
		}

    }

    // 결과를 출력하는 함수
    void printResult() {
		char screen[450 + 1];
		int width = 30;
   		int height = 15;
   		int p = 0;
  		int q = 1;

        if(player_Total == dealer_Total){
                draw(screen,30,15);
			money+=betting_money;
			betting_money=0;
        }else if (player_Total > 21) {
            if(player_Total < dealer_Total){
                Player_Wins(screen,30,15);
				money+=betting_money*2;
				betting_money=0;
            }else{
            dealer_Wins(screen,30,15);
			betting_money=0;
            }
        }else if (dealer_Total > 21) {
            if(player_Total > dealer_Total){
            dealer_Wins(screen,30,15);
				betting_money=0;
            }else{
            Player_Wins(screen,30,15);
			money+=betting_money*2;
			betting_money=0;
            }
        }else if (player_Total > dealer_Total) {
            Player_Wins(screen,30,15);
			money+=betting_money*2;
			betting_money=0;
        }else if (dealer_Total > player_Total) {
            dealer_Wins(screen,30,15);
			betting_money=0;
        }
    }
	
    //턴 정리
    int end(){

        printf("카드를 한 장 더 받으시겠습니까? (y/n): ");
        scanf(" %c", &choice);
        while(choice == 'y' || choice == 'Y'){
            hit();              //내차례
            dealerTurn();       //딜러차례
            print();            //중간결과
            printf("카드를 한 장 더 받으시겠습니까? (y/n): ");
            scanf(" %c", &choice);
        }if (choice == 'n' || choice == 'N') {
            dealerTurn();   //딜러차례
            if(dealer_newcard <= 0){
                    printResult();      // 결과 
					dealer_newcard=1;
					dealer_onecard2=0;
					
					

                }else{                  //딜러의 토탈이 17보다 작거나 딜러의 뉴카드가 0 보다 크다면 밑은 실행함.
                dealerTurn();   //딜러차례
                print();        //중간결과

                end();
                }
        }
    }

	//돈 베팅함수
	int betting(){

		char screen[450 + 1];
	int width = 30;
   	int height = 15;
   	int p = 0;
  	int q = 1;

	while (1) {

		if(money>=200000){
			game_clear();
			return 0;
		}else if(money<=0 && betting_money<=0){
			game_over();
			return 0;
		}

	
		printf("현재 자산: %d\n", money);
        printf("현재 배팅 금액: %d\n", betting_money);
        printf("배팅금액 증가: U\n");
        printf("배팅금액 감소: D\n");
        printf("완료: S\n");

        int betting_choice;
        scanf("%s", &betting_choice);

		if (betting_choice == 'u' || betting_choice == 'U') {
            if(money<=0){
				printf("금액이 부족합니다.\n");
			}
			else
            {betting_money+= 1000;
			money-=1000;
            printf("배팅금액이 1000 증가되었습니다.\n");}
		}else if (betting_choice == 'o' || betting_choice == 'O') {
            if(money<=0){
				printf("금액이 부족합니다.\n");
			}
			else
            {betting_money+= 100000;
			money-=100000;
            printf("배팅금액이 100000 증가되었습니다.\n");}
        } else if (betting_choice == 'd' || betting_choice == 'D') {
			if(betting_money<=0){
				printf("금액이 부족합니다.\n");
			}
			else
            {betting_money-= 1000;
			money+=1000;
            printf("배팅금액이 1000 감소되었습니다.\n");}
        } else if (betting_choice == 's' || betting_choice == 'S') {
			if(betting_money<=0){
				printf("배팅 금액이 부족합니다.\n");
			}
			else
            {printf("배팅이 완료되었습니다.\n");
			dealInitialCards();
			game_start_screen(screen, 30, 15);

        	end();
       		}
			
			}else {
            printf("잘못된 선택입니다.\n");
			
        }
		
        printf("\n");
	}
    
}

//시작 했을 때 보이는 화면
int main_screen(char* screenBuf, int width, int height)
{
	//스크린을 먼저 띄운다
	screen(screenBuf, 30, 15);

	const char* main = "main";
	writeStringToBuffer(".'.'.              .'.'.", 3, 3, screenBuf, width, height);
	writeStringToBuffer("'. .'  Black jack  '. .'", 3, 4, screenBuf, width, height);
	writeStringToBuffer("'                  '", 5, 5, screenBuf, width, height);
	writeStringToBuffer("'                  '", 5, 6, screenBuf, width, height);
	writeStringToBuffer("'                  '", 5, 7, screenBuf, width, height);
	writeStringToBuffer("'                  '", 5, 8, screenBuf, width, height);
	writeStringToBuffer("1)Game Start", 8, 8, screenBuf, width, height);
	writeStringToBuffer("2)How to play", 8, 9, screenBuf, width, height);
	writeStringToBuffer("3)exit", 8, 10, screenBuf, width, height);

	printf("%s\n", screenBuf);

	return 0;
}

int how_to_play()
{
		char screen[450 + 1];
		int width = 30;
   		int height = 15;
   		int p = 0;
  		int q = 1;

	printf("플레이어와 딜러 사이에서 진행되는 카드게임입니다.\n");
	printf("카드를 번갈아가며 받으면서딜러보다 21에 가깝게 \n");
	printf("숫자의 총합을 가져야합니다.\n");
	printf("승리: 카드의 총합이 딜러보다 21에 가까우면 승리\n");
	printf("주의: 카드의 총합이 21을 넘어서면 패배.\n");
	printf("주어진 돈 100000원을 모두 잃으면 게임 오버\n");
	printf("본 룰은 실제 블랙잭의 룰과 다를 수 있습니다.\n");

	how_to_play2(screen,30,15);
 
	return 0;
}

//메인 화면에서 메뉴 처리함수
int main_screen2(){

	char screen[450 + 1];
	int width = 30;
   	int height = 15;
   	int p = 0;
  	int q = 1;

	//메인 스크린을 스크린의 30의 15 자리에 넣는다?
	main_screen(screen, 30, 15);

	int main=0;
	int exit=0;
	int how=0;

	scanf("%d",&main);
	if (main==1){
	while (money > 0 || money < 200000){

		betting();
		}
		return 0;
	}

	if(main==2){
		//이 화면은 설명으로 바뀌어야함

		how_to_play();
		printf("Return to menu? (1.yes 2.no)\n");
		scanf("%d",&how);
		while(how==2){
			printf("Return to menu? (1.yes 2.no)\n");
			scanf("%d",&how);
		}
		main_screen2();
	}

	if(main==3){
	printf("Should I stop? (1.Yes 2.No)\n");
	scanf("%d", &exit);
		if(exit==1){
			return 0;
		}
		else{
			main_screen2();
		}
	
		return 0;
	}

}

int main()
{
	main_screen2();
	
}
