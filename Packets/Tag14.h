// Public-Subkey Packet
#include "Tag6.h"

#ifndef __TAG14__
#define __TAG14__
class Tag14 : public Tag6{
    public:
        Tag14();
        Tag14(std::string & data);
        Tag14 * clone();
};
#endif
