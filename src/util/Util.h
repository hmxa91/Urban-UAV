//
// This file is released under the terms of the NASA Open Source Agreement (NOSA)
// version 1.3 as detailed in the LICENSE file which accompanies this software.
//

#if !defined(UTIL_UTIL__INCLUDED_)
#define UTIL_UTIL__INCLUDED_

#include <vector>
#include "Vec3d.h"
using namespace std;

#ifndef MAX
#define MAX(x,y) (((x) < (y)) ? (y):(x))
#endif
#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x):(y))
#endif
#define SIGN(x,y) (((x)*(y) > 0.0) ? (x):(-x))
#define DEG2RAD(x) ( x*0.017453293 )
#define RAD2DEG(x) ( x*57.29578 )

//#define FRACT(v,min,max) ( ((max-min) == 0.0 ) ? (0.0):((v-min)/(max-min)))

#include <float.h>  /* for DBL_EPSILON */
#define FRACT(v,min,max) ( (fabs(max-min) <= DBL_EPSILON ) ? (0.0):((v-min)/(max-min)))

template <class T> bool ContainsVal( vector< T > & vec, T const & val )
{
    for ( int i = 0 ; i < ( int )vec.size() ; i++ )
    {
        if ( val == vec[i] )
        {
            return true;
        }
    }
    return false;
}

extern string GenerateRandomID( int length );

extern bool ToBool( double val );

double mag( double x );

#endif

