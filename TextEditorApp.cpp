#include "Text-EditorFunc.h"
//#include "Text-EditorFunc.cpp"



int main()
{
    // ------>     but those insid if to not appear if he choose count / etc   <-----
    string word, filepath,filepath_mod;
    int op;


    while (op != 16)
    {

        op = displayMenu();

        if(op!=16)
        {
            cout << "Enter file Path (Ex: file.txt)\n>>> ";
            cin >> filepath ;
            exist(filepath);
        }

        if(op!=1&&op!=2&&op!=3&&op!=11&&op!=16&&op!=7&&op!=8&&op!=9&&op!=10)
        {
            cout << "Where Do You Need To Save The Change?!..\n>>> ";
            cin >> filepath_mod ;
        }
        if (op == 6)
        {
            cout<<"Enter the second file Path (Ex: file.txt)\n>>>";
            cin >> filepath_mod;
            exist(filepath_mod);
        }

        if (op == 1)
        {
            adding_text(filepath);
        }
        else if (op == 2 )
        {
            display_file(filepath);
        }
        else if (op == 3)
        {
            delete_file(filepath);
        }
        else if (op == 4)
        {
            encrypt_file(filepath,filepath_mod);
        }
        else if (op == 5)
        {
            decrypt_file(filepath,filepath_mod);
        }
        else if (op == 6)
        {
            mergeFiles(filepath,filepath_mod);
        }
        else if (op == 7 )
        {
            n_words(filepath);
        }
        else if (op == 8 )
        {
            n_characters(filepath);
        }
        else if (op == 9 )
        {
            n_lines(filepath);
        }
        else if (op == 10)
        {
            SearchForAWord(filepath);
        }
        else if (op == 11)
        {
            count_word(filepath);
        }
        else if (op == 12)
        {
            all_capital(filepath,filepath_mod);
        }
        else if (op == 13)
        {
            all_small(filepath,filepath_mod);
        }
        else if (op == 14)
        {
            Capitalization(filepath,filepath_mod);
        }
        else if (op == 15)
        {
            return 0;
        }
        else
        {
            cout << "Thanks for using our App." << endl;
            return 0;
        }
    }
    return 0;
}

