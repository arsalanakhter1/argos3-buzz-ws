#ifndef ENERGY_QT_USER_FUNCTIONS_H
#define ENERGY_QT_USER_FUNCTIONS_H

#include <argos3/plugins/simulator/visualizations/qt-opengl/qtopengl_user_functions.h>
#include <argos3/plugins/robots/foot-bot/simulator/footbot_entity.h>


using namespace argos;

class CBuzzQTMainWindow;

class CEnergyLoopFunctions;

class CEnergyQTUserFunctions : public CQTOpenGLUserFunctions {

public:

   CEnergyQTUserFunctions();

   virtual ~CEnergyQTUserFunctions() {}

   virtual void Init(TConfigurationNode& t_tree);

   virtual void Destroy();

   virtual void DrawInWorld();


private :

   CEnergyLoopFunctions& m_cEnergyLF;

   CBuzzQTMainWindow* m_pcEditor;
   
};

#endif
