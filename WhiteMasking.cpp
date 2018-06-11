#include "stdafx.h"

float WhiteMasking(float WIncidence)
{
	// P( father Ww | 3 children ww, mother ww )	=	P( father Ww, 3 children ww, mother ww ) / P ( 3 children ww, mother ww )


	//												=	P( 3 children ww, mother ww | father Ww ) * P( father Ww ) / 
	//													P( 3 children ww, mother ww | father Ww ) * P( father Ww ) + P( 3 children ww, mother ww | father ww ) * P ( father ww )


	// P( father/mother Ww ) = 2 * incidence of W * incidence of w
	// P( father/mother ww ) = incidence of w * incidence of w

	// P( 3 children ww, mother ww | father Ww ) = 1/8 * incidence of w * incidence of w
	// P( 3 children ww, mother ww | father ww ) = 1 * incidence of w * incidence of w

	float wIncidence = 1 - WIncidence;

	float Probability;

	Probability = 0.125 * wIncidence * wIncidence							// P( 3 children ww, mother ww | father Ww )

		* 2 * wIncidence * WIncidence												// P( father Ww ) - father heterozygous

		/ ( ( 0.125 * wIncidence * wIncidence									// P( 3 children ww, mother ww | father Ww )

		* 2 * wIncidence * WIncidence )												// P( father Ww ) - father heterozygous

		+ ( wIncidence * wIncidence													// P( 3 children ww, mother ww | father ww )

		* wIncidence * wIncidence ) );											// P( father ww ) - father homozygous recessive

	return Probability;
}