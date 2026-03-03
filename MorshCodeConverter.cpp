
#include<bits/stdc++.h>
using namespace std;





string string_to_morseCode(map<string,string> str_moss, string str){
    int ln = str.size();
    string convertedString = "";
    for(int i = 0; i < ln; i++){
        if(str[i] == ' '){
            convertedString += '/';
            convertedString += ' ';
        }
        else{
            string key = "";
            key+=str[i];
            convertedString += str_moss[key];
            convertedString += ' ';
        }
    }
    convertedString += '\0';
    return convertedString;
}

string mosscode_to_strin(map<string,string> moss_str, string str){
    
}

int main(){

    map<string,string> str_moss;
    str_moss["A"] = ".-";
    str_moss["B"] = "-...";
    str_moss["c"] = "-.-.";
    str_moss["D"] = "-..";
    str_moss["E"] = ".";
    str_moss["F"] = "..-.";
    str_moss["G"] = "--.";
    str_moss["H"] = "....";
    str_moss["I"] = "..";
    str_moss["J"] = ".---";
    str_moss["K"] = "-.-";
    str_moss["L"] = ".-..";
    str_moss["M"] = "--";
    str_moss["N"] = "-.";
    str_moss["O"] = "---";
    str_moss["P"] = ".--.";
    str_moss["Q"] = "--.-";
    str_moss["R"] = ".-.";
    str_moss["S"] = "...";
    str_moss["T"] = "-";
    str_moss["U"] = "..-";
    str_moss["V"] = "...-";
    str_moss["W"] = ".--";
    str_moss["X"] = "-..-";
    str_moss["Y"] = "-.--";
    str_moss["Z"] = "--..";

    map<string,string> moss_str;
    string key, value;
    for(auto& it : str_moss){
        string key,value;
        key = it.first;
        value = it.second;
        moss_str[value] = key;
    }
    
    //morsh code converter
    string str;
    getline(cin,str);
    transform(str.begin(),str.end(),str.begin(),::toupper);
    cout<<string_to_morseCode(str_moss,str)<<endl;
}