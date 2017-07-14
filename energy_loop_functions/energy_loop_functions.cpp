#include "energy_loop_functions.h"
#include <argos3/core/simulator/simulator.h>
#include <argos3/core/utility/configuration/argos_configuration.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>
#include "/home/arsalan/buzz/src/buzz/argos/buzz_controller_footbot.h"

/****************************************/
/****************************************/

CEnergyLoopFunctions::CEnergyLoopFunctions() :
   m_vecCentroid(0.0, 0.0, 0.0) {
}

/****************************************/
/****************************************/

void CEnergyLoopFunctions::Init(TConfigurationNode& t_node) {

   try {
      TConfigurationNode& tEnergy = GetNode(t_node, "energy");
      /* Get the output file name from XML */
      GetNodeAttribute(tEnergy, "output", m_strOutput);
      /* Open the file, erasing its contents */
      m_cOutput.open(m_strOutput.c_str(), std::ios_base::trunc | std::ios_base::out);
      m_cOutput << "# clock\t" << std::endl;
   }
   catch(CARGoSException& ex) {
      THROW_ARGOSEXCEPTION_NESTED("Error parsing loop functions!", ex);
   }

}

/****************************************/
/****************************************/

void CEnergyLoopFunctions::Reset() {
   /* Close the file */
   m_cOutput.close();
   /* Open the file, erasing its contents */
   m_cOutput.open(m_strOutput.c_str(), std::ios_base::trunc | std::ios_base::out);
   m_cOutput << "# clock\t" << std::endl;

}

/****************************************/
/****************************************/

void CEnergyLoopFunctions::Destroy() {
   /* Close the file */
   m_cOutput.close();
}

/****************************************/
/****************************************/

void CEnergyLoopFunctions::PostStep() {
   
   //CSpace& cSpace = CSimulator::GetInstance().GetSpace();
   
   CSpace::TMapPerType& cFootbots = GetSpace().GetEntitiesByType("foot-bot");
    
   for(CSpace::TMapPerType::iterator it = cFootbots.begin();
        it != cFootbots.end();
        ++it) {
        
        /* Get handle to foot-bot entity and controller */
        CFootBotEntity& cSon = *any_cast<CFootBotEntity*>(it->second);
        CBuzzControllerFootBot& cController  = dynamic_cast<CBuzzControllerFootBot&>(cSon.GetControllableEntity().GetController());


        /* Get id of current robot */
        const std::string& strRobotId = cSon.GetId();

        /* Get absolute position of current robot */
        CVector3 cStart = cSon.GetEmbodiedEntity().GetOriginAnchor().Position;
        
   }
}

//UInt16 nCurrentId = FromString<UInt16>(strRobotId.substr(2));
//LOG<<"Son\t"<<nCurrentId<<"\tParent\t"<<m_nParent<<std::endl;

/****************************************/
/****************************************/

REGISTER_LOOP_FUNCTIONS(CEnergyLoopFunctions, "energy_loop_functions")
