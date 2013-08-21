#pragma once
#ifndef PARAMLOADERS_H
#define PARAMLOADERS_H

namespace Strategy
{
  class ParamLoaders
  {
  private:
    void skill_gotopoint();
    
  public:
    ParamLoaders();
    ~ParamLoaders();
    void load_all_params();
  };
}

#endif // PARAMLOADERS_H
