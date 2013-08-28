#include <cstdlib>
#include <iostream>
#include <vector>

#include "../common/includes.h"
#include "../consts.h"
#include "../mpi.h"
#include "../pgptime.h"
#include "../s2k.h"

#ifndef __PACKET__
#define __PACKET__

class Packet{
    protected:
        uint8_t tag = 0;
        uint8_t version = 0;
        bool format = true; // OLD or NEW; only used when "show"ing. "write" will always write new version
        unsigned int size = 0;

        // returns packet data with old format packet length
        std::string write_old_length(std::string data);
        // returns packet data with new format packet length
        std::string write_new_length(std::string data);

    public:
        virtual ~Packet();
        virtual void read(std::string & data) = 0;
        virtual std::string show() = 0;
        virtual std::string raw() = 0;
        std::string write(bool header = true);

        virtual Packet * clone() = 0;

        // Accessors
        uint8_t get_tag();
        bool get_format();
        unsigned int get_version();
        unsigned int get_size();

        // Modifiers
        void set_tag(uint8_t t);
        void set_format(bool f);
        void set_version(unsigned int v);
        void set_size(unsigned int s);
};

// For Tags 5, 6, 7, and 14
class Key : public Packet{};

// For Tags 13 and 17
class ID : public Packet{};
#endif
