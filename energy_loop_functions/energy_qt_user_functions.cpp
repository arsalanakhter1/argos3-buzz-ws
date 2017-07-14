#include "energy_qt_user_functions.h"
#include "energy_loop_functions.h"

#include "/home/arsalan/buzz/src/buzz/argos/buzz_qt_main_window.h"
#include <argos3/plugins/simulator/visualizations/qt-opengl/qtopengl_main_window.h>


/****************************************/
/****************************************/

CEnergyQTUserFunctions::CEnergyQTUserFunctions() :
   m_cEnergyLF(dynamic_cast<CEnergyLoopFunctions&>(CSimulator::GetInstance().GetLoopFunctions())) {
}


/****************************************/
/****************************************/

void CEnergyQTUserFunctions::Init(TConfigurationNode& t_tree) {
   m_pcEditor = new CBuzzQTMainWindow(&GetMainWindow());
   m_pcEditor->show();
}

/****************************************/
/****************************************/

void CEnergyQTUserFunctions::Destroy() {
   delete m_pcEditor;
}
/****************************************/
/****************************************/

void CEnergyQTUserFunctions::DrawInWorld() {

}


/****************************************/
/****************************************/


REGISTER_QTOPENGL_USER_FUNCTIONS(CEnergyQTUserFunctions, "energy_qt_user_functions")
