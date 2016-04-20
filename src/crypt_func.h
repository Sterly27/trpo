#pragma once
#ifndef CRYPT_FUNC_H
#define CRYPT_FUNC_H

int crpt(char* string,int key);
void vig(char a[],char b[]);
void devig(char a[],char b[]);
void morze(char* str, char* total);
void demorze(char* str);

#include "func_crpt_vigi.cpp"
#include "func_morze.cpp"
#include "crypt_func.cpp"

#endif
