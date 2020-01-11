/*
* 클래스 이름: BankingCommonDecl.h
* Author : Donghun Park
* Version : 18.8.14, v0.7
*/
#ifndef BANKING_COMMON_DECL_H
#define BANKING_COMMON_DECL_H
#include <iostream>
#include <string>
using namespace std;

const int NAME_LEN = 20;

//프로그램 사용자의 선택 메뉴
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

//계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };

#endif