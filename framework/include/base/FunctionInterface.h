/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef FUNCTIONINTERFACE_H
#define FUNCTIONINTERFACE_H

#include "InputParameters.h"
#include "ParallelUniqueId.h"

class Problem;
class Function;

/**
 * Inherit from this class at a very low level to make the getFunction method
 * available.
 */
class FunctionInterface
{
public:
  /**
   * @param func_warehouse Reference to the FunctionWarehouse stored by MooseSystem
   * @param params The parameters used by the object being instantiated. This
   *        class needs them so it can get the function named in the input file,
   *        but the object calling getFunction only needs to use the name on the
   *        left hand side of the statement "function = func_name"
   * @param tid The thread id used by this object, used by the warehouse
   */
  FunctionInterface(InputParameters & params);

  Function & getFunction(const std::string & name);

private:
  Problem & _problem;
  THREAD_ID _tid;
  InputParameters _params;
};

#endif //FUNCTIONINTERFACE_H_
