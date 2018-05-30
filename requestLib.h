/*
 * =========================================================================================
 * Name        : requestLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - Bach Khoa University
 * Description : Library for Assignment 2 - Data structures and Algorithms - Spring 2018
 *               This library contains functions used for event management
 * =========================================================================================
 */

#ifndef A02_REQUESTLIB_H
#define A02_REQUESTLIB_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>

#include "dsaLib.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#define REQUEST_CODE_SIZE     64
#define MAX_PARAM_SIZE         6
using namespace std;

struct VRequest {
    char        code[REQUEST_CODE_SIZE];
    double      params[MAX_PARAM_SIZE];

    VRequest() {
        *code   = '0';// default event is "0"
        code[1] = 0;
    }
    VRequest(char* str) {
        strncpy(code, str, REQUEST_CODE_SIZE - 1);
    }
    VRequest(string& str) {
        strncpy(code, str.data(), REQUEST_CODE_SIZE - 1);
    }
    VRequest(VRequest& a) { // copy constructor
        memcpy(code, a.code, REQUEST_CODE_SIZE);
        memcpy(params, a.params, MAX_PARAM_SIZE * sizeof(double));
    }

    VRequest(VRequest&& a) { // move constructor
        int i = 0;
        while(a.code[i]) {
            code[i] = a.code[i];
            i++;
        }
        code[i] = 0;
    }

    bool operator==(VRequest &b) {
        return strcmp(code, b.code) == 0;
    }
};

void loadRequests(char* fName, L1List<VRequest> &rList);

#endif //A02_REQUESTLIB_H
