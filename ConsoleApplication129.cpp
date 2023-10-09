#include <iostream>

#include<cmath>
#include<cstdlib>
using namespace std;
enum Entypeoflevel { Easy = 1,mod=2,hard=3,mix=4 };
enum Entypeofop{Add=1 , Sub = 2, Mul = 3, Div = 4, Mix = 5 };
int Readrandnum(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}
Entypeofop Readop(int from, int to)
{
    int randnum = rand() % (to - from + 1) + from;
    return (Entypeofop)randnum;
}
short ReadhowanyQustion()
{
    short num;
    cout << "How many Qustion ?";
    cin >> num;
    return num;
}
Entypeoflevel Readtypoflevel()
{
    int c;
    cout << "Enter Level qustion [1]Easy   [2]Mod  [3]Hard  [4]Mix ?";
    cin >> c;
    return (Entypeoflevel)c;
}
Entypeofop Readtypofop()
{
    int c;
    cout << "Enter Type of opration [1]Add   [2]Sub  [3]Mul  [4]Div [5]Mix ?";
    cin >> c;
    return (Entypeofop)c;
}
float Cheklevel( Entypeoflevel &Type)
{
    float num;
    if (Type == Entypeoflevel::Easy)
    {
        num = Readrandnum(1, 10);
        return num;
    }
    else if ((Type == Entypeoflevel::mod))
    {
        num = Readrandnum(10, 20);
        return num;
    }
    else if ((Type== Entypeoflevel::hard))
    {
        num = Readrandnum(50, 200);
        return num;
    }
    else 
        num = Readrandnum(1, 200);
    return num;
}
string Chekop(Entypeofop type2)
{
    if (type2 == Entypeofop::Add)
    {
        return "+";
    }
    else if ((type2 == Entypeofop::Sub))
    {
        return "-";
    }
    else if ((type2 == Entypeofop::Mul))
    {
        return "*";
    }
    else if (type2 == Entypeofop::Div) {
        return "/";
    }
    else
    {
        type2 = Readop(1,4);
        if (type2 == 1)
        {
            return"+";
        }
        else if (type2 == 2)
        {
            return "-";
        }
        else if (type2 == 3) {
            return "*";
        }
        else
            return "/";
    }
}
float rghitansar(float num2,float num3 ,string i)
{
    if (i =="+")
    {
        return( num2 + num3);
    }
    else if (i == "-")
    {
      return  ( num2 - num3);
    }
    else  if (i == "*")
    {
        return (num2 * num3);
    }
    else 
    {
        return   (num2 /num3);
    }
}
void checkanswer(float answr, float rightanswer,int &won,int &fail)
{
    if (answr == rightanswer)
    {
        won=won+1;
        cout << "The right Answer :)" << endl;
        cout << "---------------------\n" << endl;
        system("color 2f");
    }
    else {
        fail=fail+1;
        cout << "the wrong Answer :( " << endl;
        cout << "---------------------\n" << endl;
        system("color 4f");
    }
}
void endGaame()
{
    cout << "------------------------------------------------" << endl;
        cout << "With best wishes for success and excellence:)"<<endl;
        cout << "------------------------------------------------" << endl;
}
void PrintReslute(int won, int fail)
{
    if (won>= fail)
    {
        cout  << "----------------------------------"<<endl;
        cout << "Resulte Quze you are pass :)"<<endl;
        cout  << "---------------------------------- "<<endl;
    }
    else {

        cout << "----------------------------------" << endl;
        cout << "Resulte Quze you are fail :(" << endl;
        cout << "---------------------------------- " << endl;
    }
}
void RoundGame()
{

    short num; Entypeoflevel type; Entypeofop type2;
    float num1; int counterwon = 0; int counterfail = 0;
    float num2;  int counter = 1;
    num = ReadhowanyQustion();
    type = Readtypoflevel();
    type2 = Readtypofop();
    for (int i = 0; i < num; i++)
    {
        string op = Chekop(type2);
        cout << "Qustion[" << i + 1 << "/" << num << "]\n"<<endl;
        num1 = Cheklevel(type);
        num2 = Cheklevel(type);
        float answer;
        cout << num1 << endl;
        cout << "   " << op<<endl;
        cout << num2 << endl;
        cout << "-----------------------------"<<endl;
        cin >> answer;
        float rightanswer = rghitansar(num1, num2, op);
        cout << "\n" << "The Right Answer is : " << rightanswer << endl;
        checkanswer(rightanswer, answer,counterwon,counterfail);
    }
    PrintReslute(counterwon, counterfail);
    cout << "Num of qustion is :" << num << endl;
    cout << "Num of Right Answer is : " << counterwon<<endl;
    cout << "Num of  wrong Answer is : " << counterfail<<endl;
}
string DOwantplay()
{
    string i;
    cout << "Do you want play agin Y/N "<<endl;
    cin >> i;
    return i;
}
void RestGame()
{
    system("cls");
    system("color 0f");
}
void StartGame()
{
    string i;
    do {
        RestGame();
        RoundGame();
        endGaame();
        i = DOwantplay();

    } while (i == "Y" || i == "y");
}
int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}
