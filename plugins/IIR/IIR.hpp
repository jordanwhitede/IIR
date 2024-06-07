// PluginIIR.hpp
// Jordan White (jordanwhitede@gmail.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace IIR {

class IIR : public SCUnit {
public:
    IIR();

    // Destructor
    // ~IIR();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
};

} // namespace IIR
