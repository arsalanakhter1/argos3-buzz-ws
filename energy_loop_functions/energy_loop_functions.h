#ifndef ENERGY_LOOP_FUNCTIONS_H
#define ENERGY_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>


using namespace argos;

class CEnergyLoopFunctions : public CLoopFunctions {


public:

   CEnergyLoopFunctions();

   virtual ~CEnergyLoopFunctions() {}

   virtual void Init(TConfigurationNode& t_node);

   virtual void Reset();

   virtual void Destroy();

   virtual void PostStep();

private:

   std::string m_strOutput;
   std::ofstream m_cOutput;

   CVector3 m_vecCentroid;          // Don't know why it is here

};

#endif
