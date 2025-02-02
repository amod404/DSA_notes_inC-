//recursion-02 (basic++)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void reachHome(int src, int dest){
    //base case
    if(src==dest){
        cout<<"pahuch gya";
        return;
    }

    //processing
    cout<<"remaining steps:"<<dest-src<<endl;

    //recursive call
    src++;
    reachHome(src,dest);
}

int fibo(int m){
    if (m==1){
        return 0;
    }
    if(m<=2){
        return 1;
    }

    return fibo(m-1)+fibo(m-2);    
}
//same sequence as fibonacci sequence
int ways_to_climb(int m){
    if(m==1){
        return 1;
    }
    if(m==2){
        return 2;
    }
    return ways_to_climb(m-1)+ways_to_climb(m-2);
}
//without backspace and debug...wrote within 1.5 min
void say_digit(int n){
    if(n==0){
        return;
    }
    string s;
    switch(n%10){
        case 0: s="zero"; break;
        case 1: s="one"; break;
        case 2: s="two"; break;
        case 3: s="three"; break;
        case 4: s="four"; break;
        case 5: s="five"; break;
        case 6: s="six"; break;
        case 7: s="seven"; break;
        case 8: s="eight"; break;
        case 9: s="nine"; break;
    }

    say_digit(n/10);
    cout<<s<<" ";
}

int main()
{
    //revision-->reaching home
    // int s,d;
    // cin>>s>>d;
    // reachHome(s,d);

    //finding nth term of fibonaci series 
    //FIbonaci series--> n+2) = n+1) + n)
    // 0 1 1 2 3 5 8 13 21 34......
    // int m;
    // cin>>m;
    // cout<<fibo(m)<<endl;

    //say digit by recursion
    // int n;
    // cin>>n;
    // say_digit(n);

    //(done)HW-->make recursion tree and call stack of say_digit
    return 0;
}





