#pragma once

// C++ program for building suffix array of a given text 
// Programme C ++ pour construire un tableau de suffixes d'un texte donn�
#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std;

// Structure to store information of a suffix 
// Structure pour stocker les informations d'un suffixe
struct mysuffixA
{
	int index; // To store original index; Pour stocker l'index d'origine 
	int rank[2]; // To store ranks and next rank pair; Pour stocker les rangs et la paire suivante 
};

// A comparison function used by sort() to compare two suffixes 
// Compares two pairs, returns 1 if first pair is smaller 
// Une fonction de comparaison utilis�e par sort () pour comparer deux suffixes
// Compare deux paires, retourne 1 si la premi�re paire est plus petite
int mycmpA(struct mysuffixA a, struct mysuffixA b)
{
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
		(a.rank[0] < b.rank[0] ? 1 : 0);
}

// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
// Ceci est la fonction principale qui prend une cha�ne 'txt' de taille n en tant que
// argument, construit et retourne le tableau de suffixe pour la cha�ne donn�e
int* buildMySuffixArrayA(char* txt, int n)
{
	// A structure to store suffixes and their indexes 
	// Une structure pour stocker les suffixes et leurs index
	struct mysuffixA suffixes[1024];

	// Store suffixes and their indexes in an array of structures. 
	// The structure is needed to sort the suffixes alphabatically 
	// and maintain their old indexes while sorting 
	// Stocke les suffixes et leurs index dans un tableau de structures.
	// La structure est n�cessaire pour trier les suffixes par ordre alphab�tique
	// et conserve leurs anciens index lors du tri
	
	// TODO: Stocke les suffixes et leurs index

	// Sort the suffixes using the comparison function defined above. 
	// Triez les suffixes en utilisant la fonction de comparaison d�finie ci-dessus.
	
	// TODO: triez les suffixes

	// At this point, all suffixes are sorted according to first 
	// 2 characters. Let us sort suffixes according to first 4 
	// characters, then first 8 and so on 
	// A ce stade, tous les suffixes sont tri�s par ordre de priorit�.
	// 2 caract�res. Trions les suffixes selon le premier 4
	// caract�res, puis 8 premiers et ainsi de suite
	int ind[1024]; // This array is needed to get the index in suffixes[] 
				// from original index. This mapping is needed to get next suffix. 
				// Ce tableau est n�cessaire pour obtenir l'index en suffixe[]
				// de l'index d'origine. Ce mappage est n�cessaire pour obtenir le prochain suffixe.

	for (int k = 4; k < 2 * n; k = k * 2)
	{
		// Assigning rank and index values to first suffix 
		// Attribuer de valeurs de rang et d'index au premier suffixe
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		// Assigning rank to suffixes 
		// Attribuer un rang � des suffixes
		
		// TODO: Attribuer un rang � des suffixes

		// Assign next rank to every suffix 
		// Attribuer le rang suivant � chaque suffixe

		// TODO: Attribuer le rang suivant � chaque suffixe

		// Sort the suffixes according to first k characters 
		// Trier les suffixes en fonction des k premiers caract�res
		
		// TODO: Trier les suffixes en fonction des k premiers caract�res
	}

	// Store indexes of all sorted suffixes in the suffix array 
	// Stocke les index de tous les suffixes tri�s dans le tableau de suffixes
	int* suffixArr = new int[n];

	// TODO: Stocke les index de tous les suffixes tri�s

	// Return the suffix array 
	// Renvoie le tableau de suffixes
	return suffixArr;
}

// A utility function to print an array of given size 
void printMyArrA(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// A suffix array based search function to search a given pattern 
// 'pat' in given text 'txt' using suffix array suffArr[] 
// Une fonction de recherche bas�e sur un tableau suffixe pour rechercher un mod�le donn�
// 'pat' dans le texte donn� 'txt' en utilisant le suffixe tableau suffArr []
void mySearchA(char* pat, char* txt, int* suffArr, int n)
{
	int m = strlen(pat);  // get length of pattern, needed for strncmp() 

	// Do simple binary search for the pat in txt using the 
	// built suffix array 
	int l = 0, r = n - 1;  // Initilize left and right indexes 
	while (l <= r)
	{
		// See if 'pat' is prefix of middle suffix in suffix array 
		int mid = l + (r - l) / 2;
		int res = strncmp(pat, txt + suffArr[mid], m);

		// If match found at the middle, print it and return 
		if (res == 0)
		{
			cout << "Pattern found at index " << suffArr[mid];
			return;
		}

		// Move to left half if pattern is alphabtically less than 
		// the mid suffix 
		if (res < 0) r = mid - 1;

		// Otherwise move to right half 
		else l = mid + 1;
	}

	// We reach here if return statement in loop is not executed 
	cout << "Pattern not found";
}


