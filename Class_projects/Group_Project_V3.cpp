#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int capacity = 4;
    const int firstClassCapacity = 2;
    const int economyCapacity = capacity - firstClassCapacity;

    string name[capacity];
    char sexes[capacity];
    bool seats[capacity] = {false};
    int age[capacity];
    string passports[capacity];
    int economyPassengers = 0, firstClassPassengers = 0;
    bool transferred = false;
    char choice = 0;

    cout << "Welcome to the airline reservation system!\n";

    for (int i = 0; i < capacity; i++) {
        bool foundSeats = false;

        if (!transferred) {
            cout << "\nWelcome!! \nPlease type \n1 for \"First Class\" and \n2 for \"Economy\" \nYour choice: ";
            cin >> choice;
        }

        while (true) {

            if (choice == '1' || transferred) {
                int seatIndex = 0;
                for (; seatIndex < firstClassCapacity; seatIndex++) {
                    if (!seats[seatIndex]) {
                        foundSeats = true;
                        seats[seatIndex] = true;
                        break;
                    }
                }

                if (foundSeats) {
                    cout << "Welcome aboard!\n";
                    cout << "Please input personal details\n";
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, name[i]);
                    cin.clear();

                    do {
                        cout << "Sexes (M/F): ";
                        cin >> sexes[firstClassPassengers];
                        sexes[firstClassPassengers] = toupper(sexes[firstClassPassengers]);
                        if (sexes[firstClassPassengers] != 'F' && sexes[firstClassPassengers] != 'M') {
                            cout << "Invalid Input! Please Enter 'M' for male or 'F' for female!\n";
                        }
                    } while (sexes[firstClassPassengers] != 'F' && sexes[firstClassPassengers] != 'M');

                    do{
                        cout << "Age: ";
                        cin >> age[firstClassPassengers];
                        if(age[firstClassPassengers]<0){
                            cout << "Age can't be Negetive!\n";
                        }
                    }while(age[firstClassPassengers]<0);

                    bool uniquePassport;
                    do {
                        uniquePassport = true;
                        cout << "Passport Number (3 digits): ";
                        cin >> passports[firstClassPassengers];

                        for (int k = 0; k < capacity; ++k) {
                            if (k == firstClassPassengers) continue;
                            if (passports[firstClassPassengers] == passports[k]) {
                                cout << "Passport number must be unique. Please enter a different one.\n";
                                uniquePassport = false;
                                break;
                            }
                            for(char p : passports[firstClassPassengers]){
                                if(isalpha(p)){
                                    cout << "Passport number can't contain letters!";
                                }
                            }
                        }
                    } while (cin.fail() || passports[firstClassPassengers].length() != 3 || !uniquePassport);

                    cout << "\nBoarding Pass\n";
                    cout << "Seat: " << seatIndex + 1 << " (First Class)\n";

                    firstClassPassengers++;

                    break;
                } else {
                    char choose;
                    cout << "Sorry!! All First class seats have been occupied!\n";
                    cout << "Would you like to be transfered to \"Economy\"?\n";
                    cout << "Please input Y - for Yes or N - for No\n";

                    while (true) { // to check choice
                        cout << "Enter your choice: ";
                        cin >> choose;
                        choose = toupper(choose);

                        if (choose == 'Y') {
                            cout << "You are being transferred to Economy.\n";
                            transferred = true;
                            break;
                        } else if (choose == 'N') {
                            cout << "Next flight leaves in 3 Hours\n";
                            i--;
                            break;
                        } else {
                            cout << "Invalid Input!\n";
                        }
                    }

                    if (!transferred) {
                        break;
                    }
                }
            }

            if (choice == '2' || transferred) {
                int seatIndex = 0;
                for (; seatIndex < economyCapacity; seatIndex++) {
                    if (!seats[seatIndex + firstClassCapacity]) {
                        foundSeats = true;
                        seats[seatIndex + firstClassCapacity] = true;
                        break;
                    }
                }

                if (foundSeats) {
                    int economyIndex = firstClassCapacity + economyPassengers;
                    cout << "Welcome aboard!\n";
                    cout << "Please input personal details\n";
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, name[i]);
                    cin.clear();

                    while (true) {
                        char s;
                        cout << "Sexes (M/F): ";
                        cin >> s;
                        s = toupper(s);
                        if (s == 'F' || s == 'M') {
                            sexes[economyIndex] = s;
                            break;
                        } else {
                            cout << "Invalid Input! Please Enter 'M' for male or 'F' for female!\n";
                        }
                    }

                    do{
                        cout << "Age: ";
                        cin >> age[economyIndex];
                        if(age[economyIndex]<0){
                            cout << "Age can't be Negetive!\n";
                        }
                    }while(age[economyIndex]<0);
                    

                    bool uniquePassport;
                    do {
                        uniquePassport = true;
                        cout << "Passport Number (3 digits): ";
                        cin >> passports[economyIndex];

                        for (int k = 0; k < capacity; ++k) {
                            if (k == economyIndex) continue;
                            if (passports[economyIndex] == passports[k]) {
                                cout << "Passport number must be unique. Please enter a different one.\n";
                                uniquePassport = false;
                                break;
                            }
                            for(char p : passports[economyIndex]){
                                if(isalpha(p)){
                                    cout << "Passport number can't contain letters!";
                                }
                            }
                        }
                        
                    } while (cin.fail() || passports[economyIndex].length() != 3 || !uniquePassport);
                    
                    cout << "\nBoarding Pass\n";
                    cout << "Seat: " << seatIndex + economyCapacity + 1 << " (Economy)\n";

                    economyPassengers++;
                    break;
                } else {
                    char choose;
                    cout << "Sorry!! All economy seats have been occupied!\n";
                    cout << "Would you like to be transfered to \"First class\"?\n";
                    cout << "Please input y - for Yes or n - for No\n";

                    while (true) { 
                        cout << "Enter your choice: ";
                        cin >> choose;
                        choose = toupper(choose);
                        if (choose == 'Y') {
                            cout << "You are being transferred to First class.\n";
                            transferred = true;
                            break;
                        } else if (choose == 'N') {
                            cout << "Next flight leaves in 3 Hours\n";
                            i--;
                            break;
                        } else {
                            cout << "Invalid Input!\n";
                        }
                    }
                }
            } else {
                cout << "Please Input only 1 or 2!\n";
                i--;
                break;
            }
        }

        transferred = false;
    }

    return 0;
}
