#include "stdafx.h"

float LongHair(float LIncidence)
{
	// P( father Ll | 1 child ll, 2 children Ll/LL, mother Ll )


	//												=	P( 1 child ll, 2 children Ll/LL, mother Ll | father Ll ) * P( father Ll ) / 
	//													P( 1 child ll, 2 children Ll/LL, mother Ll | father Ll ) * P( father Ll ) + P( 1 child ll, 2 children Ll/LL, mother Ll | father ll ) * P ( father ll )


	// P( father/mother Ll ) = 2 * incidence of L * incidence of l
	// P( father/mother ll ) = incidence of l * incidence of l

	// P( 1 child ll, 2 children Ll/LL, mother Ll | father Ll ) = 12/28 * incidence of L * incidence of l
	// P( 1 child ll, 2 children Ll/LL, mother Ll | father ll ) = 3/8 * incidence of l * incidence of l

	float lIncidence = 1 - LIncidence;

	float Probability;

	Probability = ( 12.0f / 28.0f * lIncidence * lIncidence							// P( 1 child ll, 2 children Ll/LL, mother Ll | father Ll )

		* 2 * lIncidence * LIncidence )												// P( father Ll ) - father heterozygous

		/ ( 12.0f / 28.0f * lIncidence * lIncidence									// P( 1 child ll, 2 children Ll/LL, mother Ll | father Ll )

		* 2 * lIncidence * LIncidence												// P( father Ll ) - father heterozygous

		+ 3.0f / 8.0f * lIncidence * lIncidence										// P( 1 child ll, 2 children Ll/LL, mother Ll | father ll )

		* lIncidence * lIncidence );												// P( father ll ) - father homozygous recessive

	return Probability;
}