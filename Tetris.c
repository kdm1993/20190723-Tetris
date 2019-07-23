#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>

	void CursorView(char show)//커서숨기기
	{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole , &ConsoleCursor);
	}
	
	gotoxy(int x, int y)//gotoxy함수를 호출해올 기본함수.
	{   
	  COORD pos = {x, y};
	  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
	int Teduri();
	int tile_color_1 = 0,tile_color_2 = 0,tile_color_3 = 0;
	int count;
	int speed=100;
	int score=0;
	int level = 1;
	int gamestart = 0;
	int start = 0;
	int Game();
	int tile_type=1;
	int RandomTile();
	int End();
	int Gamecopy();
	int Clearner();
	int ChangeCheck();
	int tile = 0;
	int set[3];
	int game_x1=0, game_y1=0;
	int game_x2=0, game_y2=0;
	int game_x3=0, game_y3=0;
	int game_x4=0, game_y4=0;
	int game_x5=0, game_y5=0;
	int game_x6=0, game_y6=0;
	int game_x7=0, game_y7=0;
	int game_x8=0, game_y8=0;
	int end_color[40][23];
	int end[40][23];
	
	int main(void)
	{
		CursorView(0);
		int key, z, x, y;
		Teduri();
		gotoxy(17,10);
		printf("테 트 리 스");
		gotoxy(17,14);
		printf("시작 - Enter");
		while(1)
		{
			Sleep(10);
			if(kbhit()==1)
			{
				key = getch();
				if(key == 13 && gamestart == 0)
				{
					system("cls");
					Teduri();
					gamestart = 1;
					RandomTile();	
					GameCopy();
				}
				else if(key == 13 && gamestart == 1)
				{
					Clearner();
					game_x1 = game_x5;
					game_x2 = game_x6;
					game_x3 = game_x7;
					game_x4 = game_x8;
					game_y1 = game_y5;
					game_y2 = game_y6;
					game_y3 = game_y7;
					game_y4 = game_y8;
					count=speed-1;
					RandomTile();
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
					GameCopy();
					SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
					gotoxy(game_x1, game_y1);
					printf("▣");
					gotoxy(game_x2, game_y2);
					printf("▣");
					gotoxy(game_x3, game_y3);
					printf("▣");
					gotoxy(game_x4, game_y4);
					printf("▣");
					End();
				}
				if(key == 224 && gamestart==1)
				{
					key = getch();
					if(key==75) 
					{ //왼쪽 화살표
						z = 1;
						if((game_x1 >=9) &&
						(game_x2 >=9) &&
						(game_x3 >=9) &&
						(game_x4 >=9))
						{
							if((end[game_x1-2][game_y1] != 1) &&
							(end[game_x2-2][game_y2] != 1) && 
							(end[game_x3-2][game_y3] != 1) && 
							(end[game_x4-2][game_y4] != 1))
							{
								Clearner();
								game_x1-=2;
								game_x2-=2;
								game_x3-=2;
								game_x4-=2;
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
								GameCopy();
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
								gotoxy(game_x1, game_y1);
								printf("▣");
								gotoxy(game_x2, game_y2);
								printf("▣");
								gotoxy(game_x3, game_y3);
								printf("▣");
								gotoxy(game_x4, game_y4);
								printf("▣");
								End();
							}
						}
					} 
					else if(key==72) 
					{ // 위쪽 화살표 
						z = 2;
						tile_type++;
						if(tile_type==5)
						{
							tile_type = 1;
						}
						ChangeCheck();
						RandomTile();
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
						GameCopy();
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
						gotoxy(game_x1, game_y1);
						printf("▣");
						gotoxy(game_x2, game_y2);
						printf("▣");
						gotoxy(game_x3, game_y3);
						printf("▣");
						gotoxy(game_x4, game_y4);
						printf("▣");
						End();				
					} 
					else if(key==80) 
					{ // 아래쪽 화살표 
						z = 3;
						Clearner();
						game_y1++;
						game_y2++;
						game_y3++;
						game_y4++;
						count = 0;
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
						GameCopy();
						SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
						gotoxy(game_x1, game_y1);
						printf("▣");
						gotoxy(game_x2, game_y2);
						printf("▣");
						gotoxy(game_x3, game_y3);
						printf("▣");
						gotoxy(game_x4, game_y4);
						printf("▣");
						End();
					} 
					else if(key==77) 
					{ // 오른쪽 화살표 
						z = 4;
						if((game_x1 <= 35) &&
						(game_x2 <= 35) &&
						(game_x3 <= 35) &&
						(game_x4 <= 35))
						{
							if((end[game_x1+2][game_y1] != 1) &&
							(end[game_x2+2][game_y2] != 1) && 
							(end[game_x3+2][game_y3] != 1) && 
							(end[game_x4+2][game_y4] != 1))
							{
								Clearner();
								game_x1+=2;
								game_x2+=2;
								game_x3+=2;
								game_x4+=2;
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
								GameCopy();
								SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
								gotoxy(game_x1, game_y1);
								printf("▣");
								gotoxy(game_x2, game_y2);
								printf("▣");
								gotoxy(game_x3, game_y3);
								printf("▣");
								gotoxy(game_x4, game_y4);
								printf("▣");
								End();
							}
						}
					}
				}
			}
			Game();		
		} 
	}
	int Teduri()
	{
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);
		int x,y;
		for(x=1; x<24; x++)
		{
			gotoxy(5, x);
			printf("▣");
			gotoxy(39, x);
			printf("▣");	
		}
		gotoxy(5,0);
		printf("▣▣▣▣                    ▣▣▣▣");
		gotoxy(5,24);
		printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣");
		// 6 ~ 38 x좌표
		// 1 ~ 23 y좌표
		gotoxy(46,17);
		printf("LEVEL - %d", level);
		gotoxy(46,19);
		printf("SCORE - %d", score);
		gotoxy(44,0);
		printf("┏━Next━┓");
		gotoxy(44,6);
		printf("┗━━━━┛");
		gotoxy(44,8);
		printf("┏━━━━┓");
		gotoxy(44,14);
		printf("┗━━━━┛");
		for(x=1; x<6; x++)
		{
			gotoxy(44,x);
			printf("┃");
			gotoxy(54,x);
			printf("┃");
			gotoxy(44,x+8);
			printf("┃");
			gotoxy(54,x+8);
			printf("┃");
		}
	}
	int Game()
	{
		int x;
		if(gamestart == 1)
		{
			count++;
			if(count==speed)
			{
				Clearner();
				game_y1++;
				game_y2++;
				game_y3++;
				game_y4++;
				count=0;
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
				GameCopy();
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
				gotoxy(game_x1, game_y1);
				printf("▣");
				gotoxy(game_x2, game_y2);
				printf("▣");
				gotoxy(game_x3, game_y3);
				printf("▣");
				gotoxy(game_x4, game_y4);
				printf("▣");
				End();
			}
		}
	
	}
	int ChangeCheck()
	{
		int fake_x1=0, fake_y1=0;
		int fake_x2=0, fake_y2=0;
		int fake_x3=0, fake_y3=0;
		int fake_x4=0, fake_y4=0;
		
		fake_x1 = game_x1;
		fake_x2 = game_x2;
		fake_x3 = game_x3;
		fake_x4 = game_x4;
		fake_y1 = game_y1;
		fake_y2 = game_y2;
		fake_y3 = game_y3;
		fake_y4 = game_y4;
		
		if(set[0] == 0)
		{
			if(tile_type == 1)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 -= -2;
				fake_y1 -= -3;
				fake_y2 -= -2;
				fake_y3 -= 0;
				fake_y4 -= -1;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 4;
				fake_x2 += 2;
				fake_x3 += 0;
				fake_x4 -= 2;
				fake_y1 -= 3;
				fake_y2 -= 2;
				fake_y3 -= 0;
				fake_y4 -= 1;
			}
			else if(tile_type == 3)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 -= -2;
				fake_y1 -= -3;
				fake_y2 -= -2;
				fake_y3 -= 0;
				fake_y4 -= -1;
			}
			else if(tile_type == 4)
			{
				fake_x1 += 4;
				fake_x2 += 2;
				fake_x3 += 0;
				fake_x4 -= 2;
				fake_y1 -= 3;
				fake_y2 -= 2;
				fake_y3 -= 0;
				fake_y4 -= 1;
			}
		}
		else if(set[0] == 0)
		{
			if(tile_type == 1)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 += 2;
				fake_y1 += 3;
				fake_y2 += 2;
				fake_y3 += 0;
				fake_y4 += 1;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 4;
				fake_x2 += 2;
				fake_x3 += 0;
				fake_x4 += -2;
				fake_y1 += -3;
				fake_y2 += -2;
				fake_y3 += 0;
				fake_y4 += -1;
			}
			else if(tile_type == 3)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 += 2;
				fake_y1 += 3;
				fake_y2 += 2;
				fake_y3 += 0;
				fake_y4 += 1;
			}
			else if(tile_type == 4)
			{
				fake_x1 += 4;
				fake_x2 += 2;
				fake_x3 += 0;
				fake_x4 += -2;
				fake_y1 += -3;
				fake_y2 += -2;
				fake_y3 += 0;
				fake_y4 += -1;
			}
		}
		else if(set[0] == 2)
		{
			if(tile_type == 1)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 += -2;
				fake_y1 += 0;
				fake_y2 += 1;
				fake_y3 += 2;
				fake_y4 += -1;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += 4;
				fake_y1 += -2;
				fake_y2 += -1;
				fake_y3 += 0;
				fake_y4 += -1;
			}
			else if(tile_type == 3)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += 0;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += 2;
			}
			else if(tile_type == 4)
			{
				fake_x1 += 0;
				fake_x2 += 2;
				fake_x3 += 4;
				fake_x4 += -2;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += 0;
			}
		}
		else if(set[0] == 3)
		{
			if(tile_type == 1)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 += 2;
				fake_y1 += 0;
				fake_y2 += 1;
				fake_y3 += 2;
				fake_y4 += 1;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += 0;
				fake_y1 += -2;
				fake_y2 += -1;
				fake_y3 += 0;
				fake_y4 += 1;
			}
			else if(tile_type == 3)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += -4;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += 0;
			}
			else if(tile_type == 4)
			{
				fake_x1 += 0;
				fake_x2 += 2;
				fake_x3 += 4;
				fake_x4 += 2;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += -2;
			}
		}
		else if(set[0] == 4)
		{
			if(tile_type == 1)
			{
				fake_x1 += -2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += 0;
				fake_y1 += 2;
				fake_y2 += 1;
				fake_y3 += 0;
				fake_y4 += -1;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += 2;
				fake_x4 += 0;
				fake_y1 += -2;
				fake_y2 += -1;
				fake_y3 += 0;
				fake_y4 += 1;
			}
			else if(tile_type == 3)
			{
				fake_x1 += -2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += 0;
				fake_y1 += 2;
				fake_y2 += 1;
				fake_y3 += 0;
				fake_y4 += -1;
			}
			else if(tile_type == 4)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += 2;
				fake_x4 += 0;
				fake_y1 += -2;
				fake_y2 += -1;
				fake_y3 += 0;
				fake_y4 += 1;
			}
		}
		else if(set[0] == 5)
		{
			if(tile_type == 1)
			{
				fake_x1 += -2;
				fake_x2 += 0;
				fake_x3 += 2;
				fake_x4 += 2;
				fake_y1 += 0;
				fake_y2 += 1;
				fake_y3 += 2;
				fake_y4 += 0;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += 2;
				fake_y1 += -2;
				fake_y2 += -1;
				fake_y3 += 0;
				fake_y4 += 0;
			}
			else if(tile_type == 3)
			{
				fake_x1 += 2;
				fake_x2 += 0;
				fake_x3 += -2;
				fake_x4 += -2;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += 1;
			}
			else if(tile_type == 4)
			{
				fake_x1 += -2;
				fake_x2 += 0;
				fake_x3 += 2;
				fake_x4 += -2;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += -1;
			}
		}
		else if(set[0] == 6)
		{
			if(tile_type == 1)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 += 2;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += 1;
				fake_y4 += 0;
			}
			else if(tile_type == 2)
			{
				fake_x1 += 4;
				fake_x2 += 2;
				fake_x3 += 0;
				fake_x4 += -2;
				fake_y1 += -1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += 0;
			}
			else if(tile_type == 3)
			{
				fake_x1 += -4;
				fake_x2 += -2;
				fake_x3 += 0;
				fake_x4 += 2;
				fake_y1 += 1;
				fake_y2 += 0;
				fake_y3 += 1;
				fake_y4 += 0;
			}
			else if(tile_type == 4)
			{
				fake_x1 += 4;
				fake_x2 += 2;
				fake_x3 += 0;
				fake_x4 += -2;
				fake_y1 += -1;
				fake_y2 += 0;
				fake_y3 += -1;
				fake_y4 += 0;
			}
		}
		
		int check = 1;
		int x,y;
		for(x=5; x<38; )
		{
			x+=2;
			for(y=1; y<24; y++)
			{
				if(end[x][y] == 1)
				{
					if((y == fake_y1) && (x == fake_x1)||
					(y == fake_y2) && (x == fake_x2) ||
					(y == fake_y3) && (x == fake_x3) ||
					(y == fake_y4) && (x == fake_x4))
					{
						check = 0;
					}
				}
			}
		}
		if((fake_x1<=6 || fake_x2<=6 || fake_x3<=6 || fake_x4<=6)
		|| (fake_x1>=38 || fake_x2>=38 || fake_x3>=38 || fake_x4>=38)
		|| (fake_y1<0 || fake_y2<0 || fake_y3<0 || fake_y4<0))
		{
			check = 0;
		}
		if(check == 1)
		{
			Clearner();
			game_x1 = fake_x1;
			game_x2 = fake_x2;
			game_x3 = fake_x3;
			game_x4 = fake_x4;
			game_y1 = fake_y1;
			game_y2 = fake_y2;
			game_y3 = fake_y3;
			game_y4 = fake_y4;
			Game();
		}
		else if(check == 0)
		{
			tile_type--;
		}
	}
	int End()
	{
		int x,y=0,tile_count=0;
		if(game_y1>=24 || game_y2>=24 || game_y3>=24 || game_y4>=24)
		{
			end_color[game_x1][game_y1-1] = tile_color_1;
			end_color[game_x2][game_y2-1] = tile_color_1;
			end_color[game_x3][game_y3-1] = tile_color_1;
			end_color[game_x4][game_y4-1] = tile_color_1;
			end[game_x1][game_y1-1] = 1;
			end[game_x2][game_y2-1] = 1;
			end[game_x3][game_y3-1] = 1;
			end[game_x4][game_y4-1] = 1;
			Clearner();
			Teduri();
			start = 0;
			set[0] = set[1];
			set[1] = set[2];
			set[2] = rand()%7;
			tile_type = 1;
			RandomTile();
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
			gotoxy(game_x1, game_y1);
			printf("▣");
			gotoxy(game_x2, game_y2);
			printf("▣");
			gotoxy(game_x3, game_y3);
			printf("▣");
			gotoxy(game_x4, game_y4);
			printf("▣");
		}
		if(gamestart==1)
		{
			for(; y<24; y++)
			{
				tile_count = 0;
				for(x=5; x<36;)
				{
					x+=2;
					if(end[x][y] == 1)
					{
						if(y==0 && gamestart==1)
						{
							gamestart = 0;
							system("cls");
							Teduri();
							gotoxy(18,10);
							printf("Game Over");
							gotoxy(16,14);
							printf("재시작 - Enter");
							for(y=0; y<24; y++)
							{
								for(x=5; x<36;)
								{
									x+=2;
									end[x][y]=0;
									end_color[40][23]=0;
								}
							}
							speed=100;
							score=0;
							level = 1;
							gamestart = 0;
							start = 0;
							tile_type=1;
							game_x1=0, game_y1=0;
							game_x2=0, game_y2=0;
							game_x3=0, game_y3=0;
							game_x4=0, game_y4=0;
							game_x5=0, game_y5=0;
							game_x6=0, game_y6=0;
							game_x7=0, game_y7=0;
							game_x8=0, game_y8=0;
							tile=0;
						}
						tile_count++;
						if((y == game_y1) && (x == game_x1)||
						(y == game_y2) && (x == game_x2) ||
						(y == game_y3) && (x == game_x3) ||
						(y == game_y4) && (x == game_x4))
						{
							end_color[game_x1][game_y1-1] = tile_color_1;
							end_color[game_x2][game_y2-1] = tile_color_1;
							end_color[game_x3][game_y3-1] = tile_color_1;
							end_color[game_x4][game_y4-1] = tile_color_1;
							end[game_x1][game_y1-1] = 1;
							end[game_x2][game_y2-1] = 1;
							end[game_x3][game_y3-1] = 1;
							end[game_x4][game_y4-1] = 1;
							Clearner();
							start = 0;
							set[0] = set[1];
							set[1] = set[2];
							set[2] = rand()%7;
							tile_type = 1;
							RandomTile();
							count = speed-1;
						}
						if(gamestart==1)
						{
							SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), end_color[x][y]);
							gotoxy(x, y);
							printf("▣");	
						}
						
					}
					if(tile_count==16)
					{
						score += 10;
						switch(score)
						{
							case 100:
								speed = 90;
								level = 2;
								break;
							case 200:
								speed = 80;
								level = 3;
								break;
							case 300:
								speed = 70;
								level = 4;
								break;
							case 400:
								speed = 60;
								level = 5;
								break;
							case 500:
								speed = 50;
								level = 6;
								break;
							case 600:
								speed = 40;
								level = 7;
								break;
							case 700:
								speed = 30;
								level = 8;
								break;
							case 850:
								speed = 20;
								level = 9;
								break;
							case 1000:
								speed = 10;
								level = 10;
								break;
						}
						int tile_count_y;
						for(tile_count_y=y; tile_count_y>0; tile_count_y--)
						{
							for(x=5; x<36;)
							{
								x+=2;
								end_color[x][tile_count_y] = end_color[x][tile_count_y-1];
								end[x][tile_count_y] = end[x][tile_count_y-1];
								if(tile_count_y == y)
								{
									gotoxy(x,tile_count_y);
									printf(" ");
								}
								else
								{
									if(end[x][tile_count_y] == 0)
									{
										gotoxy(x,tile_count_y);
										printf(" ");
									}
									else if(end[x][tile_count_y] == 1)
									{
										SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), end_color[x][tile_count_y]);
										gotoxy(x,tile_count_y);
										printf("▣");
									}
								}
							}
						}
						count = speed-1;	
					}
				}
			}	
		}
		
	}
	int RandomTile()
	{
		int randomtile;
		
		while(tile<3)
		{
			srand(time(NULL));
			randomtile = rand()%7;
			set[tile] = randomtile;
			tile++;
		}
		if(set[0] == 0 && start == 0)
		{
			tile_color_1 = 12;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 19;
			game_x4 = 21;
			game_y1 = 0;
			game_y2 = 0;
			game_y3 = 0;
			game_y4 = 0;
		}
		else if(set[0] == 1 && start == 0)
		{
			tile_color_1 = 3;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 15;
			game_x4 = 17;
			game_y1 = 1;
			game_y2 = 1;
			game_y3 = 0;
			game_y4 = 0;
		}
		else if(set[0] == 2 && start == 0)
		{
			tile_color_1 = 14;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 19;
			game_x4 = 15;
			game_y1 = 1;
			game_y2 = 1;
			game_y3 = 1;
			game_y4 = 0;
		}
		else if(set[0] == 3 && start == 0)
		{
			tile_color_1 = 10;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 19;
			game_x4 = 19;
			game_y1 = 1;
			game_y2 = 1;
			game_y3 = 1;
			game_y4 = 0;
		}
		else if(set[0] == 4 && start == 0)
		{
			tile_color_1 = 11;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 17;
			game_x4 = 19;
			game_y1 = 1;
			game_y2 = 1;
			game_y3 = 0;
			game_y4 = 0;
		}
		else if(set[0] == 5 && start == 0)
		{
			tile_color_1 = 9;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 19;
			game_x4 = 17;
			game_y1 = 1;
			game_y2 = 1;
			game_y3 = 1;
			game_y4 = 0;
		}
		else if(set[0] == 6 && start == 0)
		{
			tile_color_1 = 13;
			game_x1 = 15;
			game_x2 = 17;
			game_x3 = 17;
			game_x4 = 19;
			game_y1 = 0;
			game_y2 = 0;
			game_y3 = 1;
			game_y4 = 1;
		}
		if(gamestart==1)
		{
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), tile_color_1);
			gotoxy(game_x1, game_y1);
			printf("▣");
			gotoxy(game_x2, game_y2);
			printf("▣");
			gotoxy(game_x3, game_y3);
			printf("▣");
			gotoxy(game_x4, game_y4);
			printf("▣");	
		}
		start = 1;
		int x;
		if(gamestart == 1)
		{
			for(x=46; x<54; x++)
			{
				gotoxy(x, 1);
				printf(" ");
				gotoxy(x, 2);
				printf(" ");
				gotoxy(x, 3);
				printf(" ");
				gotoxy(x, 4);
				printf(" ");
				gotoxy(x, 9);
				printf(" ");
				gotoxy(x, 10);
				printf(" ");
				gotoxy(x, 11);
				printf(" ");
				gotoxy(x, 12);
				printf(" ");	
			}
			if(set[1] == 0)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
				gotoxy(46,3);
				printf("▣");
				gotoxy(48,3);
				printf("▣");
				gotoxy(50,3);
				printf("▣");
				gotoxy(52,3);
				printf("▣");
			}
			else if(set[1] == 1)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
				gotoxy(48,4);
				printf("▣");
				gotoxy(50,4);
				printf("▣");
				gotoxy(48,3);
				printf("▣");
				gotoxy(50,3);
				printf("▣");
			}
			else if(set[1] == 2)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
				gotoxy(47,4);
				printf("▣");
				gotoxy(49,4);
				printf("▣");
				gotoxy(51,4);
				printf("▣");
				gotoxy(47,3);
				printf("▣");
			}
			else if(set[1] == 3)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
				gotoxy(47,4);
				printf("▣");
				gotoxy(49,4);
				printf("▣");
				gotoxy(51,4);
				printf("▣");
				gotoxy(51,3);
				printf("▣");
			}
			else if(set[1] == 4)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
				gotoxy(47,4);
				printf("▣");
				gotoxy(49,4);
				printf("▣");
				gotoxy(49,3);
				printf("▣");
				gotoxy(51,3);
				printf("▣");
			}
			else if(set[1] == 5)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 9);
				gotoxy(47,4);
				printf("▣");
				gotoxy(49,4);
				printf("▣");
				gotoxy(49,3);
				printf("▣");
				gotoxy(51,4);
				printf("▣");
			}
			else if(set[1] == 6)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
				gotoxy(47,3);
				printf("▣");
				gotoxy(49,4);
				printf("▣");
				gotoxy(49,3);
				printf("▣");
				gotoxy(51,4);
				printf("▣");
			}
			if(set[2] == 0)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12);
				gotoxy(46,11);
				printf("▣");
				gotoxy(48,11);
				printf("▣");
				gotoxy(50,11);
				printf("▣");
				gotoxy(52,11);
				printf("▣");
			}
			else if(set[2] == 1)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 3);
				gotoxy(48,12);
				printf("▣");
				gotoxy(50,12);
				printf("▣");
				gotoxy(48,11);
				printf("▣");
				gotoxy(50,11);
				printf("▣");
			}
			else if(set[2] == 2)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 14);
				gotoxy(47,12);
				printf("▣");
				gotoxy(49,12);
				printf("▣");
				gotoxy(51,12);
				printf("▣");
				gotoxy(47,11);
				printf("▣");
			}
			else if(set[2] == 3)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 10);
				gotoxy(47,12);
				printf("▣");
				gotoxy(49,12);
				printf("▣");
				gotoxy(51,12);
				printf("▣");
				gotoxy(51,11);
				printf("▣");
			}
			else if(set[2] == 4)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 11);
				gotoxy(47,12);
				printf("▣");
				gotoxy(49,12);
				printf("▣");
				gotoxy(49,11);
				printf("▣");
				gotoxy(51,11);
				printf("▣");
			}
			else if(set[2] == 5)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 9);
				gotoxy(47,12);
				printf("▣");
				gotoxy(49,12);
				printf("▣");
				gotoxy(49,11);
				printf("▣");
				gotoxy(51,12);
				printf("▣");
			}
			else if(set[2] == 6)
			{
				SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 13);
				gotoxy(47,11);
				printf("▣");
				gotoxy(49,12);
				printf("▣");
				gotoxy(49,11);
				printf("▣");
				gotoxy(51,12);
				printf("▣");
			}
		} 
	}
	int GameCopy()
	{
		gotoxy(game_x5, game_y5-1);
		printf(" ");
		gotoxy(game_x6, game_y6-1);
		printf(" ");
		gotoxy(game_x7, game_y7-1);
		printf(" ");
		gotoxy(game_x8, game_y8-1);
		printf(" ");
		game_x5 = game_x1;
		game_x6 = game_x2;
		game_x7 = game_x3;
		game_x8 = game_x4;
		game_y5 = game_y1;
		game_y6 = game_y2;
		game_y7 = game_y3;
		game_y8 = game_y4;
		
		int y;
		
		for(y=1; y<24; y++)
		{
			game_y5++;
			game_y6++;
			game_y7++;
			game_y8++;
			if(end[game_x5][game_y5+1] == 1 ||
			end[game_x6][game_y6+1] == 1 ||
			end[game_x7][game_y7+1] == 1 ||
			end[game_x8][game_y8+1] == 1 && (game_y5<=23 && game_y6<=23 && game_y7<=23 && game_y8<=23))
			{
				gotoxy(game_x5, game_y5);
				printf("□");
				gotoxy(game_x6, game_y6);
				printf("□");
				gotoxy(game_x7, game_y7);
				printf("□");
				gotoxy(game_x8, game_y8);
				printf("□");
				Teduri();
				y = 24;
			}
			else if(game_y5>=24 || game_y6>=24 || game_y7>=24 || game_y8>=24)
			{
				gotoxy(game_x5, game_y5-1);
				printf("□");
				gotoxy(game_x6, game_y6-1);
				printf("□");
				gotoxy(game_x7, game_y7-1);
				printf("□");
				gotoxy(game_x8, game_y8-1);
				printf("□");
				Teduri();
				y = 24;
			}
		}
	}
	int Clearner()
	{
		gotoxy(game_x1, game_y1);
		printf(" ");
		gotoxy(game_x2, game_y2);
		printf(" ");
		gotoxy(game_x3, game_y3);
		printf(" ");
		gotoxy(game_x4, game_y4);
		printf(" ");
		gotoxy(game_x5, game_y5);
		printf(" ");
		gotoxy(game_x6, game_y6);
		printf(" ");
		gotoxy(game_x7, game_y7);
		printf(" ");
		gotoxy(game_x8, game_y8);
		printf(" ");
	}
