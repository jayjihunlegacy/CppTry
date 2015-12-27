#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "timer.h"
#include "RandGen.h"

#define min(X,Y) ((X) < (Y) ?  (X) : (Y))
#define max(X,Y) ((X) > (Y) ?  (X) : (Y))


int cut_rod_recur(int* costs, int n, int cleng);
int cut_rod_mem_sub(int*costs, int n, int cleng, int *best);
int cut_rod_mem(int* costs, int n, int cleng);
int cut_rod_bottom(int* costs, int n, int cleng);
void cut_rod_test(int n, int key);

//===================================================================================

//s and e are both indices of Matrix.

int matrix_chain_dynamic(int* arr, int n);
int matcha_rec(int* arr, int s, int e);
int matrix_chain_recursive(int* arr, int n);
void matrix_chain_test(int n);

//==============================================================
/*
	Longest Common Subsequence Problem!!
*/

int LCS_recur(int* arr1, int len1, int*arr2, int len2, int**answersheet);
int LCS_Recurive(int* arr1, int len1, int*arr2, int len2);
void LCS_Test();

//==============================================================
/*
	Optimal Binary search tree building
*/

