#include "StochasticToolsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

#include "StateSimTester.h"
#include "StateSimRunner.h"

// Distributions
#include "UniformDistribution.h"
#include "WeibullDistribution.h"
#include "NormalDistribution.h"
#include "LognormalDistribution.h"

// Samplers
#include "MonteCarloSampler.h"
#include "SobolSampler.h"

// VectorPostprocessors
#include "SamplerData.h"
#include "StochasticResults.h"

// MultiApps
#include "SamplerMultiApp.h"

// Transfers
#include "SamplerTransfer.h"
#include "SamplerPostprocessorTransfer.h"

// Controls
#include "SamplerReceiver.h"

template <>
InputParameters
validParams<StochasticToolsApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

StochasticToolsApp::StochasticToolsApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  StochasticToolsApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  StochasticToolsApp::associateSyntax(_syntax, _action_factory);
}

StochasticToolsApp::~StochasticToolsApp() {}

// External entry point for dynamic application loading
extern "C" void
StochasticToolsApp__registerApps()
{
  StochasticToolsApp::registerApps();
}
void
StochasticToolsApp::registerApps()
{
  registerApp(StochasticToolsApp);
}

// External entry point for dynamic object registration
extern "C" void
StochasticToolsApp__registerObjects(Factory & factory)
{
  StochasticToolsApp::registerObjects(factory);
}
void
StochasticToolsApp::registerObjects(Factory & factory)
{
  registerUserObject(StateSimRunner);
  registerPostprocessor(StateSimTester);

  // Distributions
  registerDistribution(UniformDistribution);
  registerDistribution(WeibullDistribution);
  registerDistribution(NormalDistribution);
  registerDistribution(LognormalDistribution);

  // Samplers
  registerSampler(MonteCarloSampler);
  registerSampler(SobolSampler);

  // VectorPostprocessors
  registerVectorPostprocessor(SamplerData);
  registerVectorPostprocessor(StochasticResults);

  // MultiApps
  registerMultiApp(SamplerMultiApp);

  // Transfers
  registerTransfer(SamplerTransfer);
  registerTransfer(SamplerPostprocessorTransfer);

  // Controls
  registerControl(SamplerReceiver);
}

// External entry point for dynamic syntax association
extern "C" void
StochasticToolsApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  StochasticToolsApp::associateSyntax(syntax, action_factory);
}
void
StochasticToolsApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
