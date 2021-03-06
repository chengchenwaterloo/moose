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

#include "AddBCAction.h"
#include "FEProblem.h"
#include "BoundaryCondition.h"

template <>
InputParameters
validParams<AddBCAction>()
{
  InputParameters params = validParams<MooseObjectAction>();
  params += validParams<BoundaryCondition>();
  return params;
}

AddBCAction::AddBCAction(InputParameters params) : MooseObjectAction(params) {}

void
AddBCAction::act()
{
  _problem->addBoundaryCondition(_type, _name, _moose_object_pars);
}
