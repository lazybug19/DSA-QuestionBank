#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    int wordEnded = 0;
    TrieNode* letters[26];
    set<string> wordsTillHere;

    bool nodeExists(char ch){
        return letters[ch-'a'];
    }

    TrieNode* getNode(char ch){
        return letters[ch-'a'];
    }

    void addNode(char ch, TrieNode* node){
        letters[ch-'a'] = node;
    }

    void addWord(string word){
        wordsTillHere.insert(word);
    }

    set<string> getWords(){
        return wordsTillHere;
    }
};

class Trie {
    TrieNode* root;
    
    public:
    Trie() {
        root = new TrieNode();
    }

    void addWord(string word){
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            temp->addWord(word);
            if(!temp->nodeExists(word[i])){
                TrieNode* newNode = new TrieNode();
                temp->addNode(word[i], newNode);
            }
            temp = temp->getNode(word[i]);
        }   
        temp->addWord(word);
        temp->wordEnded = 1;
    }

    set<string> startsWith(string word){
        set<string> empty;
        TrieNode* temp = root;
        for(int i=0; i<word.length(); i++){
            if(!temp->nodeExists(word[i])){
              return empty;
            }
            temp = temp->getNode(word[i]);
        }
        return temp->getWords();        
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie* trie = new Trie();
    sort(contactList.begin(), contactList.end());
    for(auto x: contactList) trie->addWord(x);
    vector<vector<string>> answer;

    string temp = "";
    for(int i=0; i<queryStr.length(); i++){
        temp += queryStr[i];
        set<string> s = trie->startsWith(temp);
        vector<string> tempVec;
        if(s.size() > 0){
            for(auto word: (trie->startsWith(temp))){
                tempVec.push_back(word);
            }
            answer.push_back(tempVec);
        }
    }

    return answer;
}