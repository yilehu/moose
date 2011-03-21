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

#ifndef GEOMETRICSEARCHINTERFACE_H
#define GEOMETRICSEARCHINTERFACE_H

#include "InputParameters.h"

// Forward Declarations
class GeometricSearchData;
class PenetrationLocator;
class NearestNodeLocator;


class GeometricSearchInterface
{
public:
  GeometricSearchInterface(InputParameters & params);

  /**
   * Retrieve the PentrationLocator associated with the two sides.
   */
  PenetrationLocator & getPenetrationLocator(unsigned int master, unsigned int slave);

  /**
   * Retrieve the PentrationLocator associated with the two sides.
   */
  NearestNodeLocator & getNearestNodeLocator(unsigned int master, unsigned int slave);

protected:
  GeometricSearchData & _geometric_search_data;
};

#endif //GEOMETRICSEARCHINTERFACE_H_
