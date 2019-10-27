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

Soit une chaîne S de longueur n, son arbre suffixe est un arbre T tel que:

	 T a exactement n feuilles numérotées de 1 à n.
	 À l'exception de la racine, chaque nœud interne a au moins deux enfants.
	 Chaque bord de T est étiqueté avec une sous-chaîne non vide de S.
	 Aucune deux bords commençant d'un nœud ne peuvent avoir d'étiquettes de chaîne commençant par le même caractère.
	 La chaîne obtenue en concaténant toutes les étiquettes de chaîne trouvées sur le chemin de la racine à la feuille i épelle le suffixe S [i..n], pour i de 1 à n.

*/

struct MyNode {
	std::string sub = "";   // a substring of the input string; une sous-chaîne de la chaîne d'entrée
	std::vector<int> ch;    // vector of child nodes; vecteur de nœuds enfants

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

		// TODO: implémenter l'ajout d'un suffixe à l'arbre

	}
};
