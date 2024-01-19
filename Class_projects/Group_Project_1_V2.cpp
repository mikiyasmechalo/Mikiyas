#include <iostream>
using namespace std;

int main(){
    string name[100];
    char sex[100], seats[100];
    int age[100];
    string passportNumber[100];
    bool transfered = false;

    for(int i=0; i<100; i++){
        seats[i] = ' ';
    }
    int choise = 0, economyPassengers = 0, firstClassPassengers = 0;
    for(int i=0; i<3; i++){
        bool foundSeats = false;
        if (!transfered) {
            cout << "Please type \n1 for \"First Class\" and \n2 for \"Economy\" \nYour choise: ";
            cin >> choise;
        }
        while(true){
        
            if(choise == 1 || transfered){
                int j=0;
                for(; j<30; j++){
                    if (seats[j] == ' '){
                        foundSeats=true;
                        seats[j] = 'o';
                        break;
                    }
                }
                if (foundSeats){
                    cout << "Welcome abroad!\n";
                    cout << "You have been assigned First class seat number " << j+1 << '\n';
                    cout << "Please input personal details\n";
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, name[i]);
                    cin.clear();
                    cout << "Sex (M/F): ";
                    cin >> sex[i];
                    sex[i] = toupper(sex[i]);
                    cout << "Age: ";
                    cin >> age[i];
                    while (true){
                        string pnum;
                        bool flag=0;
                        cout << "Passport Number(3 digits): "; //check if unique?
                        cin >> pnum;
                        for(int i=0; i<100;i++){
                            if(pnum == passportNumber[i]){
                                cout << "Your passport number is not unique please input again\n";
                                flag = true;
                                break;
                            }
                        }
                        if (!flag){
                            passportNumber[i+30] = pnum;
                            break;
                        }
                    }
                    break;
                }
                else{
                    char choose;
                    cout << "Sorry!! All First class seats has been occupied!\n";
                    cout << "Would you like to shift to \"Economy\"?\n";
                    cout << "Please input y - for Yes or n - for No\n";
                    while (true){ // to check choise
                        cout << "Enter your choise: ";
                        cin >> choose; // could add intiger checker
                        choose = toupper(choose);
                        if(choose == 'Y'){
                            cout << "You are being transfered to First class.\n";
                            transfered = true;
                            break;
                        }
                        else if(choose == 'N'){
                            cout << "Next flight leaves in 3 Hours\n";
                            i--;
                            break;
                        }
                        else{
                            cout << "Invalid Input!\n";
                        }
                    }
                    if (!transfered){
                        break;
                    }

                }
            }
            if(choise == 2 || transfered){

                int j=0;
                for(; j<70; j++){
                    if (seats[j+30] == ' '){
                        foundSeats=true;
                        seats[j+30] = 'o';
                        break;
                    }
                }
                if (foundSeats){

                    cout << "Welcome abroad!\n";
                    cout << "You have been assigned economy class seat number " << j+31 << '\n';
                    cout << "Please input personal details\n";
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, name[i]);
                    cin.clear();
                    cout << "Age: ";
                    cin >> age[i];
                    while (true){
                        string pnum;
                        bool flag=0;
                        cout << "Passport Number(3 digits): "; 
                        cin >> pnum;
                        for(int i=0; i<100;i++){
                            if(pnum == passportNumber[i]){
                                cout << "Your passport number is not unique please input again!\n";
                                flag = true;
                                break;
                            }
                        }
                        if (!flag){
                            passportNumber[i+30] = pnum;
                            break;
                        }
                    }
                    break;
                }
                else{
                    char choose;
                    cout << "Sorry!! All economy seats has been occupied!\n";
                    cout << "Would you like to shift to \"First class\"?\n";
                    cout << "Please input y - for Yes or n - for No\n";
                    while (true){ // to check choise
                        cout << "Enter your choise: ";
                        cin >> choose;
                        choose = toupper(choose);
                        if(choose == 'Y'){
                            cout << "You are being transfered to First class.\n";
                            transfered = true;
                            break;
                        }
                        else if(choose == 'N'){
                            cout << "Next flight leaves in 3 Hours\n";
                            i--;
                            break;
                        }
                        else{
                            cout << "Invalid Input!\n";
                        }
                    }
                    
                }
            }
        }
        transfered = false;
    }

    return 0;
}
