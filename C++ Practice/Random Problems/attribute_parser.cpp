#include <iostream>
#include <map>

using namespace std;

map <string, string> tagmap;

void createmap(int &n, string pretag){
    string line,tag,attr,value;
    getline(cin,line);
    int i = 1;
    if (line[1] == '/'){
        while (line[i]!= '>')
            i++;
        if (pretag.size()>(i-2))
            tag = pretag.sbstr(0,pretag.size()-i+1);
        else
            tag = "";
    }
    else{
        while(line[i]!=' ' && line[i]!='>')
            i++;
        tag = line.substr(1,i-1);
        if (pretag!="")
            tag = pretag + "." + tag;
        int j;
        while (line[i]!= '>'){
            j = ++i;
            while(line[i]!=' ')
                i++;
            attr = line.substr(j,i-j);
        while(line[i]!='\"') i++;
            j = ++i;
        while(line[i]!='\"') i++;
            value = line.substr(j,i-j);
            i+= 1;
        tagMap[tag + "~" + attr] = value;
        }
    }
    createMap(--n,tag);
}

int main(){
    int n,q;
    cin >> n >> q;
    cin.ignore();
    createMap(n,"");
    string attr,value;
    while(q--){
        getline(cin,attr);
        value = tagmap[attr];
        if (value == "") value = "Not Found!";
        cout << value << endl;
    }
    return 0;
}
