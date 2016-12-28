/*
 * This is the network ADT - it is class that holds information and functions
 * relating to the Neural Network created by the NNDL file.
 */
#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <iostream>

#include "layer.h"
#include "synapse.h"



class Network
{
public:
    Network(std::vector<Layer *> *layers, std::vector<Synapse *> *connections);
    ~Network();

    friend std::ostream& operator<<(std::ostream &outstream, const Network &nw);

    /*
     * Loads the given vector of Signals (which must of size equal to
     * to the output layer of the network) into the output layer
     * and triggers each Synapse backwards.
     *
     * The result is a vector of Signals coming from the input layer.
     */
    std::vector<Signal> fire_backward(std::vector<Signal> input);

    /*
     * This is the standard mechanism for computing a result from the network.
     * The input must be of size equal to the number of input neurons.
     */
    std::vector<Signal> fire_forward(std::vector<Signal> input);


private:
    std::vector<Layer *> *layers;
    ConnectionMap connection_map;

    std::tuple<Signal, std::vector<Neuron *> *>& fire_input_layer(
            std::tuple<Signal, std::vector<Neuron *> *> &tuples,
            std::set<Neuron *> &already_fired, bool forward);

    std::tuple<Signal, std::vector<Neuron *> *> fire_neuron(
            Neuron *n_i, const Signal &s_i,
            std::set<Neuron *> &already_fired, bool forward);

    std::tuple<Signal, std::vector<Neuron *> *>& fire_neurons_in_list(
            std::tuple<Signal, std::vector<Neuron *> *> &tuples,
            std::set<Neuron *> &already_fired, bool forward,
            std::vector<std::tuple<Neuron *, Signal>> &output_neurons);

    Layer* get_input_layer();
    Layer* get_output_layer();

    bool keep_going(std::vector<std::tuple<Signal, std::vector<Neuron *> *>> &t);

    std::vector<Signal>& map_to_output(std::vector<std::tuple<
            Neuron *, Signal>> &output_neurons, std::vector<Signal> &output);

    bool neuron_is_output_neuron(const Neuron *n) const;
};



#endif //header guard



