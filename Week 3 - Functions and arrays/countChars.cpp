#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <string.h> //old school, has strcpy_s
//read the dracula file
//count the A, B, C, ....
//use an array as a counter

using namespace std;

int letters[26];    //A = 0, B = 1, C = 2...
int lineCount = 0;

void parseFile(string path);
void countLetters(string line);
void showCounts();

int main()
{
    parseFile("Dracula.txt");
    showCounts();
}
void parseFile(string path){
    //parse means read
    ifstream fin;
    string line;
    fin.open(path);
    if(fin.fail()){
        cout << path << " did not open, quitting" << endl;
        exit(1);//kills the running program
    }
    //do something with file
    while(getline(fin, line)){
       // cout << line << endl;
       countLetters(line);
       lineCount ++;
    }
    //cout << path << " opened!\n";
    fin.close();

}

void countLetters(string line){
    //strings act like arrays
    char let;
    for(int l = 0; l < line.length(); l++){
        //cout << line.at(l) << endl;
        let = toupper(line.at(l));
        if(let >= 65 && let <= 90){
            //count the letter
            letters[let - 65]++;//using array as counter
            /*
            if(let == 'A'){
                letters[0] ++;
            }
            else if(let == 'B'){
                letters[1] ++;
            }
            */
        }
    }
    
}//end of count letters

void showCounts(){
    for(char let = 'A'; let <= 'Z'; let ++){
        cout << let << setw(9) << letters[let - 65] << endl;
    }
    cout << "Lines read " << lineCount << endl;
}