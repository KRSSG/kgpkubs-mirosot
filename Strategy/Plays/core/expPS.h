#ifndef EXP_PS_H
#define EXP_PS_H

#include "ps.h"
#include "play.hpp"

namespace Strategy
{
  class BeliefState;
  
  class ExpPS : public PS
  {
  public:
    ExpPS(const BeliefState* state);
    
    ~ExpPS();

    void updateWeights(Play::Result termResult) const;
  }; // class ExpPS
} // namespace Strategy

#endif // EXP_PS_H
