#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char ch){
            data = ch;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
            childCount=0;
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
            root->childCount++;
            root->children[index]=child;
        }

        //recursion
        insertUtil(child, word.substr(1));
        // substr(1) means aage vala part bhej diya

    }

    void insertWord(string word){
        insertUtil(root,word);
    }
    

    void printSuggestions(TrieNode* curr, vector<string> & temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
            // we removed return from here as even if TIM is terminated, there can be Time that is our posibility
        }

        for(char ch ='A' ; ch<='Z'; ch++){
            TrieNode* next = curr->children[ch-'A'];
            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix ="";

        for(int i=0; i<str.length();i++){
            char lastch = str[i];
            prefix.push_back(lastch);

            //check for lastch
            TrieNode* curr = prev->children[lastch-'A'];

            // if not found
            if(curr==NULL){
                break;
            }
            // if found
            vector<string> temp;
            printSuggestions(curr, temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }

};


int main()
{

    // implementation a phone dictionary
    vector<string> arr ={"CODE", "CODING","CODINGS","CODLING","COD"};
    int n= arr.size();

    Trie* t = new Trie();
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }

    vector<vector<string>> ans = t->getSuggestion("CODING");
    
    for(auto i: ans){
        for(auto j: i){
            cout<< j<< " ";
        }cout<<endl;
    }

    //TC-> O(n*M^2)
    //SC-> O(n*M)
    //(pending)HW-> dry run atleast 5 time


    return 0;
}