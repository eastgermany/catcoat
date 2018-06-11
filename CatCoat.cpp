
/* Computing the probability of a male cat being heterozygous for gene W, given that the mother is homozygous recessive (ww)
and that all three children are homozygous recessive, while the prevalence of the dominant gene W is unknown. */

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

float WhiteMasking(float WIncidence);
float WhiteSpotting(float SIncidence);
float LongHair(float LIncidence);
float Browning(float BIncidence);

int main()
{
	float Start;
	float End;
	float Step;

	cout << "Start incidence: ";
	cin >> Start;
	cout << "End incidence: ";
	cin >> End;
	cout << "Step: ";
	cin >> Step;

	fstream text_file;
	text_file.open("cat_file.txt", std::fstream::in | std::fstream::out | std::fstream::trunc); // text_file.txt will normally not exist, so the program will generate it
	
	cout << "\nWHITE MASKING\n\n";
	text_file << "\nWHITE MASKING\n\n";
	for (float iii = Start; iii <= End; iii += Step)
	{
		cout << "P(W) = " << iii << "\t\t" << WhiteMasking(iii) << endl;
		text_file << "P(W) = " << iii << "\t\t" << WhiteMasking(iii) << endl;
	}

	cout << "\nWHITE SPOTTING\n\n";
	text_file << "\nWHITE SPOTTING\n\n";

	cout << "\t\t\tProbability of heterozygous cat (Ss)\n";
	text_file << "\t\t\tProbability of heterozygous cat (Ss)\n";
	for (float iii = Start; iii <= End; iii += Step)
	{
		cout << "P(S) = " << iii << "\t\t" << WhiteSpotting(iii) << endl;
		text_file << "P(S) = " << iii << "\t\t" << WhiteSpotting(iii) << endl;
	}

	cout << "\nLONG HAIR\n\n";
	text_file << "\nLONG HAIR\n\n";

	cout << "\t\t\tProbability of heterozygous cat (Ll)\n";
	text_file << "\t\t\tProbability of heterozygous cat (Ll)\n";
	for (float iii = Start; iii <= End; iii += Step)
	{
		cout << "P(L) = " << iii << "\t\t" << LongHair(iii) << endl;
		text_file << "P(L) = " << iii << "\t\t" << LongHair(iii) << endl;
	}

	cout << "\t\t\tProbability of heterozygous cat (Bb)\n";
	text_file << "\t\t\tProbability of heterozygous cat (Bb)\n";
	for (float iii = Start; iii <= End; iii += Step)
	{
		cout << "P(B) = " << iii << "\t\t" << Browning(iii) << endl;
		text_file << "P(B) = " << iii << "\t\t" << Browning(iii) << endl;
	}

	text_file.close();


}
