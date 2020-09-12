#include<map>
#include<iostream>
#include<string>
#include<iterator>
using namespace std; // Add any helper functions(if needed) above. bool
bool are_all_characters_unique(string str) {
    // Add your code below this line. Do not modify any other code.
   	cout<<"helloooo\n";
	map<char, int> characters;
    map<char, int>::iterator it = characters.begin();
    for(int i = 0; i < str.length(); i++)
    {
        characters.insert(pair<char, int>(str[i],++(characters.find(str[i])->second)));
    }
	cout<<"ooopppsss\n";
    for(it; it != characters.end(); it++)
    {
        cout<<"KEY: "<<it->first<<" ELEMENT: "<<it->second<<endl;
        if(it->second >= 2)
        return false;
    }
    return true;
    // Add your code above this line. Do not modify any other code.
}
int main() {
    cout<<"hey\n";
    cout<<are_all_characters_unique("Not unique");
    cout<<"hola\n";
    return 0;
}
