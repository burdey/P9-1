//
// Created by Satori on 2022/10/23.
//

#include "PolishPrefix.h"

PolishPrefix::PolishPrefix() {
    prefix = "";

}

PolishPrefix::PolishPrefix(string Polish) {
    prefix = Polish;
}

int PolishPrefix::PrefixNotation() {
    stack<int> val;
    int valid = 1;
    int value = 0;
    int digit = 0;
    int notation = 0;
    for(int i = prefix.length()-1; i>=0 && valid == 1; i--) { //Read the entire list and calculate
        char array = prefix[i];
        if(isdigit(array)){ //Arrange the array
            digit++;
            if (digit != 1){
                value = value + (array - '0'); // Array-0 is to prevent the occurrence of 0 numbers from affecting the calculation
                val.pop();
            }
            else if (digit == 1){
                value = array - '0'; // as above
            }
            val.push(value);
        }
        else if(array == '+' && val.size() >=2){ //The following four include addition, subtraction, multiplication and division, and these if statements will undertake the next calculation work
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 + num2);
            digit = 0;
        }
        else if(array == '-' && val.size() >=2){ // as above
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 - num2);
            digit = 0;
        }
        else if(array == '*' && val.size() >=2){ //as above
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 * num2);
            digit = 0;
        }
        else if(array == '/' && val.size() >=2){ //as above
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 / num2);
            digit = 0;
        }

        //Improper use
        /*else if(val.size() >=2) {
            if (array == '+') {
                int num1 = val.top();
                val.pop();
                int num2 = val.top();
                val.pop();
                val.push(num1 + num2);
                digit = 0;
            }
            else if (array == '-') {
                int num1 = val.top();
                val.pop();
                int num2 = val.top();
                val.pop();
                val.push(num1 - num2);
                digit = 0;
            }
            else if (array == '*') {
                int num1 = val.top();
                val.pop();
                int num2 = val.top();
                val.pop();
                val.push(num1 * num2);
                digit = 0;
            }
            else if (array == '/') {
                int num1 = val.top();
                val.pop();
                int num2 = val.top();
                val.pop();
                val.push(num1 / num2);
                digit = 0;
            }
        }*/

        //If there are spaces in the array, digit is equal to 0, preventing it from being counted
        else if(array == ' '){
            digit = 0;
        }
        else{
            valid = 0;
        }
    }

    //ensure results
    if(valid == 1 && !val.empty()){
        notation = val.top();
        val.pop();
    }
    return notation;
}

void PolishPrefix::setPrefixNotation(string Polish) {
    prefix = Polish;
}

string PolishPrefix::PrintPrefix() {
    stack<int> val;
    int valid = 1;
    int value = 0;
    int digit = 0;
    string print = "";
    for(int i = prefix.length()-1; i>=0 && valid == 1; i--){ // Read the entire list and print
        char array = prefix[i];
        if(isdigit(array)){ // as above
            digit++;
            if (digit != 1){
                value = value + (array - '0'); //as above
                val.pop();
            }
            else if (digit == 1){
                value = array - '0'; // as above
            }
            val.push(value);
        }
        else if (array == '+'||array == '-'||array == '*'||array == '/'){
            if(val.size() >= 2 && print.length() == 0){ //Printing according to different input and calculation situations
                int num1 = val.top();
                val.pop();
                int num2 = val.top();
                val.pop();
                ostringstream rig;
                rig << print << "(" << num1 << " " << array << " " << num2 << ")";
                print = rig.str();
                digit = 0;
            }
            else if(val.size() >= 2 && print.length() > 0){ // as above
                int num3 = val.top();
                val.pop();
                ostringstream rig;
                rig << print << " " << array << " " << num3;
                print = rig.str();
                digit = 0;
            }
            else if(val.size() == 1 && print.length() > 0){ // as above
                int num4 = val.top();
                val.pop();
                ostringstream rig;
                rig << print << " " << array << " " << num4;
                print = rig.str();
                digit = 0;
            }
            else{
                valid = 0;
            }
        }
        else if(array == ' '){
            digit = 0;
        }
    }
    if(valid == 0 || val.size() > 0){ // If the formula cannot be established, give error
        print = "Error";
    }
    return print;
}

PolishPrefix::~PolishPrefix() {


}
