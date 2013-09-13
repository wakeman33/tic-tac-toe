/*
 * =====================================================================================
 *
 *       Filename:  tools.cpp
 *
 *    Description:  Test file to output the ascii text files for the title.
 *
 *        Version:  1.0
 *        Created:  09/12/2013 23:15:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kegan Pankratz (), ridinthewave33@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <fstream>
#include "tools.h"
using namespace std;

void printWelcome(void) {
    ifstream graphics_file;
    string line;
    graphics_file.open("graphics/graphics-title1.txt");
    
    if(!graphics_file.is_open()) {
        cerr << "File failed to open!!!." << endl;
    }
    
    // Clear current screen. Hope to enhance with courses
    for (int i = 0; i < 100; i++) {
        cout << '\n';
    }

    // Print first title
    while(getline(graphics_file, line)) {
        cout << "\t" <<  line << "\n";
    }

    cout << endl;

    graphics_file.close();
    graphics_file.open("graphics/graphics-title2.txt");

    // Print second title.
    while(getline(graphics_file, line)) {
        cout << line << "\n";
    }
 
    // Leave space after title.
    for(int i = 0; i < 10; i++) {
        cout << '\n';
    }
}
