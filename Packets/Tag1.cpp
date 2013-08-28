#include "Tag1.h"
Tag1::Tag1(){
    tag = 1;
    version = 3;
}

Tag1::Tag1(std::string & data){
    tag = 1;
    version = 3;
    read(data);
}

void Tag1::read(std::string & data){
    size = data.size();
    version = data[0];
    keyid = data.substr(1, 8);
    pka = data[9];
    data = data.substr(10, data.size() - 10);
    while (data.size())
        mpi.push_back(read_MPI(data));
}

std::string Tag1::show(){
    std::stringstream out;
    out << "    Version: " << (unsigned int) version << "\n"
        << "    KeyID: " << hexlify(keyid) << "\n"
        << "    Public Key Algorithm: " << Public_Key_Algorithms.at(pka) << " (pka " << (unsigned int) pka << ")\n";
    if (pka < 4){           // RSA
        out << "    RSA m**e mod n (" << mpi[0].bits() << " bits): " << mpi[0].str(16) << "\n";
    }
    else if (pka == 16){
        out << "    Elgamal g**k mod p (" << mpi[0].bits() << " bits): " << mpi[0].str(16) << "\n"
            << "    Elgamal m * y**k mod p (" << mpi[1].bits() << " bits): " << mpi[1].str(16) << "\n";
    }
    return out.str();
}

std::string Tag1::raw(){
    std::string out = "\x03" + keyid + std::string(1, pka);
    for(unsigned int x = 0; x < mpi.size(); x++){
        out += write_MPI(mpi[x]);
    }
    return out;
}

Tag1 * Tag1::clone(){
    return new Tag1(*this);
}

std::string Tag1::get_keyid(){
    return keyid;
}

uint8_t Tag1::get_pka(){
    return pka;
}

std::vector <integer> Tag1::get_mpi(){
    return mpi;
}

void Tag1::set_keyid(std::string k){
    if (k.size() != 8){
        std::cerr << "Error: Key ID must be 8 octets" << std::endl;
        exit(1);
    }
    keyid = k;
}

void Tag1::set_pka(uint8_t p){
    pka = p;
}

void Tag1::set_mpi(std::vector <integer> m){
    mpi = m;
}
