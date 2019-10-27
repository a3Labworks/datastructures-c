// datastructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning(disable : 4996)

#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#include "suffixtree.h"
#include "mysuffixtree.h"

#include "suffixarraynaive.h"
#include "mysuffixarraynaive.h"

#include "suffixarray.h"
#include "mysuffixarray.h"



void runSuffixTree() {
	//std::string sequence = "nonsense$";
	std::string sequence = "banana$";
	std::cout << "Suffix Tree response:" << '\n';
	SuffixTree(sequence).visualize();
	std::cout << "MySuffix Tree response:" << '\n';
	MySuffixTree(sequence).visualize();
}

void runSuffixArrayNaive() {
	char txt[] = "banana";
	int n = strlen(txt);
	char pat[] = "nan";   // pattern to be searched in text 

	int* suffixArr = buildSuffixArray(txt, n);
	cout << "Following is SuffixArray for " << txt << endl;
	printArr(suffixArr, n);
	cout << "Searching for pattern " << pat << endl;
	search(pat, txt, suffixArr, n); // search pat in txt using the built suffix array

	int* suffixArr2 = buildMySuffixArray(txt, n);
	cout << "\nFollowing is MySuffixArray for " << txt << endl;
	printMyArr(suffixArr2, n);
	cout << "Searching for pattern " << pat << endl;
	mySearch(pat, txt, suffixArr2, n); // search pat in txt using the built suffix array 
}

void runSuffixArray() {
	char txt[] = "banana";
	int n = strlen(txt);
	char pat[] = "nan";   // pattern to be searched in text 

	int* suffixArr = buildSuffixArrayA(txt, n);
	cout << "Following is SuffixArray for " << txt << endl;
	printArrA(suffixArr, n);
	cout << "Searching for pattern " << pat << endl;
	searchA(pat, txt, suffixArr, n); // search pat in txt using the built suffix array

	int* suffixArr2 = buildMySuffixArrayA(txt, n);
	cout << "\nFollowing is MySuffixArray for " << txt << endl;
	printMyArrA(suffixArr2, n);
	cout << "Searching for pattern " << pat << endl;
	mySearchA(pat, txt, suffixArr2, n); // search pat in txt using the built suffix array 
}

int main()
{
	runSuffixTree();
	//runSuffixArrayNaive();
	//runSuffixArray();

	return 0;
}