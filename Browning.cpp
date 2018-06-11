#include "stdafx.h"

float Browning(float BIncidence)
	{
		// P( father BB/Bb | 3 children BB/Bb, mother BB/Bb )


		//												=	P( 3 children BB/Bb, mother BB/Bb | father BB/Bb ) * P( father BB/Bb ) / 
		//													P( 3 children BB/Bb, mother BB/Bb | father BB/Bb ) * P( father BB/Bb ) + P( 3 children BB/Bb, mother BB/Bb | father bb ) * P ( father bb )


		// P( father/mother BB/Bb ) = incidence of B * incidence of B + 2 * incidence of B * incidence of b
		// P( father/mother bb ) = incidence of b * incidence of b

		// P( 3 children BB/Bb, mother BB/Bb | father BB/Bb ) = 16/34 * ( incidence of B * incidence of B + 2 * incidence of B * incidence of b )
		// P( 3 children BB/Bb, mother BB/Bb | father BB/Bb ) = 2/9 * ( incidence of b * incidence of b )

		float bIncidence = 1 - BIncidence;

		float Probability;

		Probability = 16.0f / 34.0f * bIncidence * BIncidence							// P( 3 children BB/Bb, mother BB/Bb | father BB/Bb )

			* BIncidence * BIncidence + 2 * BIncidence * bIncidence						// P( father Bb ) - father heterozygous

			/ ( 16.0f / 34.0f * bIncidence * BIncidence									// P( 3 children BB/Bb, mother BB/Bb | father BB/Bb )

			* BIncidence * BIncidence + 2 * BIncidence * bIncidence						// P( father Bb ) - father heterozygous

			+ 2.0f / 9.0f * bIncidence * bIncidence 									// P( 3 children BB/Bb, mother BB/Bb | father bb )

			* bIncidence * bIncidence );												// P( father bb ) - father homozygous recessive

		return Probability;
	}