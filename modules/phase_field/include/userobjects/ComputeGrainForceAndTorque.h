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


#ifndef COMPUTEGRAINFORCEANDTORQUE_H
#define COMPUTEGRAINFORCEANDTORQUE_H

#include "GrainForceAndTorqueInterface.h"
#include "ElementUserObject.h"
#include "ComputeGrainCenterUserObject.h"

//Forward Declarations
class ComputeGrainForceAndTorque;

template<>
InputParameters validParams<ComputeGrainForceAndTorque>();

/* This class is here to get the force and torque acting on a grain*/

class ComputeGrainForceAndTorque :
    public GrainForceAndTorqueInterface,
    public ElementUserObject
{
public:
  ComputeGrainForceAndTorque(const InputParameters & parameters);

  virtual void initialize();
  virtual void execute();
  virtual void finalize();
  virtual void threadJoin(const UserObject & y);

  virtual const std::vector<RealGradient> & getForceValues() const;
  virtual const std::vector<RealGradient> & getTorqueValues() const;
  virtual const std::vector<RealGradient> & getForceDerivatives() const;
  virtual const std::vector<RealGradient> & getTorqueDerivatives() const;

protected:
  unsigned int _qp;
  std::string _dF_name;
  /// material property that provides force density
  const MaterialProperty<std::vector<RealGradient> > & _dF;
  /// material property that provides derivative of force density with respect to c
  const MaterialProperty<std::vector<RealGradient> > & _dFdc;
  /// provide UserObject for calculating grain volumes and centers
  const ComputeGrainCenterUserObject & _grain_data;
  const std::vector<Real> & _grain_volumes;
  const std::vector<Point> & _grain_centers;
  unsigned int _ncrys;
  unsigned int _ncomp;
  std::vector<RealGradient> _force_values;
  std::vector<RealGradient> _torque_values;
  std::vector<RealGradient> _force_derivatives;
  std::vector<RealGradient> _torque_derivatives;
  /// vector storing grain force and torque values
  std::vector<Real> _force_torque_store;
  std::vector<Real> _force_torque_derivative_store;
};

#endif //COMPUTEGRAINFORCEANDTORQUE_H
