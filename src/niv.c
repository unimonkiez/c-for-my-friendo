#include "niv.h"


static int get_max() {
    return MAX;
}

int get_shlong_size() {
    int s = 1;
    if (s > get_max())   {
        return get_max();
    }
    
    return s;
}



enum Privates get_privates() {
    enum Privates privates = get_shlong_size() > 0 ? Shlong : (get_shlong_size() < 0 ? Cat : NonBinary);
    return privates;
    // if (get_shlong_size() > 0) {
    //     return Shlong;
    // }
    // return Cat;
}