#ifndef _SimTK_OPTIMIZER_INTERFACE_H_
#define _SimTK_OPTIMIZER_INTERFACE_H_
#include "SimTKcommon.h"
#include "SimTKcommon/internal/common.h"
#include "simmatrix/internal/BigMatrix.h"
#include "objectiveFunction.h"


namespace SimTK {

class smOptimizerInterface { 

public:
    virtual ~smOptimizerInterface() {};
   

    /* by default class chooses algorithm based on size of problem. 
       The algorithm can be overridden by setting the Algo param. */
       /* should there be a set method for each parameter ? */
    virtual smStatus setOptimizerParameters(unsigned int, double *) = 0;
    virtual smStatus getOptimizerParameters(unsigned int, double *) = 0;
/*
    virtual smStatus getOptimizerParameters(unsigned int, int *) = 0;
    virtual smStatus setOptimizerParameters(unsigned int, int *) = 0;
*/
    virtual smStatus setObjectiveFunction( SimTK::objectiveFunction *objFunc) = 0;

    virtual smStatus optimize(SimTK::Vector_<Real> &) = 0; // checks to see if space needs to be allocated

       // constructor sets internal flag to require allocation
       // if dimension or algorithm changes the reallocate flag is
       // set to trigger freeing the old mem and allocating new.


}; // end class optimizeInterface
} // namespace SimTK
#endif  //_SimTK_OPTIMIZER_INTERFACE_H_
