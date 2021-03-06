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

#include "VectorNeumannBC.h"

template <>
InputParameters
validParams<VectorNeumannBC>()
{
  InputParameters params = validParams<IntegratedBC>();
  params.addParam<RealVectorValue>(
      "vector_value", RealVectorValue(), "vector this BC should act in");
  params.addClassDescription("Imposes the integrated boundary condition "
                             "$\\frac{\\partial u}{\\partial n}=\\vec{V}\\cdot\\hat{n}$, "
                             "where $\\vec{V}$ is a user-defined, constant vector.");
  return params;
}

VectorNeumannBC::VectorNeumannBC(const InputParameters & parameters)
  : IntegratedBC(parameters), _value(getParam<RealVectorValue>("vector_value"))
{
}

Real
VectorNeumannBC::computeQpResidual()
{
  return -_test[_i][_qp] * (_value * _normals[_qp]);
}
