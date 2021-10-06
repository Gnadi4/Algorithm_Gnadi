#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

void func(){

    return;
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;

    map<string, int> ma;
    string arr[100001];

    for(int i=1; i<=n; i++){
        string s;
        cin>>s;

        pair<string, int> pa;

        pa=make_pair(s,i);
        ma.insert(pa);
        arr[i]=s;
    }

    map<int, string>::iterator iter;

    for(int i=0; i<m; i++){
        string s;
        cin>>s;

        if(isdigit(s[0])){
            cout<<arr[stoi(s)]<<'\n';
        }else{
            cout<<ma.find(s)->second<<'\n';
        }
    }

    return 0;
}


/*
26 1
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna
*/