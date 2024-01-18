#include <iostream>
using namespace std;

int main(){
    string name[100]; 
    char sex[100], seats[100];
    int age[100], passportNumber[100];

    for(int i=0; i<100; i++){ // filling seats with spaces so we can use it to check if seat is empty
        seats[i] = ' ';
    }
    int choise = 0, economyPassengers = 0, firstClassPassengers = 0;
    bool foundSeats = false;
    for(int i=0; i<100; i++){
        cout << "Please type \n1 for \"First Class\" and \n2 for \"Economy\" \nYour choise: ";
        cin >> choise;
        if(choise == 1){ // first class
            int j=0;
            for(; j<30; j++){ // check if there is an empty seat
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
                cout << "Passport Number: ";
                cin >> passportNumber[i];
                
            }
            else{ // empty seats not avialable in first class
                char choose;
                cout << "Sorry!! All First class seats has been occupied!\n";
                cout << "Would you like to shift to \"Economy\"?\n";
                cout << "Please input y - for Yes or n - for No\n";
                while (true){ // to check choise
                    cout << "Enter your choise: ";
                    cin >> choose;
                    choose = toupper(choose);
                    if(choose == 'Y'){
                        cout << "You are being transfered to First class.\n"; // i havn't found an simpler way to transfer the user to economy
						// code
                        break;
                    }
                    else if(choose == 'N'){ // chose NO
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
        else if(choise == 2){
            int j=0;
            for(; j<70; j++){
                if (seats[j+30] == ' '){
                    foundSeats=true;
                    seats[j] = 'o';
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
                    int num, flag=0;
                    cout << "Passport Number(3 digits): "; // 3 digits is an example
                    cin >> num;
                    if(num>99 && num<1000){
                        for(int i=0; i<70;i++){ // checking if the passport is a unique
                            if(num == passportNumber[i+30]){
                                cout << "Your passport number is not unique please input again\n";
                                flag = true;
                                break;
                            }
                        }
                        if (!flag){
                            break;
                        }
                        
                    }
                }
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
						//code
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

    return 0;
}
