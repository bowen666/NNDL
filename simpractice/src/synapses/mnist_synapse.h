/*
 * Simple Synapse for MNIST example.
 */

#ifndef __SIMPLE_SYNAPSE_H__
#define __SIMPLE_SYNAPSE_H__

#include <iostream>

#include "synapse.h"

#include NEURON_HEADER

class SimpleSynapse
    : public Synapse
{
public:
    SimpleSynapse();
    SimpleSynapse(const NEURON *from, const NEURON *to, const Signal &w);
    ~SimpleSynapse();

    friend std::ostream& operator<<(std::ostream &outstream, const Synapse &s);

    Signal fire_backward(float t, const Signal &incoming);
    Signal fire_forward(float t, const Signal &incoming);
};





#endif //header guard