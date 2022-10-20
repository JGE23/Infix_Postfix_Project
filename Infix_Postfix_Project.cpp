#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int precedence(char x) {    
    int op;
        if (x == '^')                      
        op = 1;
            else  if (x == '*' || x == '/')         
            op = 2;
                else  if (x == '+' || x == '-')    
                    op = 3;
    return op;
}

int main() {
    string getInfix;                                      
    cout << "Infix Expression: ";
    getline(cin, getInfix);                                 
    stack <char> opStack;                              
    stringstream showInfix;                                
    

    for (unsigned i = 0; i < getInfix.length(); i++) {        
        
        if (getInfix[i] == '+' || getInfix[i] == '-' || getInfix[i] == '*' || getInfix[i] == '/'  || getInfix[i] == '^'  ) {   
            
            while (!opStack.empty() &&  precedence(opStack.top()) <= precedence(getInfix[i])) {        
                showInfix << opStack.top(); 
                opStack.pop();                
            }
           opStack.push(getInfix[i]);       
        }

         else if (getInfix[i] == '(' ) {      
            opStack.push(getInfix[i]);       
          }

          else if (getInfix[i] == ')') {           
            while (opStack.top() != '(') {          
                showInfix << opStack.top();          
               opStack.pop();                       
            }
            opStack.pop(); 
          }
          else {
            showInfix << getInfix[i]; 
        }
    }
    
    while (!opStack.empty()) { 
        showInfix << opStack.top();     
        opStack.pop();                 
    }
    
    cout << "Postfix Expression: "<<""<<showInfix.str() << endl;  
    
    cin.ignore ( numeric_limits< streamsize >:: max(),'\n'); 
    return 0;
}
