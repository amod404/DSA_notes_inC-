//char array,string
#include<iostream>
#include<string>
using namespace std;

bool valid(char ch){
    if((ch>='a'&& ch<='z')||(ch>='A' && ch<='Z')||(ch>='0'&& ch<='9')){
        return 1;
    }
    return 0;
}

char toLowerCase(char ch){
    if((ch>='a'&& ch<='z')||(ch>='0'&& ch<='9')){
        return ch;
    }
    else{
        return (ch-'A'+'a');
    }
}

bool isPalindrome(string s){

    //faltu character hata do
    int i=0;
    string temp="";
    for(int j=0;j<s.length();j++){
        if(valid(s[j])){
            temp.push_back(s[j]);
        }
    }

    //lower case mai kr do
    for(int j=0;j<temp.length();j++){
        temp[j]=toLowerCase(temp[j]);
    }

    // checking for palindrome
    for(int i=0,j=temp.length()-1;i<j;j--,i++){
        if(temp[i]!=temp[j]){
            return 0;
        }
    }
    return 1;
}

void flip(string &s){
    s.push_back(' ');
    int k=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){  //finding the space 
            int j=i-1;   // last character
            while(k<j){
                swap(s[j],s[k]);
                k++;
                j--;
            }
            k=i+1;  //first char for next iteration
        }
    }
}

string replace_space(string s){
    int i;
    for(i=0;i<s.length();i++){
        if(s[i]==' '){
            
            // // logical but brute force
            // s.push_back(' ');  //adding extra places to add @40
            // s.push_back(' ');
            // k=s.length();      // shifting forward
            // for(;k>=i+2;k--){
            //     s[k]=s[k-2];
            // }
            // s[i]='@';         //remove that space with @40
            // s[i+1]='4';
            // s[i+2]='0';
            
            s.erase(i,1);
            s.insert(i,"@40");
        }
    }
    return s;
}

string sub_s(string s,string part){

    while(s.length()!=0 && s.find(part) < s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

bool ifif(int x[26],int y[26]){
    int n=26;
    for(int i=0;i<n;i++){
        if(x[i]!=y[i]){
            return 0;
        }
    }
    return 1;
}

//fault program
bool find_perm(string s1, string s2){
//     int count2[26]={0};
//     for(int i=0;i<s2.length();i++){   //learn this method to store the value of char in a string
//         int index=s2[i]-'a';
//         count2[index]++;
//     } //we stored values of sub_string in count2

//     int i=0;
//     int count1[26]={0};
//     int window=s2.length();
//     for(int i=0;i<window;i++){
//         int index=s1[i]-'a';
//         count1[index]++;
//     } //stored values for first window in count 1;

//     if(ifif(count1,count2)){
//         return 1;
//     }
    
//     while(i<s1.length()){

//         count1[s1[i]-'a']++;
//         // other way to represent
//         // int newChar = s1[i];
//         // int index1=newChar-'a';
//         // count1[index1]++;

        
//         count1[s1[i-window]-'a']--;
//         // other way represent
//         // int oldChar = s1[i-window];
//         // int index2=oldChar-'a';
//         // count1[index2]--;

//         i++;
//         if(ifif(count1,count2)){   //checking if equal
//             return 1;
        // }
        
//         for(int k=0;k<26;k++){
//             cout<<count1[k]<<" ";
//         }cout<<endl;
//         for(int k=0;k<26;k++){
//             cout<<count2[k]<<" ";
//         }cout<<endl<<endl;
//     }
//     return 0;
}

//working program
bool find_permutation(string s,string part){
    int count1[26]={0},count2[26]={0};
    int window=part.length();

    // storing our part
    for(int k=0;k<part.length();k++){
        count2[part[k]-'a']++;
    }

    int i; //storing first window
    for(i=0;i<window;i++){
        count1[s[i]-'a']++;
    }
    //first check
    if(ifif(count1,count2)){
        return 1;
    }    

    while(i<s.length()){
        // adding new char and removing new char in count1
        count1[s[i]-'a']++;
        count1[s[i-window]-'a']--;

        if(ifif(count1,count2)){
            return 1;
        }    

        i++;
    }
    return 0;
}

string remove_d(string s){
    string :: iterator it;  //first time dealing with a iterator
    it=s.begin();
    for(;it!=s.end();){
        if(*it==*(it+1)){
            s.erase(it+1);
            s.erase(it);
            it--;
        }
        else{
            it++;
        }
    }
    return s;
}

//debugged myself :>
void s_comp(string &s){
    //Here s is sorted
    int i=0;
    int ansIndex=1;

    while(i<s.size()){
        int j=i+1;
        while(j<s.size() && s[i]==s[j]){
            j++;
        }
        //ya to string puri traverse ho jayegi
        //ya to different character encounter hoga
        
        //old index save kr lo
        int count=j-i;
        if(count>1){
            string cnt = to_string(count);
            for(char ch: cnt){
                s[ansIndex++]=ch;
            }
        }
        i=j;
        s[ansIndex++]=s[i];
        if(j==s.size()-1){
            break;
        }
    }
    s.erase(ansIndex);
}

int main()
{
    //char variable can sore only one character
    //here we use char array,and string
    
    //faltu character hatao
    //sab lowercase kro
    //check palindrome
    // char arr[10];
    // string s="Nam@#!an";
    // cout<<"Is palindrome? "<< isPalindrome(s);

    //Exploring how to input sentence
    // string s;
    // getline(cin, s);
    // cout<<s<<endl;
    // char name[100];
    // cin.getline(name,sizeof(name));
    // cout<<name<<endl;
    
    //print reverse of each word of and sentence
    // string s;
    // getline(cin,s);
    // cout<<s<<endl;
    // flip(s);
    // cout<<s<<endl;
    
    //HW....custom delimeter
    // string s;
    // getline(cin,s,'\t');
    // cout<<s<<endl;

    //HW....Replace space with @40
    // string s;
    // getline(cin,s);
    // cout<< s <<endl; 
    // cout<< replace_space(s) <<endl; 
    
    //remove all ocurrance of a substring 
    // string s;
    // s="acbabccaabcbca";
    // string ss=sub_s(s,"abc");
    // cout<<ss;
    
    // HW(done)....permutation in string
    // string s1="abcdefg";
    // string s2="gfedcba";
    // cout<<"IS present-->"<<find_Perm(s1,s2)<<endl;

    // HW...remove dublicate character
    // string s="azxxggsttszpy";
    // cout<<remove_d(s)<<endl;

    // HW(done)...string comperation
    // string s="aaaaaaaabbbbbbbdccccccccccce";
    // s_comp(s);
    // cout<<s<<endl;
    
    return 0;
}
