#include "ReadFiles.h"
#include <algorithm>

#define MAPOINTS_FILE  "../files/4x4/nodes.txt"
#define CONECTPOINTS_FILE  "../files/4x4/edges.txt"

vector<MapPoint*> ReadFiles::loadMapPoints() {
	vector<MapPoint*> result;

	string name= MAPOINTS_FILE;

	string str;
	ifstream file(name);

    getline(file,str);
    stringstream linestream(str);
    string st;
    getline(linestream,st,'\n');
    int fileSize =strtod(st.c_str(), NULL);

    if(!file.is_open()){
        cout<<"fail to open nodes file"<<endl;
    }

    for(int i=0;i<fileSize;i++){

        getline(file,str);
        stringstream linestream(str);
        string st;

        getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), '('), st.end());
        unsigned long long  id = abs(atoll(st.c_str()));

        getline(linestream,st,',');
        double x =strtod(st.c_str(), NULL);

        getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), ')'), st.end());
        double y = strtod(st.c_str(), NULL);

        MapPoint* trt = new MapPoint(id,x,y);
        result.push_back(trt);
    }

	return result;
}


vector<ConnectPoints*> ReadFiles::loadConects(){
	vector<ConnectPoints*> result;

	string name= CONECTPOINTS_FILE;
	string str;
	ifstream file(name.c_str());

    getline(file,str);
    stringstream linestream(str);
    string st;
    getline(linestream,st,'\n');
    int fileSize =strtod(st.c_str(), NULL);

    if(!file.is_open()){
        cout<<"fail to open edges file"<<endl;
    }

    for(int i=0;i<fileSize;i++){
        getline(file,str);
        stringstream linestream(str);
        string st;

		getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), '('), st.end());
		unsigned long  fr = atoll(st.c_str());

		getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), ')'), st.end());
		unsigned long  sec = atoll(st.c_str());

		ConnectPoints* trt=new ConnectPoints(i,fr,sec);

		result.push_back(trt);
    }

	return result;
}












