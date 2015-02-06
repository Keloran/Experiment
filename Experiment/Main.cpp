#include <Main.hpp>

#include <NordicEngine/Logger/Logger.hpp>
#include <NordicEngine/Files/Format/Obj/Obj.hpp>
#include <NordicEngine/Render/Models/Manager.hpp>

namespace NordicArts {
    namespace Keloran {
        void handleException(std::exception_ptr oException) {
            try {
                if (oException) {
                    std::rethrow_exception(oException);
                }
            } catch (const std::exception &oEx) {
                printIt(oEx.what());
            }
        }

        int Main() {
            std::string cName = "Experiments";

            // Logger
            NordicEngine::Logger  oLogger(cName);
            NordicEngine::Logger *pLogger = &oLogger;
        
            try {
                // Model Testing
                std::vector<glm::vec3> vVertex;
                std::vector<glm::vec2> vUV;
                std::vector<glm::vec3> vNormal;

                NordicEngine::Files::Obj oObj("Files/dragon.obj");
                oObj.loadModel(vVertex, vUV, vNormal);

                pLogger->log(vVertex.size());
                pLogger->log(vUV.size());
                pLogger->log(vNormal.size());

                NordicEngine::Render::Models::Manager  oManager(pLogger);
                NordicEngine::Render::Models::Manager *pModelManager = &oManager;

                std::vector<glm::vec3> vVerticies;

                glm::vec3 vVert;
                vVert.x = -1.0f;
                vVert.y = -1.0f;
                vVert.z =  0.0f;
                vVerticies.push_back(vVert);

                vVert.x =  1.0f;
                vVert.y = -1.0f;
                vVert.z =  0.0f;
                vVerticies.push_back(vVert);

                vVert.x = 0.0f;
                vVert.y = 1.0f;
                vVert.z = 0.0f;           
                vVerticies.push_back(vVert);

                pModelManager->addModel("triangle", vVerticies, "GameFiles/Shaders/Shader.vertex", "GameFiles/Shaders/Shader.fragment");
                pModelManager->getModel("triangle");
                
            } catch (std::exception &oException) {
                throw NordicEngine::Exception(oException.what());
            } catch (NordicEngine::Exception &oException) {
                printIt(oException.what());
            } catch ( ... ) {
                handleException(std::current_exception());
            }

            return EXIT_SUCCESS;
        }
    };
};

int main() {
    return NordicArts::Keloran::Main();
}
