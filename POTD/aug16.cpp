

//  >> VERY IMPORTANT POINT FROM TODAY'S POTD

//Aur hn ajj s hmesha yaad rkhna ki agr hme ab s kbhi kisi num ki ek ek digit ko access krna
//h to hm usko pehle string m convert krenge phir string s access krnege bcoz num m hm 
//ek ek digit ko access ni kr skte





#include <bits/stdc++.h>
using namespace std;
int maximum69Number (int num) {
        int ans= -1e9;
        string s= to_string(num);
        int n= s.length();
        bool op= false;
        for(int i=0;i<n;i++){
            if(s[i]=='9'){
                int temp= stoi(s);
                ans= max(ans,temp);
            } else{
                if(op==false){
                    s[i]='9';
                    op= true;
                    int temp2= stoi(s);
                    ans= max(ans,temp2);
                }
            }
        }
        return ans;
    }

//TC -> 0(length of string, which also the num itself) kindoff 0(1)
//SC -> 0(1)

//this was the brute force approach we can use a shortcut or a kind of smart technique
//which is also called (replace - first) technique
//which means jo sbse pehle mile usko replace krdo search krke

//kuki as we know ki koi num h jse 9686 to isme agr hm left side s pehle 6 ko nine bnayenge 
//to vo jyada impact krega num ki overall value ko na ki 0th place vale 6 ko
// so what we will do is we will try to find 6 from left and the moment we get it we will
//simply replace it with 9 and simply return the ans

int maximum69Number (int num){
    string s= to_string(num);
    for(auto& ch : s){
        if(ch=='6'){  //jaise hi pehli 6 mile
            ch='9';   //usko flip kro
            break;    //turant loop s bahar niklo
        }
    }
    return stoi(s); //ans return krne s pehle usko int bna do
}

