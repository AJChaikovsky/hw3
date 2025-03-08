#include "gate.h"

NotGate::NotGate(Wire* input, Wire* output){
  m_inputs.push_back(input);
  m_output = output;
}

Event* NotGate::update() {
  //get current state of the single input
  char inState = m_inputs[0]->getState();
  char newState;
  if (inState = 'X'){
    newState = 'X';
  } else if(inState == '0') {
    newState = '1';
  } else if(inState == '1'){
    newState = '0';
  }else {
    newState = 'X'; //default to undefined
  }

  //if the output needs to change, create and return an event
  if(m_output->getState() != newState){
    //create an evet with appropriate delay
    Event* e = new Event();
    e->time = 0;
    e-> wireId = m_output->getId();
    e->state = newState;
    return e;
  }
  return nullptr;
}