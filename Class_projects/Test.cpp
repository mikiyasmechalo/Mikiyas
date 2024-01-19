#include <iostream>
using namespace std;

int main(){
    string name[4];
    char sex[4], seats[4];
    int age[4];
    string passportNumber[4];
    bool transfered = false;

    for(int i=0; i<4; i++){
        seats[i] = ' ';
    }
    int choise = 0, economyPassengers = 0, firstClassPassengers = 0;
    for(int i=0; i<4; i++){
        bool foundSeats = false;
        if (!transfered) {
            cout << "Please type \n1 for \"First Class\" and \n2 for \"Economy\" \nYour choise: ";
            cin >> choise;
        }
        while(true){
        
            if(choise == 1 || transfered){
                int j=0;
                for(; j<2; j++){
                    if (seats[j] == ' '){
                        foundSeats=true;
                        seats[j] = 'o';
                        break;
                    }
                }
                // if (!foundSeats && transfered) {  // not possible since if all seats are full then i = 99
                //     cout << "The plane is out of seats";
                // }
                
                if (foundSeats){
                    cout << "Welcome abroad!\n";
                    cout << "You have been assigned First class seat number " << j+1 << '\n';
                    cout << "Please input personal details\n";
                    // cout << "Name: ";
                    // cin.ignore();
                    // getline(cin, name[i]);
                    // cin.clear();
                    // cout << "Sex (M/F): ";
                    // cin >> sex[i];
                    // sex[i] = toupper(sex[i]);
                    // cout << "Age: ";
                    // cin >> age[i];
                    while (true){
                        string pnum;
                        bool flag=0;
                        cout << "Passport Number(3 digits): "; //check if unique?
                        cin >> pnum;
                        // if(num>99 && num<1000){ // not a good way since numbers like 092 exist / no need for this /
                            for(int i=0; i<2;i++){
                                if(pnum == passportNumber[i+2]){
                                    cout << "Your passport number is not unique please input again\n";
                                    flag = true;
                                    break;
                                }
                            }
                            if (!flag){
                                passportNumber[i+3] = pnum;
                                break;
                            }
                            
                        // }
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
                            // i--; // necessary? Nop
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
                for(; j<2; j++){
                    if (seats[j+2] == ' '){
                        foundSeats=true;
                        seats[j+2] = 'o';
                        break;
                    }
                }
                if (foundSeats){

                    cout << "Welcome abroad!\n";
                    cout << "You have been assigned economy class seat number " << j+3 << '\n';
                    cout << "Please input personal details\n";
                    // cout << "Name: ";
                    // cin.ignore();
                    // getline(cin, name[i]);
                    // cin.clear();
                    // cout << "Age: ";
                    // cin >> age[i];
                    while (true){
                        string pnum;
                        bool flag=0;
                        cout << "Passport Number(3 digits): "; 
                        cin >> pnum;
                        // if(num>99 && num<1000){
                            for(int i=0; i<4;i++){
                                if(pnum == passportNumber[i]){ // edit?
                                    cout << "Your passport number is not unique please input again!\n";
                                    flag = true;
                                    break;
                                }
                            }
                            if (!flag){
                                passportNumber[i+2] = pnum;
                                break;
                            }
                            
                        // }
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
                            // i--;
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
