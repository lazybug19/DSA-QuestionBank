/*
You are given a character array keys containing unique characters and a string array values containing strings of 
length 2. You are also given another string array dictionary that contains all permitted original strings after 
decryption. You should implement a data structure that can encrypt or decrypt a 0-indexed string.

A string is encrypted with the following process:

For each character c in the string, we find the index i satisfying keys[i] == c in keys.
Replace c with values[i] in the string.
Note that in case a character of the string is not present in keys, the encryption process cannot be carried out, 
and an empty string "" is returned.

A string is decrypted with the following process:

For each substring s of length 2 occurring at an even index in the string, we find an i such that values[i] == s. 
If there are multiple valid i, we choose any one of them. This means a string could have multiple possible strings 
it can decrypt to. Replace s with keys[i] in the string.
Implement the Encrypter class:

Encrypter(char[] keys, String[] values, String[] dictionary) Initializes the Encrypter class with keys, values, and 
dictionary. String encrypt(String word1) Encrypts word1 with the encryption process described above and returns the 
encrypted string. int decrypt(String word2) Returns the number of possible strings word2 could decrypt to that also 
appear in dictionary.
*/


class Encrypter {
public:
    unordered_map<char, string> encrypter;
    unordered_map<string, vector<string>> decrypter;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0; i<keys.size(); i++) encrypter[keys[i]]=values[i];

        // Storing dictionary in encrypted form is the key
        for(string s: dictionary)
        {
            string r=encrypt(s);
            decrypter[r].push_back(s);
        }
    }
    
    string encrypt(string word1) {
        string res;
        for(char c: word1) 
        {
            if(encrypter.find(c)!=encrypter.end()) res+=encrypter[c];
            else return "";
        }
        return res;
    }
    
    int decrypt(string word2) {
        if(decrypter.find(word2)!=decrypter.end()) return decrypter[word2].size();
        return 0;
    }
};
