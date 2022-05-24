// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text-Editor.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: Abdelrahman Tarek Mohamed	20210206
// Author2 and ID and Group: Adel xxxxx
// Author3 and ID and Group: Roaa Talat Mohamed         20210138
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........

#include "Text-EditorFunc.h"

vector<string> fileData;

void loodDataOfFile(string fileName)
{
    int i = 0;
    string data;
    fstream file;

    file.open(fileName,ios::out );

    if(file.is_open())
    {

        //string lines;
        //getline(file, lines);

        while (!file.eof()) //while the end of file is NOT reached
        {
            getline(file,data,' ');
            fileData.push_back(data);
            i += 1;
        }
        file.close();
    }
}

void saveToFile(string data, string fileName)
{
    fstream file ;
    file.open(fileName, ios::app);
    file << data;
    file.close();
}

int displayMenu()
{
    int option;
    cout << "Ahlan ya 3m El-User:-\n";
    cout << "What You Need to DO ?!"<<endl;
    cout << "1. Add new text to the end of the file "<< endl;
    cout << "2. Display the content of the file "<< endl;
    cout << "3. Empty the file "<< endl;
    cout << "4. Encrypt the file content  "<< endl;
    cout << "5. Decrypt the file content "<< endl;
    cout << "6. Merge another file "<< endl;
    cout << "7. Count the number of words in the file. "<< endl;
    cout << "8. Count the number of characters in the file "<< endl;
    cout << "9. Count the number of lines in the file "<< endl;
    cout << "10. Search for a word in the file "<< endl;
    cout << "11. Count the number of times a word exists in the file "<< endl;
    cout << "12. Turn the file content to upper case. "<< endl;
    cout << "13. Turn the file content to lower case. "<< endl;
    cout << "14. Turn file content to 1st caps (1st char of each word is capital)  "<< endl;
    cout << "15. Save" <<endl;
    cout << "16. Exit \n>>> " <<endl;
    cin >> option;
    return option;
}

void exist(string PATH)
{
    ifstream file;
    file.open(PATH);
    if(file)
    {
        cout << "This File Already Exists\n";
    }
    else
    {
        cout << "This is a new file. I created it for you :) ... \n";
        file.open(PATH, ios::out);
    }
}

void adding_text(string path)
{
    fstream file;
    string text;
    file.open(path, ios::app);
    if (file.is_open())
    {
        cin.ignore();
        cout <<"enter the text you want to add: ";
        getline(cin,text);
        file << text <<endl;
        file.close();
        cout << "\n\nDone.\n";
    }
    else
    {
        cout <<"File open error!" << endl;
    }

}

void display_file(string path)
{
    fstream file;
    file.open(path, ios::in);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout <<line <<endl;
        }
        file.close();
    }
    else
    {
        cout <<"File open error!" << endl;
    }
}

void delete_file(string path)
{
    fstream file;
    string text;
    file.open(path, ios::out);
    if (file.is_open())
    {
        file << " " <<endl;
        file.close();
        cout << "\n\nDone.\n";
    }
    else
    {
        cout <<"File open error!" << endl;
    }
}

void encrypt_file(string old_Path,string new_path)
{
    fstream file;
    fstream file_mod;
    string line;
    file.open(old_Path, ios::in);
    file_mod.open(new_path,ios::app);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            string encrypt;
            for(int i=0; i<line.size(); i++)
            {
                char a=line[i]+1;
                encrypt+=a;
            }
            file_mod << encrypt<<endl;
        }
        file.close();
        file_mod.close();
        cout << "\n\nDone.\n";
    }
    else
    {
        cout <<"File open error!" << endl;
    }

}

void decrypt_file(string old_Path,string new_path)
{
    fstream file;
    fstream file_mod;
    string line;
    file.open(old_Path, ios::in);
    file_mod.open(new_path,ios::app);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            string decrypt;
            for(int i=0; i<line.size(); i++)
            {
                char a=line[i]-1;
                decrypt+=a;
            }
            file_mod << decrypt<<endl;
        }
        file.close();
        file_mod.close();
        cout << "\n\nDone.\n";
    }
    else
    {
        cout <<"File open error!" << endl;
    }

}

void mergeFiles(string old_Path,string new_path)
{
    /*int size = fileData.size();
    loodDataOfFile(new_path);
    for (int i = 0; i < size; i++)
    {
        saveToFile(fileData[i], new_path);
    }
    fstream file , oldFile;
    file.open(new_path, ios::out);
    oldFile.open(old_Path, ios:: app);
    string word;
    while (file >> word)
    {
        oldFile << word<<" ";
    }*/
    int i = 0;
    string data;
    fstream file, oldFile;
    file.open(new_path, ios:: in | ios:: out);
    oldFile.open(old_Path, ios:: app);
    vector <string> lines;
    if(file.is_open())
    {
        while (file.good()) //while the end of file is NOT reached
        {
            getline(file, data);
            lines.push_back(data);
        }
        file.close();
    }
    for(; i < lines.size(); i++)
    {
        saveToFile(lines[i], old_Path);
    }

}



