/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2006 Soeren Sonnenburg
 * Written (W) 1999-2006 Gunnar Raetsch
 * Copyright (C) 1999-2006 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#include "preproc/SortWordString.h"
#include "features/Features.h"
#include "features/StringFeatures.h"
#include "lib/Mathematics.h"

CSortWordString::CSortWordString() : CStringPreProc<WORD>("SortWordString", "STWS") 
{
}

CSortWordString::~CSortWordString()
{
}

/// initialize preprocessor from features
bool CSortWordString::init(CFeatures* f)
{
	ASSERT(f->get_feature_class() == C_STRING);
	ASSERT(f->get_feature_type() == F_WORD);
	return true;
}

/// clean up allocated memory
void CSortWordString::cleanup()
{
}

/// initialize preprocessor from file
bool CSortWordString::load(FILE* f)
{
	return false;
}

/// save preprocessor init-data to file
bool CSortWordString::save(FILE* f)
{
	return false;
}

/// apply preproc on feature matrix
/// result in feature matrix
/// return pointer to feature_matrix, i.e. f->get_feature_matrix();
bool CSortWordString::apply_to_feature_strings(CFeatures* f)
{
	INT i;
	INT num_vec=((CStringFeatures<WORD>*)f)->get_num_vectors() ;
	
	for (i=0; i<num_vec; i++)
	{
		INT len = 0 ;
		WORD* vec = ((CStringFeatures<WORD>*)f)->get_feature_vector(i, len) ;
		//CIO::message(M_DEBUG, "sorting string of length %i\n", len) ;
		
		CMath::qsort(vec, len);
	}
	return true ;
}

/// apply preproc on single feature vector
WORD* CSortWordString::apply_to_feature_string(WORD* f, INT& len)
{
	WORD* vec=new WORD[len];
	INT i=0;

	for (i=0; i<len; i++)
		vec[i]=f[i];

	CMath::qsort(vec, len);

	return vec;
}

/// initialize preprocessor from file
bool CSortWordString::load_init_data(FILE* src)
{
	return true;
}

/// save init-data (like transforamtion matrices etc) to file
bool CSortWordString::save_init_data(FILE* dst)
{
	return true;
}
