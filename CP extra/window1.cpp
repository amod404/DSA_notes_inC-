#include<bits/stdc++.h>
#define CLEAR system("cls")
using namespace std;

string smallestWindow(string &s, string &s2) {
        // Your code here
        
        int n = s.length();
        int m = s2.length();
        unordered_map<char,int>main;
        unordered_map<char,int>window;
        string ans = "";
        int ansl = 1e9;
        for(int i=0; i<m; i++){
            main[s2[i]]++;
        }  
        
        int i=0,j=0,count=0;
        
        for(int k=0; k<n; k++){
            if(main[s[k]]){
                i = k;
                j = k;
                count++;
                window[s[k]]++;
                if(count==m){
                    ans = s.substr(i,j-i+1);
                    ansl = j-i+1;
                }
                break;
            }
        }
        
        if(count==0){
            return ans;
        }
        
        j++;
        while(j<n){
            if(main[s[j]]){
                window[s[j]]++;
                if(window[s[j]]<=main[s[j]]){
                    count++;
                }
                while(i<j){
                    if(main[s[i]]==0){
                        i++;
                    }
                    else if(window[s[i]]>main[s[i]]){
                        window[s[i]]--;
                        i++;
                    }
                    else{
                        break;
                    }
                }
                if(count==m && j-i+1 < ansl){
                    ansl = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
            }    
            j++;
        }
        
        return ans;
    }

int main(){
    string s1 = "timetopractice";
    string s2 = "toc";
    cout<<smallestWindow(s1,s2)<<endl;
    return 0;
}
