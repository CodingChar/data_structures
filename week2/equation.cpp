#include <iostream>
#include <cmath>

using namespace std;

// global variables;

// Made for Equations of Second Degree
void getEquation(float a, float b, float c)
{

    double x1, x2;        // x1 , x2
    double nm, dm, dis;   // Numerator, Denominator, Discrminant
    int solutionType = 0; // Solution Type (Unique: 0,Real: 1, Complex: 2)

    dm = 2 * a;
    dis = pow(b, 2) - 4 * a * c;


    //Evaluates the discrminant 
    if (dis == 0)
    {
        //Real Unique 
        solutionType = 0;
    }
    else if (dis > 0)
    {
        //Real Solution
        solutionType = 1;
        dis = sqrt(dis);
    }
    else if (dis < 0)
    {
        //Complex Solution
        solutionType = 2;
    }

    //How the solution is displayed  depending of the type
    switch (solutionType)
    {
    case 0:

        double uniqueResult;
        nm = -1 * b;

        uniqueResult = nm/dm;
        cout << endl
             << "Unique Solution, x=:" << uniqueResult << endl;

    case 1:
        nm = -1 * b + dis;
        x1 = nm / dm;
        nm = -1 * b - dis;
        x2 = nm / dm;
        cout << endl
             << "x1:" << x1 << endl;
        cout << endl
             << "x2:" << x2 << endl;
        break;
    case 2:
        dis = sqrt(abs(dis));
        cout << endl
             << "x1: " << -b / (2 * a) << "+" << dis / (2 * a) << "i" << endl;
        cout << endl
             << "x2: " << -b / (2 * a) << "-" << dis / (2 * a) << "i" << endl;
        break;
    default:
        cout<<endl<<"Unexpected Error, Try again";
        break;
    }
}

int main()
{

    float a, b, c;
    bool running = true;

    cout << "\t\t\n Welcome to the Equation Solver \t\t\n";
    char opc;
    while (running)
    {

        cout <<endl<< "define a(float):";
        cin >> a;
        if (a == 0)
        {
            cout << "\n a(A) should'nt be equal to 0(zero)\n";
            a = 0, b = 0, c = 0; // Resseting Input
            continue;
        }
        cout << "\n";

        cout << "define b(float):";
        cin >> b;

        cout << "\n";

        cout << "define c(float):";
        cin >> c;

        cout << "\n";

        getEquation(a, b, c);

        cout<<endl<<"Would you like to try again?(y/n)"<<endl;
        cin>>opc;

        if(opc == 'y'){
            running=true;
        }else if(opc=='n'){
            running=false;
        }else{
            cout<<endl<<"Unknow Option"<<endl;
            running=true;
        }

    }

    return 0;
}