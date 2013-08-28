// Key Flags
#include "subpacket.h"

#ifndef __TAG2SUB27__
#define __TAG2SUB27__
class Tag2Sub27 : public Subpacket{
    private:
        char flags;

    public:
        Tag2Sub27();
        Tag2Sub27(std::string & data);
        void read(std::string & data);
        std::string show();
        std::string raw();

        Tag2Sub27 * clone();

        char get_flags();

        void set_flags(char f);
};
#endif
