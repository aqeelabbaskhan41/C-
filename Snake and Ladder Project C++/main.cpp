#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctime>
#include<fstream>
using namespace std;

void gotoRowCol(int rpos, int cpos)
{
    int xpos = cpos, ypos = rpos;
    COORD scrn;
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOutput, scrn);
}

void print_Box(int r, int c, int rdim, int cdim, char sym)
{  // Print rows
    for (int a = 0; a <= 10; a++)
    {
        for (int i = 0; i <= cdim * 10; i++)
        {
            gotoRowCol(r, i);
            cout << sym;
        }
        r = r + rdim;
    }
   // Print columns
    for (int a = 0; a <= 10; a++)
    {
        for (int i = 0; i <= rdim * 10; i++)
        {
            gotoRowCol(i, c);
            cout << sym;
        }
        c = c + cdim;
    }
}
void print_in_Box(int r, int c, int rdim, int cdim, int num)
{
    for (int i = 1; i <= 10; i++)
    {
        int col = c;
        for (int j = 1; j <= 10; j++)
        {
            gotoRowCol(r + (rdim / 2), col + (cdim / 2));
            cout << num;
            col = col + cdim;
            num--;
        }
        r = r + rdim;
    }
}
void print_Board(int rdim, int cdim)
{
    char sym = 219;
    int r = 0, c = 0, num = 100;
    print_Box(r, c, rdim, cdim, sym);
    print_in_Box(r, c, rdim, cdim, num);
     gotoRowCol(10,130);
     cout<<"Snakes:";
       gotoRowCol(12,130);
       cout<<"16----->6"<<endl;
       gotoRowCol(14,130);
       cout<<"50----->35"<<endl;
       gotoRowCol(16,130);
       cout<<"67----->33"<<endl;
       gotoRowCol(18,130);
       cout<<"98----->53"<<endl;
    gotoRowCol(20,130);
    cout<<"Laders:"<<endl;
       gotoRowCol(22,130);
       cout<<"11----->34"<<endl;
       gotoRowCol(24,130);
       cout<<"39----->61"<<endl;
       gotoRowCol(26,130);
       cout<<"69----->84"<<endl;
       gotoRowCol(28,130);
       cout<<"80----->94"<<endl;
}

int Roll_Dice()
{
    /*while(!kbhit())
    {
    gotoRowCol(43 , 135);

       int dic = rand() % 6 + 1;
       cout<<dic;
    }*/
     // Generating random number at current time to solve issue of fixed roll
    srand(time(NULL));
    int dice = rand() % 6 + 1;
    return dice;
}

int moving_player(int rdim, int cdim,int p,int turn)
{
    float sc_jump;
    int p_rem=p%10;
    int r_check;
 if(p<=10)
  {
     r_check=10;
  }
   else if (p>10&&p<=20)
    {
        r_check=9;
    }
    else if (p>20&&p<=30)
    {
        r_check=8;
    }
    else if (p>30&&p<=40)
    {
        r_check=7;
    }
    else if (p>40&&p<=50)
    {
        r_check=6;
    }
    else if (p>50&&p<=60)
    {
        r_check=5;
    }
    else if (p>60&&p<=70)
    {
        r_check=4;
    }
    else if (p>70&&p<=80)
    {
        r_check=3;
    }
    else if (p>80&&p<=90)
    {
        r_check=2;
    }
    else if (p>90&&p<=100)
    {
        r_check=1;
    }
    if(p_rem==0)
    {
        p_rem=10;
    }
    int r = (rdim * r_check) - (rdim/3);
    int c = (cdim * 10) - (cdim/3);
    float jump=(rdim*cdim)/rdim;
    sc_jump=jump*p_rem;
    gotoRowCol(r, (c+jump)-sc_jump);
    if(turn==1){
     cout << "@";
    }
    else
    {
        cout << "#";
      }
  }

void snakes_ladders(int& p)
{

    if (p == 16)
    {
        p = 6;
    }
    else if (p == 50)
    {
        p = 35;
    }
    else if (p == 67)
    {
        p = 33;
    }
    else if (p == 98)
    {
        p = 53;
    }
//lader
    else if (p == 11)
    {
        p = 34;
    }
    else if (p == 39)
    {
        p = 61;
    }
    else if (p == 69)
    {
        p = 84;
    }
    else if (p == 80)
    {
        p = 94;
    }
}

void erase_position(int rdim, int cdim,int p)
{
    float sc_jump;
    int p_rem=p%10;
    int r_check;
 if(p<=10)
  {
     r_check=10;
  }
   else if (p>10&&p<=20)
    {
        r_check=9;
    }
    else if (p>20&&p<=30)
    {
        r_check=8;
    }
    else if (p>30&&p<=40)
    {
        r_check=7;
    }
    else if (p>40&&p<=50)
    {
        r_check=6;
    }
    else if (p>50&&p<=60)
    {
        r_check=5;
    }
    else if (p>60&&p<=70)
    {
        r_check=4;
    }
    else if (p>70&&p<=80)
    {
        r_check=3;
    }
    else if (p>80&&p<=90)
    {
        r_check=2;
    }
    else if (p>90&&p<=100)
    {
        r_check=1;
    }
    if(p_rem==0)
    {
        p_rem=10;
    }
    int r = (rdim * r_check) - (rdim/3);
    int c = (cdim * 10) - (cdim/3);
    float jump=(rdim*cdim)/rdim;
    sc_jump=jump*p_rem;
    gotoRowCol(r, (c+jump)-sc_jump);
    cout<<" ";
  }

