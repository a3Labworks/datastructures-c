#pragma once

#include <functional>
#include <iostream>
#include <vector>

/*
Given a string S of length n, its suffix tree is a tree T such that:

	T has exactly n leaves numbered from 1 to n.
	Except for the root, every internal node has at least two children.
	Each edge of T is labelled with a non-empty substring of S.
	No two edges starting out of a node can have string labels beginning with the same character.
	The string obtained by concatenating all the string labels found on the path from the root to leaf i spells out suffix S[i..n], for i from 1 to n.

Soit une cha�ne S de longueur n, son arbre suffixe est un arbre T tel que:

	 T a exactement n feuilles num�rot�es de 1 � n.
	 � l'exception de la racine, chaque n�ud interne a au moins deux enfants.
	 Chaque bord de T est �tiquet� avec une sous-cha�ne non vide de S.
	 Aucune deux bords commen�ant d'un n�ud ne peuvent avoir d'�tiquettes de cha�ne commen�ant par le m�me caract�re.
	 La cha�ne obtenue en concat�nant toutes les �tiquettes de cha�ne trouv�es sur le chemin de la racine � la feuille i �pelle le suffixe S [i..n], pour i de 1 � n.

*/

struct MyNode {
	std::string sub = "";   // a substring of the input string; une sous-cha�ne de la cha�ne d'entr�e
	std::vector<int> ch;    // vector of child nodes; vecteur de n�uds enfants

	MyNode() {
		// empty; vide
	}

	MyNode(const std::string& sub, std::initializer_list<int> children) : sub(sub) {
		ch.insert(ch.end(), children);
	}
};

struct MySuffixTree {
	std::vector<MyNode> nodes;

	MySuffixTree(const std::string& str) {
		nodes.push_back(MyNode{});
		for (size_t i = 0; i < str.length(); i++) {
			addSuffix(str.substr(i));
		}
	}

	void visualize() {
		if (nodes.size() == 0) {
			std::cout << "<empty>\n";
			return;
		}

		std::function<void(int, const std::string&)> f;
		f = [&](int n, const std::string& pre) {
			auto children = nodes[n].ch;
			if (children.size() == 0) {
				std::cout << "- " << nodes[n].sub << '\n';
				return;
			}
			std::cout << "+ " << nodes[n].sub << '\n';

			auto it = std::begin(children);
			if (it != std::end(children)) do {
				if (std::next(it) == std::end(children)) break;
				std::cout << pre << "+-";
				f(*it, pre + "| ");
				it = std::next(it);
			} while (true);

			std::cout << pre << "+-";
			f(children[children.size() - 1], pre + "  ");
		};

		f(0, "");
	}

private:

	void addSuffix(const std::string& suf) {

		// TODO: impl�menter l'ajout d'un suffixe � l'arbre

	}
};
