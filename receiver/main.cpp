#include "receiver.hpp"

using namespace std;

int main(int argc, char* argv[]){
    string port = argv[1];
    string destPort = argv[2];
    Receiver receiver(port, destPort);   //ipadress, toRouter, fromRouter
    receiver.run();
    receiver.reconstructFile();
}