int change_turn(int turn)
{
    if (turn == 1)
    {
        turn = 2;
    }
    else
    {
        turn=1;
    }
    return turn;
}
void writer(int p1,int p2,int turn)
{
    ofstream writer("score.txt");
    writer<<p1<<" "<<p2<<" "<<turn;
}
void reader(int  & p1 ,int  & p2,int & turn)
{
    ifstream reader("score.txt");
    reader>>p1>>p2>>turn;
    gotoRowCol(5 , 120);
    cout<<"Player1:"<<p1<<" Player2:"<<p2<<" Turn:"<<turn;
}

void working (int&p1,int&pp1,int dice,int rdim,int cdim,int turn)
{
int temp=0,tem1=0;
                    gotoRowCol(43 , 135);
                    getch();
                    dice = Roll_Dice();
                    cout<<dice;
             if (dice == 6 && pp1 == 0 ) //for start
            {
                    pp1 = 1;
                    moving_player(rdim, cdim, pp1, turn);
                    gotoRowCol(43 , 135);
                    getch();
                    dice = Roll_Dice();
                    cout << dice;
                    if(dice==6)  //for 2nd 6
                    {
                        temp=dice;
                        gotoRowCol(43 , 135);
                        getch();
                        dice = Roll_Dice();
                        cout << dice;
                        if(dice==6)
                        {
                            temp=0;
                        }
                        else
                        {
                            erase_position(rdim, cdim, pp1);
                            temp=temp+dice;
                            p1=temp+pp1;
                            snakes_ladders(p1);
                            moving_player(rdim, cdim, p1, turn);
                            pp1=p1;
                            gotoRowCol(43 , 135);
                        }
                    }
                else
                 {
                 p1=pp1+dice;
                 erase_position(rdim, cdim, pp1);
                 snakes_ladders(p1);
                 moving_player(rdim, cdim, p1, turn);
                 pp1=p1;
                 gotoRowCol(43 , 135);
                }
            }
            else if (pp1!=0)
                {
                    if(dice==6)
                    {
                        tem1=dice;
                        gotoRowCol(43 , 135);
                        getch();
                        dice = Roll_Dice();
                        cout << dice;
                        if(dice==6)
                        {
                            tem1=tem1+dice;
                            gotoRowCol(43 , 135);
                            getch();
                            dice = Roll_Dice();
                            cout << dice;
                            if(dice==6)
                            {
                                tem1=0;
                            }
                            else
                            {
                               p1=tem1+dice+pp1;
                               snakes_ladders(p1);
                              if(p1<=100)
                              {
                               erase_position(rdim, cdim, pp1);
                               moving_player(rdim, cdim, p1, turn);
                               pp1=p1;
                               }
                             }
                        }
                        else
                        {
                            p1=tem1+pp1+dice;
                            snakes_ladders(p1);
                            if(p1<=100)
                              {
                               erase_position(rdim, cdim, pp1);
                               moving_player(rdim, cdim, p1, turn);
                               pp1=p1;
                              }
                        }
                    }
                    else
                    {
                        p1=pp1+dice;
                        snakes_ladders(p1);
                        if(p1<=100)
                        {
                        erase_position(rdim, cdim, pp1);
                        moving_player(rdim, cdim, p1, turn);
                        pp1=p1;
                        }
                    }
                 }
                }

int main()
{
    int rdim = 4, cdim =8;
    print_Board(rdim, cdim);
     int p1 , p2;    // score of players
    int pp1, pp2;  // positions of players
    int turn;// Current player's turn
    int dice;
    gotoRowCol(39, 130);
    cout << "Press any key to roll the dice!!!";
    gotoRowCol(40 , 130);
    cout << "Player 1: ";
    gotoRowCol(41 , 130);
    cout << "Player 2: ";
    gotoRowCol(43 , 130);
    cout << "Dice: ";
    char ask;
    gotoRowCol(2 , 120);
    cout<<"Press P to continue previous game else new: ";
    cin>>ask;
  if(ask=='P'||ask=='p')
    {
        reader(pp1 ,pp2, turn);
    }

  else
    {
     p1 = 0, p2 = 0;   // score of players
     pp1 = 0, pp2 = 0;  // positions of players
     turn = 1;
    }
while (pp1 < 100 && pp2 < 100)
    {
        if (turn == 1)
        {
            working(p1,pp1,dice,rdim,cdim,turn);
            gotoRowCol(40 , 139);
            cout<<pp1;
        }

  else if (turn == 2)
   {
      working(p2,pp2,dice,rdim,cdim,turn);
      gotoRowCol(41 , 139);
            cout<<pp2;
     }

        writer(pp1,pp2,turn);
       turn=change_turn(turn);
       gotoRowCol(44 , 130);
       cout<<"Turn:"<<turn;
    }

        gotoRowCol(45, 130);
     if (pp1 == 100)
        {
            cout << "Player 1 has won!";
        }
      else if (pp2 == 100)
        {
            cout << "Player 2 has won!";
        }
     return 0;
}
