#include<iostream>
using namespace std ;
int main()
{
    int num1,num2,result;
    char op,cont;
    
        cout << "Enter the first number:";
        cin >> num1;
        cout << "Enter the Second number:";
        cin >> num2;
        cout << "Choose an operation(+,-,*,/):";
        cin >> op;
do{
    switch (op)
    {
    case '+':
        cout << num1+num2;
        break;
    
    case '-':
        cout << num1-num2;
        break;
    
    case '*':
        cout << num1*num2;
        break;
    
    case '/':
    
        if(num2!=0)
            {
                cout << num1/num2 ;
            }
        else
            {
                cout << "Division by zero can not done !";
                return 1;
            }
        break;
     
    default:
        break; 
     }
    cout << "\n Want to continue ? Y/N ";
    cin >> cont;
    }while(cont=='Y');
    return 0;
}


