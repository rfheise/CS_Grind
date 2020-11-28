#include "Hash.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <thread>
using namespace std;

Hash<string> * load(string filename);
//Uses Hash function djb2 by Dan Bernstein http://www.cse.yorku.ca/~oz/hash.html
int hashfunction(string words){
    unsigned long hash = 5381;
    for (char c: words) {
        hash = 33 * hash + tolower(c);
    }
    // while ((c = *word++))
    //     hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */
    return hash;
}
class FileNotFoundError {

};
//returns misspellings in file
int check(Hash<string> *dict, string file);
int main(void) {
    Hash<string> *dict = load("words.txt");
    string lists[30] = {"aca.txt", "tolstoy.txt", "constitution.txt", "federalist.txt", "whittier.txt", "burnett.txt", "xueqin2.txt", "revenant.txt", "carroll.txt", "xueqin1.txt", "stoker.txt", "wells.txt", "austen.txt", "frankenstein.txt", "homer.txt", "mansfield.txt", "pneumonoultramicroscopicsilicovolcanoconiosis.txt", "bible.txt", "holmes.txt", "koran.txt", "birdman.txt", "stein.txt", "grimm.txt", "surgery.txt", "rinehart.txt", "lalaland.txt", "wordsworth.txt", "cat.txt", "shakespeare.txt", "her.txt"};
    thread threads[30];
    for (int i = 0; i < 30; i++) {
        threads[i] = thread(check, dict, "./texts/"+lists[i]);
    }
    for (int i = 0; i < 30; i++) {
        threads[i].join();
    }
    // long total = 0;
    // for (int i = 0; i < 30; i++) {
    //     total += check(dict, "./texts/" + lists[i]);
    // }
    // cout << "Total " << total << endl;
    delete dict;
 }


Hash<string> * load(string filename) {
    ifstream in = ifstream(filename);
    if (!in) {
        throw FileNotFoundError();
    }
    Hash<string> * hash = new Hash<string>(hashfunction);
    string buff;
    while(in >> buff) {
        hash -> add(buff);
    }
    in.close();
    return hash;
}




int check(Hash<string> *dict, string file) {
    ifstream in = ifstream(file);
    if (!in) {
        throw FileNotFoundError();
    }
    int count = 0;
    char *word = new char[1000];
    int checked = 0;
    while(in >> word) {
        int len = strlen(word);
        bool setinal = true;
        for (int i = 0; i < len; i ++) {
            //keep apostrophes and alphabetic characters only
            if (isdigit(word[i])) {
                setinal = false;
                break;
            } else if(!isalpha(word[i]) && word[i] != '\'') {
                for (int j = i; j < len - 1; j++) {
                    word[j] = word[j + 1];
                }
                len --;
                i --;
            } else {
                word[i] = tolower(word[i]);
            }
        }
        if(len == 0 || word[0] == '\'' || len > 45) {
            setinal = false;
        }
        word[len] = '\0';
        string buff = word;
        if (setinal && !dict -> check(buff)) {
            count++;
        }
        if (setinal) {
            checked++;
        }
        
    }
    in.close();
    cout << endl;
    cout << file << endl;
    cout << "Words misspelled: " << count << endl;
    cout << "Words checked: " << checked << endl;
    cout << endl;
    delete[] word;
    return count;
}