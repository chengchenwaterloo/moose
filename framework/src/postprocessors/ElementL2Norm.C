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

#include "ElementL2Norm.h"

template <>
InputParameters
validParams<ElementL2Norm>()
{
  InputParameters params = validParams<ElementIntegralVariablePostprocessor>();
  return params;
}

ElementL2Norm::ElementL2Norm(const InputParameters & parameters)
  : ElementIntegralVariablePostprocessor(parameters)
{
}

Real
ElementL2Norm::getValue()
{
  return std::sqrt(ElementIntegralVariablePostprocessor::getValue());
}

Real
ElementL2Norm::computeQpIntegral()
{
  Real val = _u[_qp];
  return val * val;
}
