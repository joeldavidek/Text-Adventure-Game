
/*******
This program is a text based game. The objective of the game is to travel the required amount
of miles without dying from lack of HP, Stamina, or hunger. Follow the prompts and the game
will explain how to play.
********/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream> // alllows to read and write to txt files.
#include <iomanip> // Manipulator functions- such as setw(), setprecision(), etc.
#include <cstdlib> // c standard library. Allows random.
#include <ctime>   // Allows time.

using namespace std;

int main()
{
    /******************************   #4   Variables   ******************************/
    int health;
    int stamina;
    int hunger;
    bool done;
    int miles;
    int traveled;
    int miles_traveled;
    string user_input;
    int hit_atk;
    int kick_atk;
    int sleep_hours;
    string holding;
    string player;

    cout << endl;
    cout << "Welcome!" << endl;
    cout << endl;
    cout << "Enter player name:  ";
    getline(cin, player);
    cout << endl;
    cout << "Hello " << player << ". Lets get started." << endl;
    cout << endl;

    cout << "Press enter to continue.";
    cout << endl;
    cin.get();
    cout << "You were on your way home from a beautiful vacation when the plane you were on crash landed in the middle of the mountains. " << endl;
    cout << "You must trek through the mountains to reach the nearest civilation 50 miles away and get help. There is luggage scattered  " << endl;
    cout << "through out the path containing vital supplies you will need to survive and protect yourself. Good luck on your journey. " << endl;
    cout << endl;

    srand(time(NULL)); // This is required to have a random number without a pattern

    /****************** Main game stats************************/
    health = 100;                             // HP the user starts out with.
    stamina = 100;                            // Amount of stamina points user starts with.
    hunger = 100;                             // Amouint of hunger points user starts out with.
    miles = 50;                               // amount of  miles to travel.
    traveled = 0;                             // amount of miles traveled per turn.
    miles_traveled = 0;                       // running total of miles traveled.
    hit_atk = 15;                             // Default attack power from user.
    kick_atk = 20;                            // Kick power from user.
    done = false;                             // Boolean set to false.
    sleep_hours = (rand() % (6 - 4 + 1)) + 4; // Formula for generating a number between 4 and 6. Random hours player slept.
    holding = "None";                         // Tells user what weapon they are holding.

    /************************  #7   LOOP ITERATION    ***********************/
    /************************  #8     INTERACTION     *************************/
    /************************  #9      CONTROL      *****************************/
    while (done == false)
    {
        cout << endl;
        cout << endl;
        cout << setw(0) << "HP: " << health << setw(15) << "Stamina: " << stamina << setw(15) << "Hunger: " << hunger; // This is where point are displayed.
        cout << setw(25) << "Miles traveled: " << miles_traveled << setw(15) << "Weapon: " << holding << endl;
        cout << endl;
        cout << endl;
        cout << "W. Walk" << endl;
        cout << "R. Run" << endl;
        cout << "S. Sleep" << endl;
        cout << "Q. Quit Game" << endl;
        cout << endl;
        cout << "Your choice?: ";
        cin >> user_input; // <-------------------------------  #3     INPUT
        cout << endl;

        if (user_input == "Q" or user_input == "q") // If user selects Q, then program will exit while loop. Game ends.
        {
            done = true;
            cout << "You quit the game. Game Over.";
            break;
        }

        if (user_input == "W" or user_input == "w") // If user selects W the amount of miles will ascend by a random amount between 1 and 3.
        {
            traveled = (rand() % (3 - 1 + 1)) + 3; // This is the formula  to have a random number between 1 and 3. Travels between 1 and 3 miles.
            cout << "You walked " << traveled << " miles.";
            miles_traveled = miles_traveled + traveled;

            stamina = (stamina - 10);
            hunger = (hunger - 8);
        }

        if (user_input == "R" or user_input == "r") // If user selects R the amount of miles will ascend by a random amount between 4 and 8.
        {
            traveled = (rand() % (8 - 4 + 1)) + 4; // This is the formula to have a random number between 4 and 8
            cout << "You ran " << traveled << " miles.";
            miles_traveled = miles_traveled + traveled;
            stamina = (stamina - 15);
            hunger = (hunger - 12);
        }

        if (user_input == "S" or user_input == "s") // If user selects S, stamina will reset to 100 and health will increase by 20 points.
        {
            cout << "You slept " << sleep_hours << " hours." << endl;
            cout << "You feel much better now. Stamina was restored to 100 and health increased by 20." << endl;
            stamina = 100;
            health = health + 20;

            if (health >= 100) // This is so that health doesnt display a number over 100. 100 is the max amount.
            {
                health = 100;
            }

            cin.ignore();
            cout << endl;
            cout << "Enter to continue...";
            cout << endl;
            cin.get(); // user has to press enter on keyboard to move on.
        }

        if (miles_traveled >= 50) // If miles traveled is greater than or equal to 50, the game will end.
        {
            cout << endl;
            cout << "You made it to civilization!!" << endl;
            cout << "YOU WIN!!" << endl;
            cout << "Be sure to check file called  'endingstats.txt' to see your ending stats!" << endl;
            cout << endl;
            cout << "Press Enter to End Game." << endl;
            cin.ignore();
            cin.get();   // user has to press enter to move on.
            done = true; // done is no longer false.
            break;       // breaks out of the while loop.
        }
        /***************************  #5   Array     ***************************/

        const string items[6] = {"sword", "wand", "bow and arrow", "mri", "fruit", "magic bean"};
        int sword = 25, wand = 45, arrow = 20, mri = 50, fruit = 30, bean = 100;
        string found;
        int suitcase;
        suitcase = (rand() % (100 - 1 + 1)) + 1;

        if (suitcase <= 25)
        {
            cout << endl;
            cout << endl;
            cout << "You found a suitcase! ";
            int random_item = rand() % 6;
            found = items[random_item];
            cout << "It cantains a " << found << endl;
            cout << endl;
            cout << endl;
            cout << "Would you like to use the " << found << "?\n";
            cout << "Y or N\n";
            cout << endl;
            cin >> user_input;
            cout << endl;

            if (user_input == "Y" or user_input == "y")
            {
                if (found == "sword")
                {
                    hit_atk = sword;
                    holding = "Sword";
                }

                if (found == "wand")
                {
                    hit_atk = wand;
                    holding = "Wand";
                }

                if (found == "bow and arrow")
                {
                    hit_atk = arrow;
                    holding = "Bow and Arrow";
                }

                if (found == "mri")
                {
                    health = health + mri;
                    if (health > 100)
                    {
                        health = 100;
                    }

                    hunger = hunger + mri;
                    if (hunger > 100)
                    {
                        hunger = 100;
                    }
                }

                if (found == "fruit")
                {
                    health = health + fruit;
                    if (health > 100)
                    {
                        health = 100;
                    }

                    hunger = hunger + fruit;
                    if (hunger > 100)
                    {
                        hunger = 100;
                    }
                }

                if (found == "magic bean")
                {
                    health = 100;
                    hunger = 100;
                    stamina = 100;
                }
            }

            if (user_input == "N" or user_input == "n")
            {
                health = health;
                hit_atk = hit_atk;
            }
        }

        if (stamina <= 0)
        {
            cout << endl;
            cout << endl;
            cout << "You collapsed from exhaution and can no longer continue." << endl;
            cout << "Game Over." << endl;
            break;
        }

        if (hunger <= 0)
        {
            cout << endl;
            cout << endl;
            cout << "You went too long without eating and can no longer continue." << endl;
            cout << "Game over." << endl;
            break;
        }

        int bigFoot;
        int bf_health;
        int bf_attack;
        bigFoot = (rand() % (100 - 1 + 1)) + 1; // generates a number between 1 and 100.
        bf_health = 100;

        if (bigFoot <= 13) // if number generated = 13 or less, bigfoot will appear.
        {
            cout << endl;
            cout << endl;
            cout << "You ran into a bigfoot!" << endl;
            cin.ignore();
            cin.get();

            while (bf_health > 0)
            {
                bf_attack = (rand() % (20 - 8 + 1) + 8); // attack ranges between 20 and 8

                cout << setw(92) << "////////////////B A T T L E////////////////" << endl;
                cout << endl;
                cout << setw(55) << "HP: " << health;
                cout << setw(30) << "Bigfoot HP: " << bf_health << endl;
                cout << endl;
                cout << setw(92) << "////////////////B A T T L E////////////////" << endl;
                cout << endl;
                cout << setw(71) << "H. Hit" << endl;
                cout << setw(72) << "K. Kick" << endl;
                cout << setw(79) << "Your choice?: ";
                cin >> user_input;
                cout << endl;

                if (user_input == "H" or user_input == "h")
                {
                    if (holding == "Sword" or holding == "Bow and Arrow" or holding == "Wand")
                    {
                        cout << "You hit bigfoot with your " << holding << "!" << endl;
                        cout << "You took " << hit_atk << " points from it's HP!...." << endl;
                        cin.ignore();
                        cin.get();
                        cout << endl;
                        bf_health = bf_health - hit_atk;
                    }

                    if (holding == "None")
                    {
                        cout << "You hit bigfoot! " << endl;
                        cout << "You took " << hit_atk << " points from it's HP!...." << endl;
                        cin.ignore();
                        cin.get();
                        cout << endl;
                        bf_health = bf_health - hit_atk;
                    }

                    if (bf_health <= 0)
                    {
                        cout << "Bigfoot ran off!..." << endl;
                        cout << endl;
                        cin.get();
                        break;
                    }
                    cout << endl;
                    cout << "The bigfoot attacked!" << endl;
                    cout << "You lost " << bf_attack << " points from your HP!..." << endl;
                    cin.get();
                    cout << endl;
                    health = health - bf_attack;
                }

                if (user_input == "K" or user_input == "k")
                {
                    cout << "You kicked bigfoot!" << endl;
                    cout << "You took " << kick_atk << " points from it's HP!..." << endl;
                    cin.ignore();
                    cin.get();
                    cout << endl;
                    bf_health = bf_health - kick_atk;

                    if (bf_health <= 0)
                    {
                        cout << "Bigfoot ran off!..." << endl;
                        cin.get();
                        break;
                    }

                    cout << endl;
                    cout << "Bigfoot attacked!" << endl;
                    cout << "You lost " << bf_attack << " points from your HP." << endl;
                    cin.get();
                    cout << endl;
                    health = health - bf_attack;
                }

                if (health <= 0)
                {
                    cout << "You died!" << endl;
                    cout << "Game over" << endl;
                    done = true;
                    break;
                }
            }
        }
    }
    /**********************************  #6     File I/O *******************************/

    ifstream statfilein;
    ofstream statfileout;
    statfilein.open("endingstats.txt");
    statfileout.open("endingstats.txt", ios::app);

    if (statfilein.is_open())
    {
        statfileout << "*******ENDING STATS*******" << endl;
        statfileout << " " << endl;
        statfileout << "Player: " << player << endl;
        statfileout << "Health: " << health << endl;
        statfileout << "Stamina: " << stamina << endl;
        statfileout << "Hunger: " << hunger << endl;
        statfileout << "Total Miles Traveled: " << miles_traveled << endl;
        statfileout << " " << endl;
        statfileout << "**************************" << endl;
        statfileout << endl;
        statfileout << endl;
    }

    statfilein.close();
    statfileout.close();

    return 0;
}
