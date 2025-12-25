#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

//Function to print the current status of the man using the number of attempts as the parameter
void person(int step){
    switch(step){
        case 0:
               cout << "-------" 
            << endl << "|     " 
            << endl << "|" 
            << endl << "|" 
            << endl << "|" 
                     << "____" << endl;
            break;
        case 1:
               cout << "-------" 
            << endl << "|     O" 
            << endl << "|" 
            << endl << "|" 
            << endl << "|" 
                     << "____" << endl;
            break;
        case 2:
               cout << "-------" 
            << endl << "|     O" 
            << endl << "|     |" 
            << endl << "|" 
            << endl << "|" 
                     << "____" << endl;
            break;
        case 3:
               cout << "-------" 
            << endl << "|     O" 
            << endl << "|     |" 
            << endl << "|    /" 
            << endl << "|" 
                     << "____" << endl;
            break;
        case 4:
               cout << "-------" 
            << endl << "|     O" 
            << endl << "|     |" 
            << endl << "|    / \\"
            << endl << "|" 
                     << "____" << endl; 
            break;
        case 5:
               cout << "-------" 
            << endl << "|     O" 
            << endl << "|    /|" 
            << endl << "|    / \\"
            << endl << "|" 
                     << "____" << endl; 
            break;        
        case 6:
               cout << "-------" 
            << endl << "|     O" 
            << endl << "|    /|\\" 
            << endl << "|    / \\"
            << endl << "|" 
                     << "____" << endl;  
            break;
    }
}

int main(){

    cout << "***** Welcome to Hangman *****" << endl << endl;

    //Possible words that can be picked at random
    string word_list[30] = {"grassland", "seatbelt", "motorway", "apartment", "speedbump",  
                            "backpack", "rainstorm", "sunflower", "notebook", "playground",  
                            "fireplace", "skyscraper", "blueprint", "earthquake", "honeycomb",  
                            "landscape", "breakfast", "wristwatch", "nightfall", "crosswalk",  
                            "moonlight", "campfire", "snowstorm", "paperclip", "woodpecker",  
                            "steamboat", "shoelace", "railroad", "treadmill", "snowflake"};


    //Generating the random word
    srand(time(0));
    int random_word = rand() % 30;
    string word = word_list[random_word];

    //Defining an array with dashed elements -> # elements = length of word
    string dashed[word.length()];
    
    //Initializing the dashed list
    for(int i = 0; i < word.length(); i++){
        dashed[i] = "_";
    }

    //Initializing a variable for # attempts and the win status
    int attempts = 0;
    int win_check = false;

    //Code to print the dashed list
    for(int i = 0; i < word.length(); i++){
        cout << dashed[i] << " ";
    }
    cout << endl << endl;

    //For loop  run program until user attepmts are exhausted
    while (attempts < 8){
        //Asking for user input
        cout << endl;
        char guess;
        cout << "Enter Guess: ";
        cin >> guess;

        //Variable to check if there is a matching letter in the word
        int status;

        //For loop to check if the guess letter is found in the word
        for(int i = 0; i < word.length(); i++){
            if (word[i] == guess){
                dashed[i] = guess;
                status = true;
            }
            else if (word[i] != guess && status != true){
                status = false;
            }
        }

        //Increasing or completing game if no match was found
        if(status == false){
            attempts ++;
            person(attempts);
            if (attempts == 6){
                cout << endl << "You Lost! :(" << endl << "The word was: " << word;
                break;
            }
            for(int i = 0; i < word.length(); i++){
                cout << dashed[i] << " ";
            }
            cout << endl << endl;
        }

        //If a match was found -> printing the modified dashed list
        else if(status == true){
            person(attempts);
            int count = 0;
            for(int i = 0; i < word.length(); i++){
                cout << dashed[i] << " ";
                if (dashed[i] != "_"){
                    count ++;
                }
            }
            cout << endl << endl;

            //Condition to check for a win
            if (count == word.length()){
                cout << "You Win! :)";
                break;
            }
            status = false;
        }

    }
    return 0;
}