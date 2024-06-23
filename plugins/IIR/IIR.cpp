// PluginIIR.cpp
// Jordan White (jordanwhitede@gmail.com)

#include "SC_PlugIn.hpp"
#include "IIR.hpp"

static InterfaceTable* ft;

namespace IIR {

IIR::IIR() {
    mCalcFunc = make_calc_function<IIR, &IIR::next>();
    prevSample = 0.0;
    next(1);
}

void IIR::next(int nSamples) {

    // args
    const float* input = in(0); 
    const float a1 = in0(1);
    const float b0 = in0(2);
    const float b1 = in0(3);

    // Output buffer
    float* output = out(0);

    // IIR function - signal is delayed by one sample. sig * b0 and delayed sig * b1 are summed to output. delayed sig * a0 is added to input.
    // so I need a buffer, a delayed sig
    for (int i = 0; i < nSamples; ++i) {
        float filtered = ((input[i] + (prevSample * -a1)) * b0) + (prevSample * b1);
        output[i] = zapgremlins(filtered);
        prevSample = output[i];
    }
}

} // namespace IIR

PluginLoad(IIRUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<IIR::IIR>(ft, "IIR", false);
}
