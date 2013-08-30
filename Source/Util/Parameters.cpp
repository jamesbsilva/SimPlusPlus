// File and Version Information:  Parameters.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>
#include "Parameters.h"

Parameters::Parameters(vector<paramAliases> defs, const char* filename){
    string fStr(filename);
    paramFile = fStr;
    debugOutput = false;
    delimParam = ":";
    initVecs();
    initParse(defs);
    parseParamFile();
    doneInitializing = true;
}

Parameters::Parameters(vector<paramAliases> defs, string filename){
    paramFile = filename;
    debugOutput = false;
    delimParam = ":";
    initVecs();
    initParse(defs);
    parseParamFile();
    doneInitializing = true;
}

Parameters::Parameters(vector<paramAliases> defs){
    debugOutput = false;
    delimParam = ":";
    initVecs();
    initParse(defs);
}


Parameters::Parameters(){
}

Parameters::~Parameters(){
}

void Parameters::initVecs(){
    boolParams = vector<bool>();
    intParams =  vector<int>() ;
    dblParams = vector<double>();
    flParams = vector<float>();
    strParams = vector<string>();
    paramKeys = vector<paramStrKey>();
    outputKeys = vector<paramStrKey>();
}

void Parameters::initParse(vector<paramAliases> defs){
    if(debugOutput)printf("Begin parse \n");
    for(int u = 0;u < defs.size();u++){
        paramAliases pAlias = defs.at(u);
        if(pAlias.typeP == intParam){
            int current = intParams.size();
            pushKey(pAlias,intParam,current);
            intParams.push_back(0);
        }else if(pAlias.typeP == doubleParam){
            int current = dblParams.size();
            pushKey(pAlias,doubleParam,current);
            dblParams.push_back(0.0);
        }else if(pAlias.typeP == floatParam){
            int current = flParams.size();
            pushKey(pAlias,floatParam,current);
            flParams.push_back(0.0);
        }else if(pAlias.typeP == boolParam){
            int current = boolParams.size();
            pushKey(pAlias,boolParam,current);
            boolParams.push_back(false);
        }else{
            int current = strParams.size();
            pushKey(pAlias,stringParam,current);
            strParams.push_back("");
        }
    }
}

// pushKey pushes all aliases and parameter name into all parameter keys so it can be searched for
void Parameters::pushKey(paramAliases pAlias,paramType pType,int current){
    paramStrKey push;
    push.index = current;
    push.pId = delimParam+pAlias.param+delimParam;
    push.typeP = pType;
    paramKeys.push_back(push);
    if(debugOutput)printf("Pushing Key: %s   in index : %d \n",push.pId.c_str(),push.index);
    if(debugOutput)printf("Keys size : %i \n",(int)paramKeys.size());
    
    for(int k = 0; k < pAlias.aliases.size();k++){
        if(!keyExist(pAlias.aliases.at(k))){
            paramStrKey push2;
            push2.index = current;
            push2.pId = delimParam+pAlias.aliases.at(k)+delimParam;
            push2.typeP = pType;
            paramKeys.push_back(push2);
            if(debugOutput)printf("Pushing Key: %s   in index : %d \n",push2.pId.c_str(),push.index);
            if(debugOutput)printf("Keys size : %i \n",(int)paramKeys.size());
        }
    }
}

int Parameters::getParameterI(string param){
    return intParams.at(searchParam(param,intParam));
}

double Parameters::getParameterD(string param){
    return dblParams.at(searchParam(param,doubleParam));
}

float Parameters::getParameterF(string param){
    return flParams.at(searchParam(param,floatParam));
}

bool Parameters::getParameterB(string param){
    return boolParams.at(searchParam(param,boolParam));
}

string Parameters::getParameter(string param){
    return strParams.at(searchParam(param,stringParam));
}

// searchParam searches for the index of the given parameter
int Parameters::searchParam(string param, paramType inType){
    int paramInd = -1; 
    param = delimParam+param+delimParam;
    for(int u = 0;u < paramKeys.size();u++){
        paramStrKey key = paramKeys.at(u);
        if(key.pId == param && key.typeP == inType){
            if(debugOutput)printf("Param found \n");
            paramInd = key.index;
            break;
        }
    }
    if(paramInd == (-1)){printf("Parameters| ERROR >> Parameter %s not found \n",param.c_str());}
    return paramInd;
}

