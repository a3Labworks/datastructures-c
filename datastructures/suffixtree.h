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

struct Node {
	std::string sub = "";   // a substring of the input string; une sous-chaîne de la chaîne d'entrée
	std::vector<int> ch;    // vector of child nodes; vecteur de nœuds enfants

	Node() {
		// empty; vide
	}

	Node(const std::string& sub, std::initializer_list<int> children) : sub(sub) {
		ch.insert(ch.end(), children);
	}
};

struct SuffixTree {
	std::vector<Node> nodes;

	SuffixTree(const std::string& str) {
		nodes.push_back(Node{});
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
		int n = 0;
		size_t i = 0;
		while (i < suf.length()) {
			char b = suf[i];
			int x2 = 0;
			int n2;
			while (true) {
				auto children = nodes[n].ch;
				if (x2 == children.size()) {
					// no matching child, remainder of suf becomes new node
					// aucun enfant correspondant, le reste de suf devient le nouveau noeud
					n2 = nodes.size();
					nodes.push_back(Node(suf.substr(i), {}));
					nodes[n].ch.push_back(n2);
					return;
				}
				n2 = children[x2];
				if (nodes[n2].sub[0] == b) {
					break;
				}
				x2++;
			}
			// find prefix of remaining suffix in common with child
			// trouver le préfixe du suffixe restant en commun avec l'enfant
			auto sub2 = nodes[n2].sub;
			size_t j = 0;
			while (j < sub2.size()) {
				if (suf[i + j] != sub2[j]) {
					// split n2
					auto n3 = n2;
					// new node for the part in common
					// nouveau noeud pour la partie en commun
					n2 = nodes.size();
					nodes.push_back(Node(sub2.substr(0, j), { n3 }));
					nodes[n3].sub = sub2.substr(j); // old node loses the part in common; ancien noeud perd la partie en commun
					nodes[n].ch[x2] = n2;
					break; // continue down the tree; continuer en bas de l'arbre
				}
				j++;
			}
			i += j; // advance past part in common; avancer la partie en commun
			n = n2; // continue down the tree; continuer en bas de l'arbre
		}
	}
};
