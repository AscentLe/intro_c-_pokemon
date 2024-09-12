#ifndef STATE_HPP  
#define STATE_HPP
#include <iostream>
#include <typeinfo>
class Context;
class State {
protected:
    Context *context_;
public:
    virtual ~State();
    
    void set_context(Context *context);
    virtual void handle()=0;
    virtual std::string getName() const = 0;
};
#endif