#include<bits/stdc++.h>
using namespace std;

//Prime detection
bool isprime(int num){
  for(int i = 0; i < num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

//Passcode validation
bool valid(int pass){
  if(pass == int('p') + int('a') + int('s') + int('s') + int('w') + int('o') + int('r') + int('d')){
    return true;
  }
  return false;
}

//Main function
int main(){
  // int passcode;
  // cin >> passcode;
  // if(valid(passcode)){
  //   ;
  // }
  // else{
  //   return 0;
  // }
  char ans;
  cout << "Do you know the controls for the game?(Y/N)";
  cin >> ans;
  if(ans == 'Y'){
    ;
  }
  else{
    cout << "The controls are as follows: " << endl;
    cout << "Hit '/' to ask if the number is divisible by another number. Then add another number. Afterwards hit Enter to submit your guess." << "\n";
    cout << "Hit the '<' and '>' buttons and then input a number to make sure if the number is greater than or less than the number you inputted. Afterwards hit Enter to submit your guess." << "\n";
    cout << "Hit 'G' to guess, followed by the number you want to guess. Afterwards hit Enter to submit your guess." << "\n";
    cout << "Hit '^' to ask if the number is a perfect square. Afterwards hit Enter to submit your guess." << "\n";
    cout << "Hit 'P' to ask if the number is prime. Afterwards hit Enter to submit your guess." << "\n";
    cout << "Now you should understand the controls. Good luck! :P";
    cout << "There is a secret easter egg in the game. If you find it, you will be granted debug mode. Have fun!";
  }
    bool debug = false;
  while(1){

    //Make needed variables for program
    int n;
    cout << "What is the maximum size do you want the number to be?" << "\n";
    cin >> n;
    srand(time(0));
    int num = rand() % n;
    char gchar;
    int guess;
    int cnt = 1;
    int wrongcount = 0;

    while(1){
      cout << "What is your " << cnt;

      if(cnt == 1){
        cout << "st guess?" << "\n";
      }
      else if(cnt == 3){
        cout << "nd guess?" << "\n";
      }
      else{
        cout << "th guess?" << "\n";
      }
      cin >> gchar;

      //Checks if the player is asking if the number is divisible by the guess
      if(gchar == '/'){
        cin >> guess;
        if(num % guess == 0){
          cout << "Yes, the number is fully divisible by " << guess << "." << "\n";
        }
        else{
          cout << "No, the number is not fully divisible by " << guess << "." << "\n";
        }
      }

      //Is the number a prime number?
      else if(gchar == 'P'){
        if(isprime(num)){
          cout << "Yes, the number is a prime number." << "\n";
        }
        else{
          cout << "No, the number is not a prime number." << "\n";
        }
      }

      //Is the number a perfect square?
      else if(gchar == '^'){
        if(sqrt(num) == int(sqrt(num))){
          cout << "Yes, the number is a perfect square." << "\n";
        }
        else{
          cout << "No, the number is not a perfect square." << "\n";
        }
      }

      //Is the number less than the guess?
      else if(gchar == '<'){
        cin >> guess;
        if(num < guess){
          cout << "Yes, the number is less than " << guess << "." << "\n";
        }
        else{
          cout << "No, the number is not less than " << guess << "." << "\n";
        }
      }

      //Is the number greater than the guess?
      else if(gchar == '>'){
        cin >> guess;
        if(num > guess){
          cout << "Yes, the number is greater than " << guess << "." << "\n";
        }
        else{
          cout << "No, the number is not greater than " << guess << "." << "\n";
        }
      }

      //The player tries to guess the number
      else if(gchar == 'G'){
        cin >> guess;
        if(guess == num){
          cout << "Yes, you guessed the number!" << "\n";
          break;
        }
        else{
          cout << "No, you did not guess the number." << "\n";
          wrongcount++;
        }
      }

      else if(gchar == 'R'){
        if(debug){
          cout << "The number is " << num << "." << "\n";
        }
      }
      cnt++;
    }

    //Easter Egg
    if(cnt > 100){
      cout << "You found the easter egg! But be honest; Did you peek at the code? (Y/N)" << "\n";
      cin >> ans;
      cout << "Debug mode activated" << "\n";
      debug = true;
    }

    if(debug){
      cout << "Input 'S' to skip the game.";
      cin >> ans;
      if(ans == 'S'){
        ;
      }
      else{
        //Results
        cout << "Results:" << "\n";
        cout << "You had a total of " << wrongcount << " wrong guesses." << "\n";
        cout << "You took a total of " << cnt << " guesses." << "\n";

        //Does the player want to play a new game?
        cout << "New game? (input 'N' to play new game, input 'Q' to quit)" << "\n";
        char newgame;
        cin >> newgame;
        if(newgame == 'N'){
          cout << "\033[H\033[J";
          //Clears screen
        }
        else{
          break;
        }
      }
    }
    else{
      //Results
      cout << "Results:" << "\n";
      cout << "You had a total of " << wrongcount << " wrong guesses." << "\n";
      cout << "You took a total of " << cnt << " guesses." << "\n";

      //Does the player want to play a new game?
      cout << "New game? (input 'N' to play new game, input 'Q' to quit)" << "\n";
      char newgame;
      cin >> newgame;
      if(newgame == 'N'){
        cout << "\033[H\033[J";
        //Clears screen
      }
      else{
        break;
      }
    }
  }

  //End credits
  cout << "Made by the developers of 'Guess the number'." << "\n";
  cout << "Thank you for playing!" << "\n";
  return 0;
}
