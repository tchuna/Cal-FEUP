#include "ReadFiles.h"
#include <algorithm>
#define CONECTPOINTS_FILE  "../files/maps/Ermesinde/edges.txt"
#define MAPOINTS_FILE  "../files/maps/Ermesinde/nodes.txt"
#define TAG_FILE  "../files/maps/Ermesinde/tags_ermesinde.txt"
#define HEALTHSTATION_FILE  "../files/HealthStation/healthStation.txt"
#define VEHICLES_FILE  "../files/Vehicles/vehicles.txt"
#define NURSINGHOME_FILE  "../files/NursingHome/nursingHome.txt"


vector<vector<unsigned long long>>  ReadFiles::loadTags() {
    vector<vector<unsigned long long>> result;
    vector<unsigned long long> heathCenter;
    vector<unsigned long long> nursingHome;
    vector<unsigned long long> urgency;


    string name = TAG_FILE;

    string str;
    ifstream file(name);

    getline(file, str);
    stringstream linestream(str);
    string st;
    getline(linestream, st, '\n');
    //cout<<st<<endl;
    int typesOnfile = strtod(st.c_str(), NULL);

    if (!file.is_open()) {
        cout << "fail to open tags file" << endl;
    }
    string urg ("healthcare=urgency");
    for (int i = 0; i < typesOnfile; i++) {

        getline(file, str);
        stringstream linestream(str);
        string st;
        getline(linestream, st, '\n');


        if (st.compare("healthcare=urgency") ==1) {

            getline(file, str);
            stringstream linestream(str);
            getline(linestream, st, '\n');
            int numtype = strtod(st.c_str(), NULL);



            for (int j = 0; j < numtype; j++) {

                getline(file, str);
                stringstream linestream(str);
                getline(linestream, st, '\n');
                unsigned long long id = abs(atoll(st.c_str()));
                urgency.push_back(id);

            }
            result.push_back(urgency);
        }

        if (st.compare("healthcare=center")==1) {
            getline(file, str);
            stringstream linestream(str);
            getline(linestream, st, '\n');
            int numtype = strtod(st.c_str(), NULL);

            for (int j = 0; j < numtype; j++) {

                getline(file, str);
                stringstream linestream(str);
                getline(linestream, st, '\n');
                unsigned long long id = abs(atoll(st.c_str()));
                heathCenter.push_back(id);

            }
            result.push_back(heathCenter);
        }

        if (st.compare("health_facility=nursinghome") ==1 ) {
            getline(file, str);
            stringstream linestream(str);
            getline(linestream, st, '\n');
            int numtype = strtod(st.c_str(), NULL);

            for (int j = 0; j < numtype; j++) {

                getline(file, str);
                stringstream linestream(str);
                getline(linestream, st, '\n');
                unsigned long long id = abs(atoll(st.c_str()));
                nursingHome.push_back(id);

            }
            result.push_back(nursingHome);
        }
    }
    return result;
}


vector<HealthStation*> ReadFiles::loadHealthStation(){
    vector<HealthStation*> result;

    string name= HEALTHSTATION_FILE;

    string str;
    ifstream file(name);

    getline(file,str);
    stringstream linestream(str);
    string st;
    getline(linestream,st,'\n');
    int fileSize =strtod(st.c_str(), NULL);

    if(!file.is_open()){
        cout<<"fail to open healthStation file"<<endl;
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

        getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), ')'), st.end());
        int ty = atoi(st.c_str());


        HealthStation* hstation = new HealthStation (*trt,ty);



        if (find(result.begin(), result.end(), hstation) == result.end()) {//not in the vector, so it will be added
            result.push_back(hstation);
        }
    }

    return result;
}

vector<NursingHome*> ReadFiles::loadNursingHome(){
    vector<NursingHome*> result;

    string name= NURSINGHOME_FILE;

    string str;
    ifstream file(name);

    getline(file,str);
    stringstream linestream(str);
    string st;
    getline(linestream,st,'\n');
    int fileSize =strtod(st.c_str(), NULL);

    if(!file.is_open()){
        cout<<"fail to open nursingHomes file"<<endl;
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

        getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), ')'), st.end());
        int er = atoi(st.c_str());


        NursingHome* nursingHome = new NursingHome(*trt,er);



        if (find(result.begin(), result.end(), nursingHome) == result.end()) {//not in the vector, so it will be added
            result.push_back(nursingHome);
        }
    }

    return result;
}



vector<Vehicle*> ReadFiles::loadVehicles() {
    vector<Vehicle*> result;
    MapPoint point;

    string name= VEHICLES_FILE;

    string str;
    ifstream file(name);

    getline(file,str);
    stringstream linestream(str);
    string st;
    getline(linestream,st,'\n');
    int fileSize =strtod(st.c_str(), NULL);

    if(!file.is_open()){
        cout<<"fail to open vehicle file"<<endl;
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

        getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), ')'), st.end());
        int cap = atoi(st.c_str());

        getline(linestream,st,',');
        st.erase(remove(st.begin(), st.end(), ')'), st.end());
        int type = atoi(st.c_str());

        Vehicle* vehicle = new Vehicle(cap,type,*trt);



        if (find(result.begin(), result.end(), vehicle) == result.end()) {//not in the vector, so it will be added
            result.push_back(vehicle);
        }
    }

    return result;
}


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


        if (find(result.begin(), result.end(), trt) == result.end()) {//not in the vector, so it will be added
            result.push_back(trt);
        }
    }

	return result;
}


vector<ConnectPoints*> ReadFiles::loadConnects(){
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

        if (find(result.begin(), result.end(), trt) == result.end()) {//not in the vector, so it will be added
            result.push_back(trt);
        }
    }

	return result;
}












