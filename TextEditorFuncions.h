// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text-Editor.cpp
// Last Modification Date: 16/05/2022
// Author1 and ID and Group: Abdelrahman Tarek Mohamed	20210206
// Author2 and ID and Group: Adel Magdy Abd El-Hay      20210190
// Author3 and ID and Group: Roaa Talat Mohamed         20210138
// Teaching Assistant: Dr.Mohamed Al Ramly
// Purpose:..........


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

void loodDataOfFile(string fileName);
void saveToFile(string data, string fileName);
int displayMenu();
void adding_text(string path);
void display_file(string path);
void delete_file(string path);
void encrypt_file(string old_Path,string new_path);
void decrypt_file(string old_Path,string new_path);
void mergeFiles(string old_Path,string new_path);
void n_words(string path);
void n_characters(string path);
void n_lines(string path);
void SearchForAWord(string path);
void word_By_word(string path);
void count_word(string path);
void Capitalization(string old_Path,string new_path);
void all_capital(string old_Path,string new_path);
void all_small(string old_Path,string new_path);
void exist(string PATH);
string capital(string WORD);
