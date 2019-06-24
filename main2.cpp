#include <iostream>
#include <deque>

using namespace std;


int main()
{
    deque<string> exspression;
    string allExspression;
    string inputOperation;
    string numberOperationString;
    int numberOperation;
    getline(cin, inputOperation);
    exspression.push_back(inputOperation);
    getline(cin, numberOperationString);
    numberOperation = stoi(numberOperationString);
    if(numberOperation == 0){
        cout << exspression[0] << endl;
        return 0;
    }else{
        char lastOperation = '*';
        for(int i(0); i < numberOperation; i++){
            getline(cin, inputOperation);
            if(lastOperation != '*' && lastOperation != '/'){
                if(inputOperation[0] == '*' || inputOperation[0] == '/'){
                    exspression.push_back(")");
                    exspression.push_front("(");
                }
            }
            lastOperation = inputOperation[0];
            exspression.push_back(" ");
            exspression.push_back(inputOperation);
        }
        for(const string& ex : exspression){
            cout << ex;
        }
        cout << endl;
    }
    return 0;

}
