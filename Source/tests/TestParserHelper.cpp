/* 
 * File:   TestParserHelper.cpp
 * Author: James B. Silva <jbsilva@bu.edu>
 *
 * Created on Nov 21, 2012, 2:28:47 AM
 */

#include <stdlib.h>
#include <iostream>
#include "../Util/ParserHelper.h"

/*
 * Simple C++ Test Suite
 */

void testParseArrString() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    vector<string> result = parserHelper.parseArrString(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseArrString (newsimpletest) message=error message sample" << std::endl;
    }
}

void testParseBool() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    bool result = parserHelper.parseBool(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseBool (newsimpletest) message=error message sample" << std::endl;
    }
}

void testParseDblArr() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    vector<double> result = parserHelper.parseDblArr(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseDblArr (newsimpletest) message=error message sample" << std::endl;
    }
}

void testParseDouble() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    double result = parserHelper.parseDouble(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseDouble (newsimpletest) message=error message sample" << std::endl;
    }
}

void testParseInt() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    int result = parserHelper.parseInt(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseInt (newsimpletest) message=error message sample" << std::endl;
    }
}

void testParseIntArr() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    vector<int> result = parserHelper.parseIntArr(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseIntArr (newsimpletest) message=error message sample" << std::endl;
    }
}

void testParseString() {
    string p0;
    string p1;
    int p2;
    ParserHelper parserHelper;
    string result = parserHelper.parseString(p0, p1, p2);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testParseString (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testParseArrString (newsimpletest)" << std::endl;
    testParseArrString();
    std::cout << "%TEST_FINISHED% time=0 testParseArrString (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testParseBool (newsimpletest)" << std::endl;
    testParseBool();
    std::cout << "%TEST_FINISHED% time=0 testParseBool (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testParseDblArr (newsimpletest)" << std::endl;
    testParseDblArr();
    std::cout << "%TEST_FINISHED% time=0 testParseDblArr (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testParseDouble (newsimpletest)" << std::endl;
    testParseDouble();
    std::cout << "%TEST_FINISHED% time=0 testParseDouble (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testParseInt (newsimpletest)" << std::endl;
    testParseInt();
    std::cout << "%TEST_FINISHED% time=0 testParseInt (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testParseIntArr (newsimpletest)" << std::endl;
    testParseIntArr();
    std::cout << "%TEST_FINISHED% time=0 testParseIntArr (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testParseString (newsimpletest)" << std::endl;
    testParseString();
    std::cout << "%TEST_FINISHED% time=0 testParseString (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

