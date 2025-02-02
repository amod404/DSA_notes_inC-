// Trie->question

#include<iostream>
#include<string>
#include<vector>
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
    
    void lcp(string str, string & ans){
        int n= str.length();
        for(int i=0;i<n;i++){
            char ch = str[i];

            if(root->childCount==1){
                ans.push_back(ch);
                //age bd jao
                int index= ch -'A';
                root= root->children[index];
            }
            else{
                break;
            }
            if(root->isTerminal){
                break; // means a word end
            }
        }
    }

};

//normal approach.....working
string longestCommonPrefix(vector<string> & arr){
    int n= arr.size();
    string ans;
    //for traverse all characters of firt string
    for(int i=0;i<arr[0].length();i++){
        char ch = arr[0][i];

        bool match = true;
        // for comparing ch with rest of the string
        for(int j=1;j<n;j++){
            //not match
            if(arr[j].size()<i || ch!= arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
}

int main()
{

    // finding maximum commom prefix;
    vector<string> arr ={"CODING","CODEZEN","CODINGNIZJA","CODERS"};
    int n= arr.size();
    // approach 1-> can iterate through all and if any of the character in all string at that index is not equal, return
    // TC-->O(n*m)  ... n is number of string ans m is size of minimum string
    //approach 2-> use trie and find that TrieNode which have children node more than one;
    // in this we have to make a variable which store count of cildren

    cout<<longestCommonPrefix(arr)<<endl;

    Trie* t = new Trie();
    for(int i=0; i<n;i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans ="";
    t->lcp(first,ans);
    cout<<ans<<endl;
    return 0;
}
