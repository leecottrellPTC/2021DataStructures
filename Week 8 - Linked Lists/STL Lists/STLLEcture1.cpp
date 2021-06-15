#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <forward_list>
#include <algorithm>
#include <iterator>

using namespace std;

forward_list <string> adjectives, nouns, allWords;
void readFile(string path, forward_list<string>& theList)
{
    std::ifstream fin(path);

    if (fin.fail()){
     
        std::exit(-1);
    }

    std::string ln;
    int count = 0;
    while (!fin.eof())
    {
        std::getline(fin, ln);
        theList.push_front(ln);//add to the list
        count ++;
    }
    cout << count << " words read from " << path << endl;
    fin.close();
    theList.sort();
}

void showList(forward_list<string> theList){
    //iterators will walk through the data structure
    //iterators are of the data type that is in the structure
    forward_list<string>::iterator word;
    int count = 1;
    for(word = theList.begin(); word != theList.end(); word++){
        cout << left << setw(15) << *word;
        if(count %5 == 0){
            cout << endl;//print 5 per line
        }
        count ++;
    }
}

void caseString(string &word){
    //convert a word to upper case
    //one letter at a time
    for(char& x : word){
        x = toupper(x);
    }
}
int main()
{
    readFile("adjective.txt",adjectives);
    readFile("nouns.txt",nouns);

    allWords.splice_after(allWords.before_begin(), adjectives);
    allWords.splice_after(allWords.before_begin(), nouns);
    allWords.sort();
    cout << "\nAll words\n";

    for_each(allWords.begin(), allWords.end(), caseString);

    showList(allWords);

}