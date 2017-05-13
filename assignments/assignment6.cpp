//  main.cpp
//  CS 161 Assignment #6
//  Created by Xilun Guo on 3/11/15.
//  Copyright (c) 2015 assignment6. All rights reserved.

/*********************************************************************
 ** Program Filename: Assignment #6
 ** Author: Xilun Guo
 ** Date: 03/11/2015
 ** Description: Using struct for this assignment. Print out information that user inpuut, one of them using array.
 ** Input: Title, number of stars, number of cast, name of cast, rating.
 ** Output: Tile, number of stars, name of cast, rating.
 *********************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;

struct netflix {
    string name;
    int stars, num_cast;
    string *cast; // This is a dynamic array of string
    string rating;
};

/********** function prototype  ***********/

bool play_again();
int get_number_of_stars(netflix *movie);
int get_number_of_cast(netflix *movie);
void get_casts(netflix *movie);
void print_data(netflix *movie);

/*********************************************************************
 ** Function: main function
 ** Description: runing the whole program.
 ** Parameters:
 ** Pre-Conditions: number of stars and number of cast are int.
 ** Post-Conditions: chocie == 1
 *********************************************************************/

int main() {
    struct netflix movie;
    int choice = play_again();
    while(choice == 1)
    {
        cout << "Enter the name of your movie: ";
        cin >> movie.name;
        movie.stars = get_number_of_stars(&movie);
        movie.num_cast = get_number_of_cast(&movie);
        get_casts(&movie);
        cout << "Enter the movie rati1ng: ";
        cin >> movie.rating;
        print_data(&movie);
        delete [] movie.cast;
        choice = play_again();
    }
    return 0;
}

/*********************************************************************
 ** Function: play_again function
 ** Description: runing the whole program again or not depend of the choice is T/F.
 ** Parameters:
 ** Pre-Conditions:  
 ** Post-Conditions:
 *********************************************************************/

bool play_again()
{
    int choice;
    cout << "Do you want to enter a movie to the database?  1 - Yes, 0 - No  ";
    cin >> choice;
    if (choice == 1)
        return true;
    return false;
}

/*********************************************************************
 ** Function: checking function
 ** Description: check the input are int or not.
 ** Parameters: input
 ** Pre-Conditions: check == 1
 ** Post-Conditions:
 *********************************************************************/

int check_input(string input)
{
    int check = 1;
    for (int i = 0; i < input.length(); i++)
    {
        if(input[i] < '0' || input[i] > '9')
            check = 0;
    }
    return check;
}

/*********************************************************************
 ** Function: get num of stars
 ** Description: get the user input the num of stars
 ** Parameters: netflix *movie
 ** Pre-Conditions:
 ** Post-Conditions: input1 is int
 *********************************************************************/

int get_number_of_stars(netflix *movie)
{
    string input1;
    int check;
    do
    {
        cout << "How many stars? ";
        cin >> input1;
        check = check_input(input1);
    }while (check == 0);
    
    stringstream ss(input1);
    ss >> movie->stars; // converting the string into int
    
    return movie->stars;
}

/*********************************************************************
 ** Function: get num of cast
 ** Description: get the user input the num of cast
 ** Parameters: netflix *movie
 ** Pre-Conditions:
 ** Post-Conditions: input2 is int
 *********************************************************************/

int get_number_of_cast(netflix *movie)
{
    string input2;
    int check;
    do
    {
        cout << "How many cast member? ";
        cin >> input2;
        check = check_input(input2);
    }while(check == 0);
    
    stringstream ss(input2);
    ss >> movie->num_cast; // converting the string into int
    
    return movie->num_cast;
}

/*********************************************************************
 ** Function: get name of each cast
 ** Description: get name of each cast using array on the heap by for loop.
 ** Parameters: netflix *movie
 ** Pre-Conditions: input2 is int
 ** Post-Conditions:
 *********************************************************************/

void get_casts(netflix *movie)
{
    movie->cast = new string[movie->num_cast];
    cin.ignore();// this is able to avoid the getline and cin mass up.
    for (int i = 1; i <= movie->num_cast; i++)
    {
        cout << "Enter cast member " << i << " : ";
        getline(cin, movie->cast[i-1]);// in order the get the name with space.
    }
}

/*********************************************************************
 ** Function: printing data from all the user input
 ** Description: printing the info one by one from the user input, the hardest part is printing the array.
 ** Parameters: netflix *movie
 ** Pre-Conditions:
 ** Post-Conditions: input1&2 are int
 *********************************************************************/

void print_data(netflix *movie)
{
    cout << "Your movie entry is:" << endl;
    cout << "Title: " << movie->name << endl;
    cout << "Stars: " << movie->stars << endl;
    cout << "Cast: ";
    for (int i = 0; i < movie->num_cast; i++)
    {
        cout << movie->cast[i] << ",  ";
    }
    cout << endl;
    cout << "Rating: " << movie->rating <<endl;
}





