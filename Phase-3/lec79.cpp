// Trie-----introduction

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{

    public:
    TrieNode* root;

    Trie(){
        root= new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //assumptionis that the word is in caps
        int index= word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        //absent
        else{
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion
        insertUtil(child, word.substr(1));
        // substr(1) means aage vala part bhej diya

    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        //same assumption
        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            return false;
        }

        //recursion
        searchUtil(child,word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }

    bool prefixUtil(TrieNode* root, string word){
        //base case
        if(word.length()==0){
            return true; // only this much change
        }
        //same assumption
        int index = word[0]-'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //absent
        else{
            return false;
        }

        //recursion
        prefixUtil(child,word.substr(1));
    }
    bool SearchPrefix(string word){
        return prefixUtil(root,word);
    }


};


int main()
{	

    Trie* t = new Trie();
    string s="HELLO";
    string s2="HELL";
    t->insertWord(s);
    cout<<"Is present? -> "<< (t->searchWord(s)) <<endl;
    
    //(pending)HW--> write code of remove word
    //(pending)HW--> optimize space in removing

    // use in seacrch bar to show suggestion

    // question-> a prefeix is given, now find if there is any word that start with that prefix
    string prefix="HE";
    cout<<"Is present? -> "<< t->SearchPrefix(prefix)<<endl;

    
    return 0;
}