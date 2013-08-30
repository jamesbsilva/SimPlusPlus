// File and Version Information:  ParserHelper.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>
#include "ParserHelper.h"

ParserHelper::ParserHelper(){
    debugOutput = false;
}

// parseString returns the word in the line passed in which includes 
// the target word and is the offset word away from the trigger word
string ParserHelper::parseString(string input, string target, int offset){
    string parsed;string word;
    
    parsed = getTargetSubString(input,target);
    if(parsed == "NOTFOUND"){return parsed;}
    
    istringstream iss(parsed, istringstream::in);
    
    vector<string> *words = new vector<string>();
    int p = 0;
    while( iss >> word && p <= offset){
        p++;
        words->push_back(word);
    }
    word = words->at(offset);
    delete words;
    words=0;
    return word;
}

bool ParserHelper::targetExists(string input, string target){
    int pos = input.find(target);
    if(pos == std::string::npos){
        return false;
    }else{return true;}
}

bool ParserHelper::targetExists(vector<string> input, string target){
    int pos;
    for(int u = 0; u < input.size();u++){
        pos = (input.at(u)).find(target);
        if(!(pos == std::string::npos)){
            return true;
        }
    }
    return false;
}

string ParserHelper::targetLine(vector<string> input, string target){
    int pos;
    for(int u = 0; u < input.size();u++){
        pos = (input.at(u)).find(target);
        if(!(pos == std::string::npos)){
            return input.at(u);
        }
    }
    return "";
}

bool ParserHelper::targetExists(string input, string target,int offset){
    string parsed;string word;
    
    bool good = targetExists(input,target);
    if(!good){return false;}
    istringstream iss(parsed, istringstream::in);
    
    int p = 0;
    while( iss >> word && p <= offset){
        p++;
    }
    if(p <= offset){return false;}else{return true;}
}

string ParserHelper::getTargetSubString(string input, string target){
    string parsed;
    int pos = input.find(target);
    if(pos == std::string::npos){
        if(debugOutput){
            parsed = string("TARGET STRING : ");
            parsed = parsed+target+"  NOT FOUND \n";
            printf("%s",parsed.c_str());
        }
        return "NOTFOUND";
    }
    parsed = input.substr(target.length()+pos);
    return parsed;
}


// parseVecString returns the words in the line passed in which includes 
// the target word and are the all the words leading to the offset
vector<string> ParserHelper::parseVecString(string input, string target, int offset){
    string parsed;string word;
    int pos = input.find(target);
    
    parsed = input.substr(target.length()+pos);
    istringstream iss(parsed, istringstream::in);
    
    vector<string> *words = new vector<string>();
    int p = 0;
    while( iss >> word && p <= offset ){
        p++;
        words->push_back(word);
    }
    return *words;
}

// parseInt returns the integer in the line passed in which includes 
// the target word and is the offset integer away from the trigger word
int ParserHelper::parseInt(string input, string target, int offset){
    string intStr = parseString(input,target,offset);
    if(intStr == "NOTFOUND"){return -222222222;}
    return atoi(intStr.c_str());
}


// parseIntVec returns the integers in the line passed in which includes 
// the target word and are the all the integers leading to the offset
vector<int> ParserHelper::parseIntVec(string input, string target, int offset){
    vector<string> str = parseVecString(input,target,offset);     
    vector<int> *intVec = new vector<int>();
    for(int u = 0; u < offset;u++){
        intVec->push_back(atoi(str[u].c_str()));
    }
    return *intVec;
}

// parseIntArr returns the integers in the line passed in which includes 
// the target word and are the all the integers leading to the offset
int* ParserHelper::parseIntArr(string input, string target, int offset){
    vector<string> str = parseVecString(input,target,offset);     
    int* intArr = new int[offset];
    for(int u = 0; u < offset;u++){
        intArr[u] = (atoi(str[u].c_str()));
    }
    return intArr;
}

