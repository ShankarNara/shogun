#ifndef _CSHORTPREPROC__H__
#define _CSHORTPREPROC__H__

#include "features/Features.h"
#include "lib/common.h"

#include <stdio.h>

class CFeatures;

class CShortPreProc
{
public:
	CShortPreProc();
	virtual ~CShortPreProc();

	/// initialize preprocessor from features
	virtual bool init(CFeatures* f);
	/// cleanup
	virtual void cleanup();
	/// initialize preprocessor from file
	virtual bool load(FILE* f);
	/// save preprocessor init-data to file
	virtual bool save(FILE* f);

	/// apply preproc on feature matrix
	/// result in feature matrix
	/// return pointer to feature_matrix, i.e. f->get_feature_matrix();
	virtual short int * apply_to_feature_matrix(CFeatures* f)=0;
	/// apply preproc on single feature vector
	/// result in feature matrix
	virtual short int* apply_to_feature_vector(short int* f, int len)=0;
	
	/** return feature type with which objects derived 
	*         from CPreProc can deal
	*             */
	virtual CFeatures::EType get_feature_type() { return CFeatures::F_SHORT; }
};
#endif
