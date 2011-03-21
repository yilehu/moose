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

#ifndef GEOMETRICSEARCHDATA_H
#define GEOMETRICSEARCHDATA_H

//libmesh includes
#include "MooseMesh.h"

#include <map>

//Forward Declarations
class MooseMesh;
class SubProblem;
class PenetrationLocator;
class NearestNodeLocator;

class GeometricSearchData
{
public:
  GeometricSearchData(SubProblem & subproblem, MooseMesh & mesh);

  PenetrationLocator & getPenetrationLocator(unsigned int master, unsigned int slave);

  NearestNodeLocator & getNearestNodeLocator(unsigned int master, unsigned int slave);

  /**
   * Update all of the search objects.
   *
   * This is probably getting called because the mesh changed in some way.
   */
  void update();

protected:
  SubProblem & _subproblem;
  MooseMesh & _mesh;
  std::map<std::pair<unsigned int, unsigned int>, PenetrationLocator *> _penetration_locators;
  std::map<std::pair<unsigned int, unsigned int>, NearestNodeLocator *> _nearest_node_locators;
};

#endif //GEOMETRICSEARCHDATA_H
