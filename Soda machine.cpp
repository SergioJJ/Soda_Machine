/*
Author: Sergio Jimenez
This is code modeling a soda machine that focuses on using OOP in creating the program for practice.

This machine will sell 8 kinds of sodas, each with a price and optional flavor addition. The machine will have a quantity of 
10 sodas per soda type, and 3 flavor additions available. If no sodas are left of a particular type, it will display
"Out of Stock" for that particular soda.
The price of the sodas will be in increments of $0.25, and the machine will take up to $5 bills. 


The machine will accept four types of input: Soda selection buttons, money, optional flavor addition, and a change button.
Soda selection will be done by typing an integer between 1 and 8, and return an error message if a number is inserted outside that range.

Money will accepted will be in the form of modular amounts, and will take the format $X to denote money.
Discrete amounts representing change and bills will be accepted such as $5.00 $1.00, and $0.25.
An error will display if the user attempts to use a number outside of this range, or not in a multiple of $0.25
Only single bills and quarters exist in this world.

If no credits exist, or not enough exists to purchase a given item
"pressing" a button will result in displaying the price, calories, and wether the drink has caffeine or not.
Only when enough money exists as a credit in the machine will it release a soda as a purchase.
If the change button is pressed by typing the word "change", it will return any credit still in the system and reset the wallet to $0.

Sodas:
#   Soda        Price   Calories    Caffiene
1   Coke        $1.00   300         Y
2   RC Cola     $1.25   300         Y
3   Sprite      $0.75   275         N
4   Dr. Pepper  $1.00   300         Y
5   Ramune      $2.25   70          N
6   Arizona Tea $0.75   150         Y
7   Iced Coffee $2.00   200         Y
8   Water       $0.50   0           N

Additions:
#   Flavor      Calories
1   Cherry      50
2   Wildberry   100
3   Lemon-Lime  20

Class Soda
price 
calories
caffiene

Class modified_Soda
price inherited from soda class
calories + calories from soda
caffiene inherited from soda class

*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const int number_of_items       = 8;  // number of items for sale
const int number_of_additives   = 4;  // number of possible additives


// these are the definitions of the soda parameters in order of name, price, calories and caffeine content
const string sodaOptions[number_of_items] = {"Coke"     ,"RC Cola"  ,"Sprite"   ,"Dr. Pepper"   ,"Ramune"   ,"Arizona Tea"  ,"Iced Coffee"  ,"Water"    };

const float sodaPrices[number_of_items]  = {1.00       ,1.25       ,0.75       ,1.00           ,2.25       ,0.75           ,2.00           ,0.50       };

const int   sodaCalories[number_of_items] = {300        ,300        ,275        ,300            ,70         ,150            ,200            ,0          };

const bool  sodaCaffeine[number_of_items] = {true       ,true       ,false      ,true           ,false      ,true           ,true           ,false      };

// these are the definitions of the additive options you can get with your soda
const string additiveOptions[number_of_additives]  = {"Cherry"  ,"Wildberry"    ,"Lemon-Lime"   ,"Vodka"    };

const int  additiveCalories[number_of_additives] =  {50       ,100            ,20             ,0          };


class Sale_item {
public:
    string  getName() {return name;}
    void    setName(string name) {this-> name = name;} // using this-> operator as we will create the class before we instantiate it
    float   getPrice() {return price;}
    void    setPrice(float price) {this-> price = price;}
    int     getCalories() {return calories;}
    void    setCalories(int calories) {this-> calories = calories;} 
private:

    string  name;
    float   price;
    int     calories;
};

class Soda: public Sale_item {
public:

    bool    getCaffeine() {return caffeine;}
    void    setCaffeine(bool caffeine) {this-> caffeine = caffeine;} 
    void    SetAll(string, float, int, bool);
    Soda(string, float, int, bool);
    ~Soda();
private:
    bool caffeine;
};

// function to print the physical machine the user "sees", including the current selection available
void printMachine () {
    cout << "\n\nWelcome to the Soda Machine & Mixer!\nMake a selection to see price and details, or insert money to purchase." << endl;
    cout << "---------------------------------------------------------------------\n";
    for (int i = 0; i < 4; i++) {
        cout << "| " << i + 1 << " - " << sodaOptions[i] << "  |";
    }
    cout << "\n---------------------------------------------------------------------" << endl;
    for (int i = 4; i < 8; i++) {
        cout << "| " << i + 1 << " - " << sodaOptions[i] << "  |";
    }
    cout << "\n---------------------------------------------------------------------";
}

// function to print the current credit balance in machine
void printCredit (float credit) {
    cout    << "\nCredit: $" << credit << "\nPlease insert $5, $1 bills or quarters ($0.25) one at a time." 
            << "\nOr enter a number selection to receive details: \n";
}



// function to determine if input is money, a selection, or invalid
int determineInput (string inputString) {
    char found = inputString.at(0);
    if (found == '$') {
        cout << "Credit added.\n";
        //cout    << found << endl;
        return 2;
    }
    else // need to detect if 
    {
        if (isdigit(inputString[0]) >= 1){
            cout << "Entered a selection.\n";
            return 1;
        }
        else
        {
            cout << "Did not enter any money, or made a proper selection. Try again:\n";
            return 0;
        }
    }
}

int main () {
    float credit = 0;
    int inputType;
    string inputString;
    
    while (true) {
        printMachine();
        printCredit(credit);
        cin >> inputString;
        cout << "You entered : " << inputString << "\n";
    
        inputType = determineInput(inputString);

        // if money is inserted, add to credit
        if (inputType == 2) {
            inputString.erase(0,1);
            credit = credit + stof(inputString);
        }
        // if a selection is made, determine if a purchase is made or display info instead
        else if (inputType == 1) {
            cout << "selection info goes here!!!!!" << endl;

        }


    }
    return 0;
}