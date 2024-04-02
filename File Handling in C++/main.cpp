#include <iostream>
#include <fstream>
using namespace std;

void writer(int p1,int p2,int turn)
{
    ofstream writing("score.txt");
    writing<<p1<<" "<<p2<<" "<<turn;
    writing.close();
}
void reader(int  & p1 ,int  & p2,int & turn)
{
    ifstream reader("score.txt");
    reader>>p1>>p2>>turn;
    cout<<"Player1:"<<p1<<" Player2:"<<p2<<" Turn:"<<turn;
    reader.close();
}

int main()
{
    int p1=2,p2=5,turn=1;

      writer( p1, p2, turn);
      reader( p1 , p2, turn);

}