void n_words(string path)
{
    fstream file;
    file.open(path, ios::in);
    char ch;
    int words=0;
    if (file.is_open())
    {
        file.get(ch);
        while(file)
        {
            if (ch == ' ')
                words++;
            file.get(ch);
        }
        cout <<"number of words = "<<words <<endl;
    }
    else
    {
        cout <<"File open error!" << endl;
    }
}

void n_characters(string path)
{
    fstream file;
    file.open(path, ios::in);
    char ch;
    int chr=0;
    if (file.is_open())
    {
        file.get(ch);
        while(file)
        {
            if(ch !=' ' || ch !='\n')
                chr++;
            file.get(ch);
        }
        cout << "number of characters = " <<chr <<endl;
    }
    else
    {
        cout <<"File open error!" << endl;
    }
}
void n_lines(string path)
{
    fstream file;
    file.open(path, ios::in);
    char ch;
    int lines=0;
    if (file.is_open())
    {
        file.get(ch);
        while(file)
        {
            if (ch == '\n')
                lines++;
            file.get(ch);
        }
        cout <<"number of lines = " <<lines <<endl;
    }
    else
    {
        cout <<"File open error!" << endl;
    }
}


void SearchForAWord(string path)
{
    string word;
    cout<<"what the word you need to search for it";
    cin >> word;
    for(int i = 0; i < word.length() ; i++ )
    {
        word[i] = tolower(word[i]);
    }
    loodDataOfFile(path);
    for(int i = 0; i < fileData.size(); i++)
    {
        string dataWord = fileData[i];
        for(int j = 0; j < dataWord.length(); j++ )
        {
            dataWord[j] = tolower(dataWord[j]);
        }

        if( word == fileData[i])
        {
            cout<<"Word was found in the file :)"<<endl;
        }
        else
        {
            cout<<"Word was not found in the file :("<<endl;
        }
    }
}
void word_By_word(string path)
{
    fstream file;
    string word;
    file.open(path, ios::in);
    if (file.fail())
        cout << "File open error!" << endl;
    else
    {
        cout << "File opened successful.\n";

        while (file >> word)
        {
            cout << word << endl;
        }
        file.close();
        cout << "\n\nDone.\n";
    }
}

void count_word(string path)
{

    ifstream file;
    string word, i_word;
    int times = 0;

    // opening file
    file.open(path, ios::in);
    cout << "Enter what you need to search:-\n>> ";
    cin >> i_word;

    // extracting words from the file
    while (file >> word)
    {
        if (capital(word) == capital(i_word))
        {
            times ++;
        }
    } // ------------------------>   IF I SERCH ABOUT ID IT SHOW (NO. + 1) ?!!!!!
    cout <<"The word '" << i_word << "' Showed in file " <<times << " times....\n";
    file.close();
}

void Capitalization(string old_Path,string new_path)
{
    fstream file;
    fstream file_mod;
    string word;
    char op;

    file.open(old_Path, ios::in);
    cout << "Are You Need Save change with last Cahnge?!. ";
    cin >> op;
    if (op == 'y')
    {
        file_mod.open(new_path, ios::out | ios::app);
    }
    else if (op == 'n')
    {
        file_mod.open(new_path, ios::out);
    }

    while (file >> word)
    {
        if (word[0] > 96 && word[0] < 123)
        {
            word[0] = word[0] - 32;
        }
        file_mod << word[0];

        for (int i = 1 ; i < word.length(); i++)
        {
            if (word[i] > 64 && word[i] < 91)
            {
                word[i] = word[i] + 32;
            }
            file_mod << word[i];
        }

        file_mod << " ";
    }
    file.close();
    file_mod.close();
}

void all_capital(string old_Path,string new_path)
{
    fstream file;
    fstream file_mod;
    string word;
    char op;

    file.open(old_Path, ios::in);
    cout << "Are You Need Save change with last Cahnge?!. ";
    cin >> op;
    if (op == 'y')
    {
        file_mod.open(new_path, ios::out | ios::app);
    }
    else if (op == 'n')
    {
        file_mod.open(new_path, ios::out);
    }
    while (file >> word)
    {
        for (int i = 0 ; i < word.length(); i++)
        {

            if (word[i] > 96 && word[i] < 123)
            {
                word[i] = word[i] - 32;
            }
            file_mod << word[i];
        }
        file_mod << " ";
    }
    file.close();
    file_mod.close();
}

void all_small(string old_Path,string new_path)
{
    fstream file;
    fstream file_mod;
    string word;
    char op;

    file.open(old_Path, ios::in);
    cout << "Are You Need Save change with last Cahnge?!. ";
    cin >> op;
    if (op == 'y')
    {
        file_mod.open(new_path, ios::out | ios::app);
    }
    else if (op == 'n')
    {
        file_mod.open(new_path, ios::out);
    }

    while (file >> word)
    {
        for (int i = 0 ; i < word.length(); i++)
        {
            if (word[i] > 64 && word[i] < 91)
            {
                word[i] = word[i] + 32;
            }
            file_mod << word[i];
        }
        file_mod << " ";
    }
    file.close();
    file_mod.close();
}


string capital(string WORD)
{
    string new_word=" ";
    for (int i = 0 ; i < WORD.length(); i++)
    {

        if (WORD[i] > 96 && WORD[i] < 123)
        {
            WORD[i] = WORD[i] - 32;
        }
        new_word =+ WORD[i];
    }
    return new_word;
}
