#ifndef NordicArts_Keloran_Experiments_Main_H
#define NordicArts_Keloran_Experiments_Main_H

#include <Includes.hpp>

#include <NordicEngine/Engine.hpp>

namespace NordicArts {
    namespace Keloran {
        void handleException(std::exception_ptr oException);

        int Main();
    };
};

#endif
