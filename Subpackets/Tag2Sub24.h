// Preferred Key Server
#include "subpacket.h"

#ifndef __TAG2SUB24__
#define __TAG2SUB24__
class Tag2Sub24 : public Subpacket{
    private:
        std::string pks;

    public:
        Tag2Sub24();
        Tag2Sub24(std::string & data);
        void read(std::string & data);
        std::string show();
        std::string raw();

        Tag2Sub24 * clone();

        std::string get_pks();

        void set_pks(std::string p);
};
#endif
