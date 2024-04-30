#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cstdlib>
using namespace std;

void play(){
    ifstream file ("words.txt");
    string input, word;
    vector<string> words;
    bool found = false;
    int count = 1;
    int total = 1;

    if(file.fail()){
        cout << "Error!\n";
    }

    srand(time(0));
    while (file >> word){
        words.push_back(word);
        total++;
    }

    int randnum = rand() % total;

    word = words[randnum];

    file.close();

    while(count <= 10){
        cout << "Enter a word: ";
        cin >> input;

        while(input.length() != 5){
            cout << "\nEnter a 5-letter word: ";
            cin >> input;
        }

        for (char &c : input) {
            c = tolower(c);
        }

        if(input == word){
            cout << "\033[1;32m" << input << "\033[0m" << endl << endl;
            cout << "You win!\n\n";
            return;
        }
        else{
            for(int i = 0; i < word.length(); i++){
                if(input[i] == word[i]){
                    cout << "\033[1;32m" << input[i] << "\033[0m";
                }
                else if(input[i] != word[i]){
                    for(int j = 0; j < word.length(); j++){
                        if(input[i] == word[j]){
                            cout << "\033[1;33m" << input[i] << "\033[0m";
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        cout << "_";
                    } 
                    else{
                        found = false;
                    }
                } 
            }
        }
       
        cout << endl;
        cout << endl;
        count++;
    }

    cout << "Correct word: " << word << endl;
    cout << "You lost!\n\n";
}

int main(){
    system("cls");
    cout << "Guessing game.\nTry to guess the word in 10 tries.\nIf the letter is written in \033[1;32mgreen\033[0m, then it is in the right place.\nIf the letter is written in \033[1;33myellow\033[0m, then it is from the word, but not in the right place.\nIf no letter appears, then it is not from the word.\nGood luck!" << endl << endl;

    char ch = ' ';

    while(ch != 'e'){
        play();

        cout << "Press 'r' to play again or 'e' to exit: ";
        cin >> ch;
        cout << endl << endl;

        if(ch == 'r'){
            continue;
        }
        else{
            break;
        }
    }
    
    return 0;
}