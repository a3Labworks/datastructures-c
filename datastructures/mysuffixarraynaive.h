#pragma once

// A simple method to construct suffix array is to make an array of all suffixes and then sort the array. 
// Une méthode simple pour construire un tableau de suffixes consiste à créer un tableau de tous les suffixes, puis à trier le tableau.
#include <iostream> 
#include <cstring> 
#include <algorithm> 
using namespace std;

// Structure to store information of a suffix
// Structure pour stocker les informations d'un suffixe
struct mysuffix
{
	int index;
	char* suff;
};

// A comparison function used by sort() to compare two suffixes
// Une fonction de comparaison utilisée par sort () pour comparer deux suffixes
int mycmp(struct mysuffix a, struct mysuffix b)
{
	return strcmp(a.suff, b.suff) < 0 ? 1 : 0;
}

// This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string
// Ceci est la fonction principale qui prend une chaîne 'txt' de taille n en tant que
// argument, construit et retourne le tableau de suffixe pour la chaîne donnée
int* buildMySuffixArray(char* txt, int n)
{
	// A structure to store suffixes and their indexes
	// Une structure pour stocker les suffixes et leurs index
	struct mysuffix suffixes[1024];

	// Store suffixes and their indexes in an array of structures. 
	// The structure is needed to sort the suffixes alphabatically 
	// and maintain their old indexes while sorting
	// Stocke les suffixes et leurs index dans un tableau de structures.
	// La structure est nécessaire pour trier les suffixes par ordre alphabétique
	// et conserve leurs anciens index lors du tri

	// TODO: Stocke les suffixes

	// Sort the suffixes using the comparison function defined above. 
	// Triez les suffixes en utilisant la fonction de comparaison définie ci-dessus.
	
	// TODO: Triez les suffixes

	// Store indexes of all sorted suffixes in the suffix array
	// Stocke les index de tous les suffixes triés dans le tableau de suffixes
	int* suffixArr = new int[n];

	// TODO: Stocke les index de tous les suffixes triés

	// Return the suffix array 
	// Renvoie le tableau de suffixes
	return suffixArr;
}

// A utility function to print an array of given size
// Une fonction utilitaire pour imprimer un tableau de taille donnée
void printMyArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// A suffix array based search function to search a given pattern 
// 'pat' in given text 'txt' using suffix array suffArr[] 
//
// Une fonction de recherche basée sur un tableau suffixe pour rechercher un modèle donné
// 'pat' dans le texte donné 'txt' en utilisant le suffixe tableau suffArr[]
void mySearch(char* pat, char* txt, int* suffArr, int n)
{
	int m = strlen(pat);  // get length of pattern, needed for strncmp(); obtenir la longueur du motif, nécessaire pour strncmp () 

	// Do simple binary search for the pat in txt using the util suffix array
	// Effectue une recherche binaire simple pour pat dans le texte en utilisant le tableau de suffixe util
	int l = 0, r = n - 1;  // Initilize left and right indexes 
	while (l <= r)
	{
		// See if 'pat' is prefix of middle suffix in suffix array 
		// Voir si 'pat' est le préfixe du suffixe du milieu dans le tableau de suffixes
		int mid = l + (r - l) / 2;
		int res = strncmp(pat, txt + suffArr[mid], m);

		// If match found at the middle, print it and return 
		// Si une correspondance est trouvée au milieu, imprimez-la et renvoyez-la
		if (res == 0)
		{
			cout << "Pattern found at index " << suffArr[mid];
			return;
		}

		// Move to left half if pattern is alphabtically less than the mid suffix 
		// Déplace la moitié gauche si le motif est alphabétiquement inférieur au suffixe moyen
		if (res < 0) r = mid - 1;

		// Otherwise move to right half 
		// sinon passe à la moitié droite
		else l = mid + 1;
	}

	// We reach here if return statement in loop is not executed 
	// Nous atteignons ici si l'instruction return en boucle n'est pas exécutée
	cout << "Pattern not found";
}