// parseDouble returns the double in the line passed in which includes 
// the target word and is the offset double away from the trigger word
double ParserHelper::parseDouble(string input, string target, int offset){
    string dblStr = parseString(input,target,offset);
    if(dblStr == "NOTFOUND"){return -2222.22222;}     
    return atof(dblStr.c_str());
}
// parseDblVec returns the doubles in the line passed in which includes 
// the target word and are the all the doubles leading to the offset
vector<double> ParserHelper::parseDblVec(string input, string target, int offset){
    vector<string> str = parseVecString(input,target,offset);     
    vector<double> *dblVec = new vector<double>();
    for(int u = 0; u < offset;u++){
        dblVec->push_back(atof(str[u].c_str()));
    }
    return *dblVec;
}
// parseDblArr returns the doubles in the line passed in which includes 
// the target word and are the all the doubles leading to the offset
double* ParserHelper::parseDblArr(string input, string target, int offset){
    vector<string> str = parseVecString(input,target,offset);     
    double* dblArr = new double[offset];
    for(int u = 0; u < offset;u++){
        dblArr[u] = atof(str[u].c_str());
    }
    return dblArr;
}

// parseBool returns the boolean in the line passed in which includes 
// the target word and is the offset boolean away from the trigger word
bool ParserHelper::parseBool(string input, string target, int offset){
    string blStr = parseString(input,target,offset);     
    return StringToBool(blStr);
}

// StringToBool converts a string into a boolean
bool ParserHelper::StringToBool(string input){
    if(input == "true" || 
            input == "TRUE"|| input == "True"|| input == "tRUE"|| input == "TRUe"
            || input == "trUE" || input == "TRue"|| input == "TrUE"|| input == "TRuE"
            || input == "1" || input == "t" || input == "T"){
        return true;
    }else{
        return false;
    }
}
// parseBoolVec returns the booleans in the line passed in which includes 
// the target word and are the all the booleans leading to the offset
vector<bool> ParserHelper::parseBoolVec(string input, string target, int offset){
    vector<string> str = parseVecString(input,target,offset);     
    vector<bool> *boolVec = new vector<bool>();
    for(int u = 0; u < offset;u++){
        boolVec->push_back(StringToBool(str[u]));
    }
    return *boolVec;
}



/*
 *  Simple test of parser helper
 */
int main2(int argc, char** argv) {
    ParserHelper *parse = new ParserHelper();
    string *inTest = new string(":Temperature: 29.4 "
            "/n :hField: 3.2 /n :useHeter: true /n :useDilution: false /n"
            ":algo: metropolis /n :Length: 256 /n"
            ":triggerParams: 3948.3 984.3 433.3 9.34");
    double dOut = parse->parseDouble(*inTest,":hField:",0);
    cout << "dOut: " << dOut << endl ;
    dOut = parse->parseDouble(*inTest,":Temperature:",0);
    cout << "dOut2: " << dOut << endl ;
    bool boolTest = parse->parseBool(*inTest,":useHeter:",0);
    cout << "bOut: " << boolTest << endl ;
    boolTest = parse->parseBool(*inTest,":useDilution:",0);
    cout << "bOut2: " << boolTest << endl ;
    string strTest = parse->parseString(*inTest,":algo:",0);
    cout << "strOut: " << strTest << endl ;
    int iOut = parse->parseInt(*inTest,":Length:",0);
    cout << "iOut: " << iOut << endl;
    vector<double> dVec = parse->parseDblVec(*inTest,":triggerParams:",4);
    cout << "dVec1: " << dVec.at(0) << endl;
    cout << "dVec2: " << dVec.at(1) << endl;
    cout << "dVec3: " << dVec.at(2) << endl;
    cout << "dVec4: " << dVec.at(3) << endl;
    
    double* dArr = parse->parseDblArr(*inTest,":triggerParams:",4);
    cout << "dArr1: " << dArr[0] << endl;
    cout << "dArr2: " << dArr[1] << endl;
    cout << "dArr3: " << dArr[2] << endl;
    cout << "dArr4: " << dArr[3] << endl;
    
    dOut = parse->parseDouble(*inTest,":Teture:",0);
    cout << "dOut4: " << dOut << endl ;
    delete parse;
    return 0;
}
