#include "stdafx.h"

float WhiteSpotting(float SIncidence)
{
	// P( father Ss | 3 children Ss, mother ss )	=	P( father Ss, 3 children Ss, mother ss ) / P ( 3 children Ss, mother ss )


	//												=	P( 3 children Ss, mother ss | father Ss ) * P( father Ss ) / 
	//													P( 3 children Ss, mother ss | father Ss ) * P( father Ss ) + P( 3 children Ss, mother ss | father SS ) * P ( father SS )


	// P( father/mother Ss ) = 2 * incidence of S * incidence of s
	// P( father/mother SS ) = incidence of S * incidence of S

	// P( 3 children Ss, mother ss | father Ss ) = 1/8 * incidence of S * incidence of s
	// P( 3 children Ss, mother ss | father SS ) = incidence of s * incidence of s

	float sIncidence = 1 - SIncidence;

	float Probability;

	Probability = 0.125 * sIncidence * SIncidence							// P( 3 children Ss, mother ss | father Ss )

		* 2 * sIncidence * SIncidence												// P( father Ss ) - father heterozygous

		/ ((0.125 * sIncidence * SIncidence									// P( 3 children Ss, mother ss | father Ss )

		* 2 * sIncidence * SIncidence)												// P( father Ss ) - father heterozygous

		+ (SIncidence * SIncidence													// P( 3 children Ss, mother ss | father SS )

		* SIncidence * SIncidence));											// P( father SS ) - father homozygous dominant

	return Probability;
}