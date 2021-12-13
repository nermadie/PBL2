#pragma once
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

//check if string s is a number
bool isNumber(string s) 
{
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0';
}

//change text color in terminal
void printLineColor(string line, int color_code) 
{
    HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, color_code);
    cout << line;
    SetConsoleTextAttribute(color, 7);
}

//print notification
void printError(string status) 
{
    printLineColor("ERROR ", 67);
    printLineColor(status, 4);
    cout << "\n";
}

//print notification
void printSuccess(string status) 
{
    printLineColor("SUCCESS ", 37);
    printLineColor(status, 2);
    cout << "\n";
}

int getIntInput(string title) 
{
    string value;
    printLineColor(title + ": ", 6); 
    fflush(stdin); getline(cin, value); 
    while (!isNumber(value)) 
    {
        printError("Invalid value!");
        printLineColor(title + ": ", 6);
        fflush(stdin); 
        getline(cin, value);
    }
    return stoi(value);
}

string getStringInput(string title) 
{
    string value;

    printLineColor(title + ": ", 6);
    fflush(stdin);
    getline(cin, value);
    return value;
}

char getCharInput(string title)
{
    char value;
    printLineColor(title + ": ", 6);
    cin >> value;
    return value;
}

char StringToChar(string line)
{
    char c;
    const char *p = line.c_str();
    c = p[0];
    return c;
}