paramStrKey Parameters::searchParamKey(string param){
    int paramInd = -1; 
    param = delimParam+param+delimParam;
    paramStrKey key;
    bool keyFound = false;
    for(int u = 0;u < paramKeys.size();u++){
        key = paramKeys.at(u);
        if(key.pId == param){
            keyFound = true;
            break;
        }
    }
    if(!keyFound){
        key.index = -1;
        printf("Parameters| ERROR >> Parameter %s not found \n",param.c_str());
    }
    return key;
}


// parseParamFile parses a parameter file and updates the parameters based on the file
void Parameters::parseParamFile(string filename){
    paramFile = filename;
    parseParamFile();
    doneInitializing = true;
}


// parseParamFile parses a parameter file and updates the parameters based on the file
void Parameters::parseParamFile(){
    ParserHelper parser;
    vector<string> inFile = getFileStringVector();
    for(int u = 0; u < paramKeys.size(); u++){
        paramStrKey key = paramKeys.at(u);
        if(parser.targetExists(inFile,key.pId)){          
            updateKeyValue(parser.targetLine(inFile,key.pId),key,parser);
        }
    }
}

// searchParseKey searches for the given key and updates the value for the parameter with a matching key 
void Parameters::updateKeyValue(string line,paramStrKey key,ParserHelper parser){
    if(key.typeP==intParam){
        int p =  parser.parseInt(line,key.pId,key.offset);
        vector<int>::iterator it = intParams.begin();
        intParams.insert(it+key.index,p);
    }else if(key.typeP==doubleParam){
        double p = parser.parseDouble(line,key.pId,key.offset);
        vector<double>::iterator it = dblParams.begin();
        it = dblParams.begin();
        dblParams.insert(it+key.index,p);     
    }else if(key.typeP==floatParam){
        float p = (float) parser.parseDouble(line,key.pId,key.offset);
        vector<float>::iterator it = flParams.begin();
        it = flParams.begin();
        flParams.insert(it+key.index,p);            
    }else if(key.typeP==boolParam){
        bool p = parser.parseBool(line,key.pId,key.offset);
        vector<bool>::iterator it = boolParams.begin();
        it = boolParams.begin();
        boolParams.insert(it+key.index,p);            
    }else{
        string p = parser.parseString(line,key.pId,key.offset);
        vector<string>::iterator it = strParams.begin();
        it = strParams.begin();
        strParams.insert(it+key.index,p);            
    }
}

// getFileStringVector returns the parameter file as a vector of strings
vector<string> Parameters::getFileStringVector(){
    vector<string> file = vector<string>();
    printf("Opening File : %s \n",paramFile.c_str());
    ifstream myfile(paramFile.c_str());
    if (myfile.is_open()){
        while (myfile.good()){
            string line;
            getline (myfile,line);
            if(debugOutput)printf("Line In : %s \n",line.c_str());
            file.push_back(line);
        }
    myfile.close();
    }
    return file;
}

bool Parameters::keyExist(string keyId){
    keyId = delimParam + keyId + keyId;
    for(int u = 0; u< paramKeys.size();u++){
        if(paramKeys.at(u).pId == keyId){
            return true;
        }
    }
    return false;
}

vector<paramStrKey> Parameters::getOutputKeysSet(){
    return outputKeys;
}

void Parameters::makeOutputKeysSet(vector<string> outKeys){
    for(int u = 0; u < outKeys.size();u++){
        paramStrKey keyOut = searchParamKey(outKeys.at(u));
        if(keyOut.index != -1){
            outputKeys.push_back(keyOut);
        }
    }
}


/*
 *  Simple test of parser helper
 */
int mainParam(int argc, char** argv) {
    printf("Creating length aliases \n");
    vector<string> tAliases = vector<string>();
    tAliases.push_back("length");
    tAliases.push_back("length");
    tAliases.push_back("Length");
    tAliases.push_back("L");
    paramAliases pL = paramAliases("Length", intParam ,tAliases); 
    printf("Creating temp aliases \n");
    tAliases = vector<string>();
    tAliases.push_back("Temp");
    tAliases.push_back("temperature");
    paramAliases pTemp = paramAliases("Temp", doubleParam ,tAliases);
    printf("Creating vector aliases \n");
    vector<paramAliases> al = vector<paramAliases>();
    al.push_back(pL);
    al.push_back(pTemp);
    printf("Creating parameters \n");
    //string fname("/home/jbsilva/JISim/Settings/parameters.txt");
    Parameters param(al,"/home/j2/JISim/Settings/parameters.txt");
    cout << "testResult2: "  << param.getParameterD("Temp") << endl;
    cout << "testResult3: "  << param.getParameterI("Length") << endl;
    cout << "testResult4: "  << param.getParameterI("L") << endl;
    
    return 0;
}

